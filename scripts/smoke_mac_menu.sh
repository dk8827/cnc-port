#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="$ROOT_DIR/build"
SECONDS_TO_WAIT=60
SCREENSHOT=""
LOG_FILE=""
DO_BUILD=1
DO_ASSETS=1
KEEP_RUNNING=0

usage() {
  cat <<'USAGE'
Usage: scripts/smoke_mac_menu.sh [options]

Build and launch the macOS Command & Conquer port from the repo root long enough to capture the title/menu.

Options:
  --seconds N            Seconds to wait before screenshot (default: 60)
  --screenshot PATH      Screenshot output path
  --log PATH             Log output path (default: build/last_smoke_menu.log)
  --no-build             Reuse the existing build artifact
  --no-assets            Do not check local assets before running
  --build-dir DIR        CMake build directory (default: build)
  --keep-running         Leave the game running after the screenshot
  -h, --help             Show this help
USAGE
}

absolute_dir() {
  mkdir -p "$1"
  (cd "$1" && pwd -P)
}

absolute_file() {
  local path="$1"
  local dir
  dir="$(dirname "$path")"
  mkdir -p "$dir"
  dir="$(cd "$dir" && pwd -P)"
  printf '%s/%s\n' "$dir" "$(basename "$path")"
}

cnc_window_id() {
  if ! command -v swift >/dev/null 2>&1; then
    return
  fi

  swift - 2>/dev/null <<'SWIFT'
import CoreGraphics
import Foundation

let options = CGWindowListOption(arrayLiteral: .optionOnScreenOnly, .excludeDesktopElements)
let windows = CGWindowListCopyWindowInfo(options, kCGNullWindowID) as? [[String: Any]] ?? []

for window in windows {
    let owner = (window[kCGWindowOwnerName as String] as? String ?? "").lowercased()
    let name = (window[kCGWindowName as String] as? String ?? "").lowercased()
    if owner == "cnc_mac" || name.contains("command & conquer") {
        if let number = window[kCGWindowNumber as String] as? Int {
            print(number)
            exit(0)
        }
    }
}
SWIFT
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --seconds)
      [[ $# -ge 2 ]] || { echo "--seconds requires a value" >&2; exit 2; }
      SECONDS_TO_WAIT="$2"
      shift 2
      ;;
    --screenshot)
      [[ $# -ge 2 ]] || { echo "--screenshot requires a value" >&2; exit 2; }
      SCREENSHOT="$2"
      shift 2
      ;;
    --log)
      [[ $# -ge 2 ]] || { echo "--log requires a value" >&2; exit 2; }
      LOG_FILE="$2"
      shift 2
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
    --keep-running)
      KEEP_RUNNING=1
      shift
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      echo "Unknown option: $1" >&2
      usage >&2
      exit 2
      ;;
  esac
done

case "$SECONDS_TO_WAIT" in
  ''|*[!0-9]*)
    echo "--seconds must be a positive integer" >&2
    exit 2
    ;;
esac

if [[ "$SECONDS_TO_WAIT" -lt 1 ]]; then
  echo "--seconds must be a positive integer" >&2
  exit 2
fi

BUILD_DIR="$(absolute_dir "$BUILD_DIR")"
if [[ -z "$SCREENSHOT" ]]; then
  SCREENSHOT="$BUILD_DIR/cnc_menu_smoke.png"
fi
SCREENSHOT="$(absolute_file "$SCREENSHOT")"
if [[ -z "$LOG_FILE" ]]; then
  LOG_FILE="$BUILD_DIR/last_smoke_menu.log"
fi
LOG_FILE="$(absolute_file "$LOG_FILE")"

prepare_args=(--prepare-only --build-dir "$BUILD_DIR")
if [[ "$DO_BUILD" -eq 0 ]]; then
  prepare_args+=(--no-build)
fi
if [[ "$DO_ASSETS" -eq 0 ]]; then
  prepare_args+=(--no-assets)
fi

"$ROOT_DIR/scripts/run_mac_dev.sh" "${prepare_args[@]}"

pkill -TERM -x cnc_mac 2>/dev/null || true
pkill -9 -x UserNotificationCenter 2>/dev/null || true
pkill -9 -x CoreServicesUIAgent 2>/dev/null || true

cd "$ROOT_DIR"
"$BUILD_DIR/cnc_mac" > "$LOG_FILE" 2>&1 &
pid=$!

sleep "$SECONDS_TO_WAIT"
window_id="$(cnc_window_id | head -n 1)"
if [[ -n "$window_id" ]]; then
  screencapture -x -l "$window_id" "$SCREENSHOT"
else
  screencapture -x "$SCREENSHOT"
fi

if kill -0 "$pid" 2>/dev/null; then
  echo "cnc_mac still running after ${SECONDS_TO_WAIT}s"
  if [[ "$KEEP_RUNNING" -eq 0 ]]; then
    kill -TERM "$pid" 2>/dev/null || true
  fi
else
  wait "$pid"
  status=$?
  echo "cnc_mac exited before screenshot with status $status" >&2
  exit "$status"
fi

echo "Screenshot: $SCREENSHOT"
if [[ -n "$window_id" ]]; then
  echo "Window ID: $window_id"
fi
echo "Log: $LOG_FILE"
