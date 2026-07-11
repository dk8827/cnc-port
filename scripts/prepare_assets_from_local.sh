#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ASSET_DIR="$ROOT_DIR/assets/cnc"
GDI_SRC=""
NOD_SRC=""

usage() {
  cat <<'USAGE'
Usage: scripts/prepare_assets_from_local.sh --gdi DIR --nod DIR

Copy locally provided Command & Conquer disc contents into the ignored assets tree.

Required:
  --gdi DIR         Mounted or extracted GDI disc directory
  --nod DIR         Mounted or extracted Nod disc directory

Options:
  -h, --help        Show this help
USAGE
}

absolute_dir() {
  local path="$1"
  [[ -d "$path" ]] || { echo "Not a directory: $path" >&2; exit 2; }
  (cd "$path" && pwd -P)
}

validate_disc_root() {
  local name="$1"
  local source_dir="$2"

  if [[ ! -d "$source_dir/INSTALL" ]]; then
    echo "$name source does not look like a Command & Conquer disc root: missing INSTALL/" >&2
    exit 2
  fi

  if ! find "$source_dir" -maxdepth 3 -type f \( -iname '*.mix' -o -iname 'CONQUER.INI' \) -print -quit | grep -q .; then
    echo "$name source does not contain expected Command & Conquer data files" >&2
    exit 2
  fi
}

copy_disc() {
  local name="$1"
  local source_dir="$2"
  local target_dir="$ASSET_DIR/$name"

  validate_disc_root "$name" "$source_dir"
  mkdir -p "$target_dir"
  rsync -a --delete "$source_dir/" "$target_dir/"
  echo "Prepared $name assets in $target_dir"
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --gdi)
      [[ $# -ge 2 ]] || { echo "--gdi requires a directory" >&2; exit 2; }
      GDI_SRC="$(absolute_dir "$2")"
      shift 2
      ;;
    --nod)
      [[ $# -ge 2 ]] || { echo "--nod requires a directory" >&2; exit 2; }
      NOD_SRC="$(absolute_dir "$2")"
      shift 2
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      echo "Unknown argument: $1" >&2
      usage >&2
      exit 2
      ;;
  esac
done

if [[ -z "$GDI_SRC" || -z "$NOD_SRC" ]]; then
  usage >&2
  exit 2
fi

copy_disc gdi "$GDI_SRC"
copy_disc nod "$NOD_SRC"
echo "Assets are ready under $ASSET_DIR"
