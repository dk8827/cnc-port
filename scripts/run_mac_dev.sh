#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="$ROOT_DIR/build"
TARGET_NAME="cnc_mac"
DO_BUILD=1
DO_ASSETS=1
DO_RUN=1
GAME_ARGS=()

usage() {
  cat <<'USAGE'
Usage: scripts/run_mac_dev.sh [options] [-- game-args...]

Build and run the macOS Command & Conquer port from the repo root.

Options:
  --prepare-only          Build, codesign, and check assets, but do not launch the game
  --no-build              Reuse the existing build artifact
  --no-assets             Do not check local assets before running
  --build-dir DIR         CMake build directory (default: build)
  -h, --help              Show this help
USAGE
}

absolute_dir() {
  mkdir -p "$1"
  (cd "$1" && pwd -P)
}

configure_if_needed() {
  if [[ -f "$BUILD_DIR/CMakeCache.txt" ]]; then
    return
  fi

  if command -v ninja >/dev/null 2>&1; then
    cmake -S "$ROOT_DIR" -B "$BUILD_DIR" -G Ninja
  else
    cmake -S "$ROOT_DIR" -B "$BUILD_DIR"
  fi
}

build_target() {
  configure_if_needed
  cmake --build "$BUILD_DIR" --target "$TARGET_NAME"
}

verify_assets() {
  local source_dir="$ROOT_DIR/assets/cnc"

  if [[ ! -f "$source_dir/gdi/INSTALL/CONQUER.INI" || ! -d "$source_dir/nod" ]]; then
    echo "Missing base assets under $source_dir" >&2
    echo "Run scripts/prepare_assets_from_local.sh --gdi DIR --nod DIR first." >&2
    exit 1
  fi
}

codesign_binary() {
  local built_binary="$BUILD_DIR/$TARGET_NAME"

  if [[ ! -x "$built_binary" ]]; then
    echo "Missing executable $built_binary" >&2
    echo "Run without --no-build first." >&2
    exit 1
  fi

  xattr -c "$built_binary" 2>/dev/null || true
  codesign --force --sign - "$built_binary" >/dev/null
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --prepare-only)
      DO_RUN=0
      shift
      ;;
    --no-build)
      DO_BUILD=0
      shift
      ;;
    --no-assets)
      DO_ASSETS=0
      shift
      ;;
    --build-dir)
      [[ $# -ge 2 ]] || { echo "--build-dir requires a value" >&2; exit 2; }
      BUILD_DIR="$2"
      shift 2
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    --)
      shift
      GAME_ARGS=("$@")
      break
      ;;
    *)
      GAME_ARGS+=("$1")
      shift
      ;;
  esac
done

BUILD_DIR="$(absolute_dir "$BUILD_DIR")"

if [[ "$DO_BUILD" -eq 1 ]]; then
  build_target
fi

if [[ "$DO_ASSETS" -eq 1 ]]; then
  verify_assets
fi

codesign_binary

echo "Prepared $TARGET_NAME at $BUILD_DIR/$TARGET_NAME"

if [[ "$DO_RUN" -eq 1 ]]; then
  cd "$ROOT_DIR"
  if [[ "${#GAME_ARGS[@]}" -gt 0 ]]; then
    exec "$BUILD_DIR/$TARGET_NAME" "${GAME_ARGS[@]}"
  else
    exec "$BUILD_DIR/$TARGET_NAME"
  fi
fi
