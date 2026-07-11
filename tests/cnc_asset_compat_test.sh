#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEFINES_HEADER="$ROOT_DIR/CODE/DEFINES.H"
CONQUER_HEADER="$ROOT_DIR/CODE/CONQUER.H"
CCLOCAL_MIX="$ROOT_DIR/assets/cnc/gdi/INSTALL/CCLOCAL.MIX"

entry_count="$({ perl -0777 -e '
  my $file = <>;
  my ($count) = unpack("s<", substr($file, 0, 2));
  my $data_base = 6 + 12 * $count;
  for my $index (0 .. $count - 1) {
    my ($offset, $size) = unpack("VV", substr($file, 10 + 12 * $index, 8));
    my $data = substr($file, $data_base + $offset, $size);
    next if length($data) < 2 || index($data, "Start New Game\0") < 0;
    my $first_offset = unpack("v", substr($data, 0, 2));
    next if $first_offset == 0 || $first_offset % 2 || $first_offset > length($data);
    print $first_offset / 2;
    exit 0;
  }
  exit 1;
' "$CCLOCAL_MIX"; } )"

bonus_id="$(awk '$2 == "TXT_BONUS_MISSIONS" { print $3; exit }' "$CONQUER_HEADER")"

if grep -Eq '^[[:space:]]*#define[[:space:]]+BONUS_MISSIONS([[:space:]]|$)' "$DEFINES_HEADER" &&
   (( entry_count <= bonus_id )); then
  echo "BONUS_MISSIONS requires text ID $bonus_id, but bundled CONQUER.ENG has IDs 0-$((entry_count - 1))." >&2
  exit 1
fi

echo "C&C source features match the bundled language table ($entry_count entries)."
