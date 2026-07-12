#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

fail() {
  echo "FAIL: $*" >&2
  exit 1
}

assert_executable() {
  local path="$1"
  [[ -x "$ROOT_DIR/$path" ]] || fail "$path is not executable"
}

assert_help_contains() {
  local script="$1"
  local expected="$2"
  "$ROOT_DIR/$script" --help | grep -F -- "$expected" >/dev/null || fail "$script --help missing $expected"
}

assert_help_not_contains() {
  local script="$1"
  local unexpected="$2"
  if "$ROOT_DIR/$script" --help | grep -F -- "$unexpected" >/dev/null; then
    fail "$script --help should not contain $unexpected"
  fi
}

assert_file_contains() {
  local path="$1"
  local expected="$2"
  grep -F -- "$expected" "$ROOT_DIR/$path" >/dev/null || fail "$path missing $expected"
}

assert_file_not_contains() {
  local path="$1"
  local unexpected="$2"
  if grep -F -- "$unexpected" "$ROOT_DIR/$path" >/dev/null; then
    fail "$path should not contain $unexpected"
  fi
}

assert_executable scripts/run_mac_dev.sh
assert_executable scripts/prepare_assets_from_local.sh
assert_executable scripts/smoke_mac_menu.sh
assert_executable scripts/build_android_debug.sh
assert_executable scripts/run_android_debug.sh
assert_executable scripts/build_ios_debug.sh
assert_executable scripts/run_ios_simulator.sh

assert_file_contains .github/workflows/macos-build.yml "--target cnc_mac"

legacy_stage_arg="--staging-""dir"
legacy_tmp_dir="/tmp/redalert_""mac_run"
legacy_stage_var="STAGING_""DIR"
legacy_stage_assets="stage_""assets"
legacy_stage_binary="stage_""binary"
legacy_staging_phrase="staging ""directory"
legacy_tmp_run_phrase="stage assets into a ""temporary run directory"

assert_help_contains scripts/run_mac_dev.sh "--prepare-only"
assert_help_contains scripts/run_mac_dev.sh "--no-build"
assert_help_contains scripts/run_mac_dev.sh "repo root"
assert_help_not_contains scripts/run_mac_dev.sh "$legacy_stage_arg"
assert_help_contains scripts/prepare_assets_from_local.sh "--gdi"
assert_help_contains scripts/prepare_assets_from_local.sh "--nod"
assert_help_contains scripts/smoke_mac_menu.sh "--seconds"
assert_help_contains scripts/smoke_mac_menu.sh "--screenshot"
assert_help_not_contains scripts/smoke_mac_menu.sh "$legacy_stage_arg"
assert_help_contains scripts/build_android_debug.sh "assembleDebug"
assert_help_contains scripts/run_android_debug.sh "adb"
assert_help_contains scripts/run_android_debug.sh "--fresh-install"
assert_help_contains scripts/build_ios_debug.sh "iphonesimulator"
assert_help_contains scripts/build_ios_debug.sh "iphoneos"
assert_help_contains scripts/build_ios_debug.sh "CNC_IOS_DEVELOPMENT_TEAM"
assert_help_contains scripts/run_ios_simulator.sh "simctl"
assert_help_contains scripts/run_ios_simulator.sh "--no-build"
assert_help_contains scripts/run_ios_simulator.sh "--device"
assert_help_contains scripts/run_ios_simulator.sh "--no-landscape"

assert_file_not_contains scripts/run_mac_dev.sh "$legacy_tmp_dir"
assert_file_not_contains scripts/run_mac_dev.sh "$legacy_stage_var"
assert_file_not_contains scripts/run_mac_dev.sh "$legacy_stage_assets"
assert_file_not_contains scripts/run_mac_dev.sh "$legacy_stage_binary"
assert_file_not_contains scripts/run_mac_dev.sh 'rsync -a --delete "$source_dir/" "$target_dir/"'
assert_file_contains scripts/run_mac_dev.sh 'cd "$ROOT_DIR"'
assert_file_contains scripts/run_mac_dev.sh 'exec "$BUILD_DIR/$TARGET_NAME"'

assert_file_contains android/settings.gradle.kts "cnc-android"
assert_file_contains android/build.gradle.kts "com.android.application"
assert_file_contains android/app/build.gradle.kts "assembleDebug"
assert_file_contains android/app/build.gradle.kts "28.2.13676358"
assert_file_contains android/app/CMakeLists.txt "cnc_android"
assert_file_contains android/app/CMakeLists.txt "RA_MOBILE_TOUCH"
assert_file_contains android/app/src/main/AndroidManifest.xml "landscape"
assert_file_contains android/app/src/main/AndroidManifest.xml "appCategory=\"game\""
android_activity="android/app/src/main/java/com/cncport/cnc/CncActivity.java"
assert_file_contains "$android_activity" "SDLActivity"
assert_file_contains "$android_activity" "extractBundledAssets"
assert_file_not_contains "$android_activity" "installOverlayControls"
assert_file_not_contains "$android_activity" "addKeyButton"
assert_file_not_contains "$android_activity" "addContentView(controls"
assert_file_not_contains "$android_activity" "LinearLayout.VERTICAL"
assert_file_not_contains "$android_activity" "Gravity.START | Gravity.CENTER_VERTICAL"
assert_file_contains "$android_activity" "KEYCODE_BACK"
assert_file_contains "$android_activity" "KEYCODE_ESCAPE"
assert_file_contains "$android_activity" "onBackPressed"
assert_file_contains "$android_activity" "OnBackInvokedDispatcher"
assert_file_contains "$android_activity" "registerOnBackInvokedCallback"
assert_file_contains "$android_activity" "WindowInsetsController.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE"
assert_file_contains "$android_activity" "WindowInsets.Type.statusBars() | WindowInsets.Type.navigationBars()"
assert_file_contains "$android_activity" "SYSTEM_UI_FLAG_IMMERSIVE_STICKY"
assert_file_contains PORT/ANDROID/src/android_main.cpp "SDL_main"
assert_file_contains PORT/IOS/src/ios_main.cpp "SDL_main"
assert_file_contains PORT/IOS/src/ios_main.cpp "SDL_GetPrefPath"
assert_file_contains PORT/IOS/src/ios_main.cpp "SDL_GetBasePath"
assert_file_contains PORT/IOS/src/ios_main.cpp "copy_directory_recursive"
assert_file_contains PORT/IOS/src/ios_main.cpp "cnc-root"
assert_file_contains PORT/IOS/src/ios_app_delegate.m "CncIOSDelegate"
assert_file_contains PORT/IOS/src/ios_app_delegate.m "UIInterfaceOrientationMaskLandscape"
assert_file_contains PORT/IOS/src/ios_app_delegate.m "getAppDelegateClassName"
assert_file_contains PORT/IOS/src/ios_app_delegate.m "class_replaceMethod"
assert_file_contains PORT/IOS/src/ios_app_delegate.m "UIWindowSceneGeometryPreferencesIOS"
assert_file_contains PORT/IOS/src/ios_app_delegate.m "requestGeometryUpdateWithPreferences"
assert_file_contains ios/CMakeLists.txt "cnc_ios"
assert_file_contains ios/CMakeLists.txt "MACOSX_BUNDLE"
assert_file_contains ios/CMakeLists.txt "ios_app_delegate.m"
assert_file_contains ios/CMakeLists.txt "SDL2::SDL2main"
assert_file_contains ios/CMakeLists.txt "RA_IOS"
assert_file_contains ios/CMakeLists.txt "RA_MOBILE_TOUCH"
assert_file_contains ios/CMakeLists.txt "copy_directory"
assert_file_contains ios/Info.plist.in "UIApplicationSupportsIndirectInputEvents"
assert_file_contains ios/Info.plist.in "UIInterfaceOrientationLandscapeLeft"
assert_file_contains ios/Info.plist.in "UIInterfaceOrientationLandscapeRight"
assert_file_contains scripts/build_ios_debug.sh 'SDL_VERSION="2.32.10"'
assert_file_contains scripts/build_ios_debug.sh "-DCMAKE_SYSTEM_NAME=iOS"
assert_file_contains scripts/build_ios_debug.sh "iphonesimulator"
assert_file_contains scripts/build_ios_debug.sh "iphoneos"
assert_file_contains scripts/build_ios_debug.sh "CODE_SIGNING_ALLOWED=NO"
assert_file_contains scripts/build_ios_debug.sh "ensure_xcode_developer_dir"
assert_file_contains scripts/build_ios_debug.sh "DEVELOPER_DIR"
perl -0ne 'exit(/configure_project\(\)[\s\S]*local cmake_args=\([\s\S]*if \(\(\$\{#CMAKE_ARGS\[@\]\}\)\); then[\s\S]*cmake_args\+=\("\$\{CMAKE_ARGS\[@\]\}"\)[\s\S]*"\$\{cmake_args\[@\]\}"/s ? 0 : 1)' "$ROOT_DIR/scripts/build_ios_debug.sh" \
  || fail "iOS build script must avoid expanding an empty CMAKE_ARGS array under macOS bash nounset"
assert_file_contains scripts/run_ios_simulator.sh "bootstatus"
assert_file_contains scripts/run_ios_simulator.sh 'install "$SIMULATOR_UDID"'
assert_file_contains scripts/run_ios_simulator.sh 'launch "$SIMULATOR_UDID"'
assert_file_contains scripts/run_ios_simulator.sh "CurrentDeviceUDID"
assert_file_contains scripts/run_ios_simulator.sh "Landscape Right"
assert_file_contains scripts/run_ios_simulator.sh "prefer iPads"
assert_file_contains scripts/run_ios_simulator.sh "ensure_xcode_developer_dir"
assert_file_contains scripts/run_ios_simulator.sh "DEVELOPER_DIR"
perl -0ne 'exit(/run_build\(\)[\s\S]*local build_args=\([\s\S]*if \(\(\$\{#BUILD_ARGS\[@\]\}\)\); then[\s\S]*build_args\+=\("\$\{BUILD_ARGS\[@\]\}"\)[\s\S]*"\$\{build_args\[@\]\}"/s ? 0 : 1)' "$ROOT_DIR/scripts/run_ios_simulator.sh" \
  || fail "iOS simulator script must avoid expanding an empty BUILD_ARGS array under macOS bash nounset"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "SDL_FINGERDOWN"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "SDL_MULTIGESTURE"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "MobilePan_IgnoreMultiGestureCenter"
assert_file_not_contains PORT/MAC/src/mac_sdl_runtime.cpp "mobile_emit_pan(event.mgesture.x, event.mgesture.y)"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "RA_MOBILE_TOUCH"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "MobileTouchGesture"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "MobilePointerDragCandidate"
assert_file_not_contains PORT/MAC/src/mac_sdl_runtime.cpp "SDL_CreateRenderer(MacWindow, -1, SDL_RENDERER_SOFTWARE);"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "SDL_RENDERER_ACCELERATED"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "mobile_idle_delay"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "SDL_Delay(1)"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "SDL_HINT_IOS_HIDE_HOME_INDICATOR"
assert_file_contains PORT/MAC/src/mac_sdl_runtime.cpp "SDL_HINT_ORIENTATIONS"
assert_file_not_contains PORT/MAC/src/mac_sdl_runtime.cpp "RA_PERF"
assert_file_not_contains PORT/MAC/src/mac_sdl_runtime.cpp "AndroidTouchGesture"
assert_file_not_contains PORT/MAC/src/mac_sdl_runtime.cpp "#if defined(__ANDROID__)"
assert_file_contains CODE/DISPLAY.CPP "RA_MOBILE_TOUCH"
perl -0ne 'exit(/void DisplayClass::Mouse_Left_Release\([^\)]*\)[\s\S]*MobileRubberBand_ShouldCommitCandidateOnRelease[\s\S]*if \(IsRubberBand \|\| mobile_fast_rubber_band\)/s ? 0 : 1)' "$ROOT_DIR/CODE/DISPLAY.CPP" \
  || fail "mobile touch fast rubber-band fallback must be in Mouse_Left_Release"
assert_file_contains CODE/DISPLAY.CPP "MacSDL_ConsumeMobilePointerDrag"
assert_file_not_contains CODE/DISPLAY.CPP "RA_TOUCH_"
assert_file_not_contains CODE/DISPLAY.CPP "ra_touch_debug"
assert_file_contains WIN32LIB/KEYBOARD/MOUSE.CPP "RA_MOBILE_TOUCH"
assert_file_contains WIN32LIB/KEYBOARD/MOUSE.CPP "mac_sdl_runtime.h"
assert_file_contains WIN32LIB/KEYBOARD/MOUSE.CPP "MacSDL_TouchCursorHidden()"
assert_file_not_contains CODE/DISPLAY.CPP "#if defined(__ANDROID__)"
assert_file_not_contains CODE/TAB.CPP "#if defined(__ANDROID__)"
assert_file_not_contains WIN32LIB/KEYBOARD/MOUSE.CPP "#if defined(__ANDROID__)"

perl -0ne 'exit(/static void mac_queue_mouse_button_with_cursor\([^\)]*\)\s*\{\s*MacMousePoint\.x\s*=\s*x;\s*MacMousePoint\.y\s*=\s*y;[\s\S]*?if \(update_cursor\)/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" \
  || fail "Android tap button events must update the legacy cursor position even when the touch cursor stays hidden"

perl -0ne 'exit(/Uint32 window_flags = SDL_WINDOW_SHOWN \| SDL_WINDOW_RESIZABLE;[\s\S]*#if defined\(RA_MOBILE_TOUCH\)[\s\S]*window_flags \|= SDL_WINDOW_BORDERLESS;[\s\S]*#endif/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" \
  || fail "mobile SDL windows must be borderless so iOS hides system chrome"

perl -0ne 'exit(/#if defined\(RA_IOS\)[\s\S]*SDL_SetHint\(SDL_HINT_ORIENTATIONS,\s*"LandscapeLeft LandscapeRight"\);[\s\S]*SDL_SetHint\(SDL_HINT_IOS_HIDE_HOME_INDICATOR,\s*"1"\);[\s\S]*#endif/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" \
  || fail "iOS SDL windows must restrict UIKit/SDL orientation masks to landscape"

perl -0ne 'exit(/Uint32 window_flags = SDL_WINDOW_SHOWN \| SDL_WINDOW_RESIZABLE;[\s\S]*#if defined\(RA_IOS\)[\s\S]*window_flags &= ~SDL_WINDOW_RESIZABLE;[\s\S]*#endif/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" \
  || fail "iOS SDL windows must not opt into resizable portrait-capable scenes"

assert_file_contains CODE/TEXTBTN.CPP "TPF_USE_GRAD_PAL|TPF_MEDIUM_COLOR"

perl -0ne 'exit(/DisplayClass::Cell_Shadow\([^)]*\)[\s\S]*Cell_Y\(cell\)-1\)\s*>=\s*MAP_CELL_H-2/s ? 0 : 1)' "$ROOT_DIR/CODE/DISPLAY.CPP" \
  || fail "Cell_Shadow must reject the last map row before reading southern neighbors"

perl -0ne 'exit(/DisplayClass::Map_Cell\([^)]*\)[\s\S]*c\s*=\s*Adjacent_Cell\(cell, dir\);[\s\S]*\(unsigned\)c\s*<\s*MAP_CELL_TOTAL[\s\S]*!\(\*this\)\[c\]\.IsMapped/s ? 0 : 1)' "$ROOT_DIR/CODE/DISPLAY.CPP" \
  || fail "Map_Cell must reject adjacent cells outside the physical map before dereferencing them"

perl -0ne 'exit(/#if defined\(RA_MOBILE_TOUCH\)[\s\S]*FacingType\s+facing\s*=\s*KN_To_Facing\(input\);[\s\S]*int\s+distance\s*=\s*CELL_LEPTON_W;[\s\S]*Map\.Scroll_Map\(Facing_Dir\(facing\), distance, true\);[\s\S]*input\s*=\s*KN_NONE;[\s\S]*#endif/s ? 0 : 1)' "$ROOT_DIR/CODE/CONQUER.CPP" \
  || fail "mobile arrow pulses emitted by two-finger pan must scroll the tactical map"

perl -0ne 'exit(/void WWMouseClass::Low_Show_Mouse\(int x, int y\)[\s\S]*MacSDL_TouchCursorHidden\(\)[\s\S]*MouseBuffX\s*=\s*-1[\s\S]*MouseBuffY\s*=\s*-1[\s\S]*return/s ? 0 : 1)' "$ROOT_DIR/WIN32LIB/KEYBOARD/MOUSE.CPP" \
  || fail "Android touch-hidden mode must suppress low-level software cursor drawing without leaving stale mouse backing coordinates"

perl -0ne 'exit(/void WWMouseClass::Draw_Mouse\(GraphicViewPortClass \*scr\)[\s\S]*MacSDL_TouchCursorHidden\(\)[\s\S]*return/s ? 0 : 1)' "$ROOT_DIR/WIN32LIB/KEYBOARD/MOUSE.CPP" \
  || fail "Android touch-hidden mode must suppress explicit software cursor draws"

for ignored_runtime_file in \
  "SAVEGAME.*" \
  "SAVEGAME.NET" \
  "OPTIONS.INI" \
  "ASSERT.TXT" \
  "*.PCX" \
  "*.pcx" \
  "*.LOG" \
  "*.log"; do
assert_file_contains .gitignore "$ignored_runtime_file"
done

assert_file_contains .gitignore "ios/build*/"
assert_file_contains .gitignore "ios/third_party/"

legacy_script="fetch_base_""assets.sh"
legacy_allies="RA_""Allies"
legacy_soviet="RA_""Soviet"
legacy_host="downloads."
legacy_host="${legacy_host}cnc-comm"

[[ ! -e "$ROOT_DIR/scripts/$legacy_script" ]] || fail "legacy asset downloader must not be exported"

for legacy_pattern in "$legacy_host" "$legacy_allies" "$legacy_soviet" "$legacy_script"; do
  grep -R -F "$legacy_pattern" "$ROOT_DIR/NOTICE.md" "$ROOT_DIR/scripts" >/dev/null \
    && fail "exported docs/scripts contain a legacy asset-download reference"
done

grep -F 'https://github.com/electronicarts/CnC_Tiberian_Dawn' "$ROOT_DIR/NOTICE.md" >/dev/null \
  || fail "NOTICE must reference the original EA source repository for provenance"

perl -0ne 'exit(/Buffer_Draw_Stamp_Clip\([^)]*\)\s*\{\s*\}/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "Buffer_Draw_Stamp_Clip is still an empty stub"

perl -0ne 'exit(/Buffer_Frame_To_Page\([^)]*\)\s*\{\s*return Buffer_To_Page/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "Buffer_Frame_To_Page must honor shape flags instead of raw copying"

perl -0ne 'exit(/apply_shape_effects[\s\S]*ghost_table\[256[\s\S]*Buffer_Frame_To_Page[\s\S]*va_start[\s\S]*SHAPE_GHOST/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  || fail "Buffer_Frame_To_Page must apply SHAPE_GHOST remap tables"

perl -0ne 'exit(/Mouse_Shadow_Buffer\([^)]*\)\s*\{\s*\}/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "Mouse_Shadow_Buffer is still an empty stub"

perl -0ne 'exit(/Draw_Mouse\([^)]*\)\s*\{\s*\}/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "Draw_Mouse is still an empty stub"

perl -0ne 'exit(/ASM_Set_Mouse_Cursor\([^)]*\)\s*\{\s*return cursor;\s*\}/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "ASM_Set_Mouse_Cursor must unpack cursor shapes"

perl -0ne 'exit(/VQA_Alloc\([^)]*\)\s*\{\s*return 0;\s*\}/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "VQA_Alloc must return a handle so movie calls do not assert"

perl -0ne 'exit(/VQA_Open\([^)]*\)\s*\{\s*return VQAERR_OPEN;\s*\}/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "VQA_Open must not force movie failure"

perl -0ne 'exit(/VQ_Call_Back[\s\S]*bool\s+break_requested\s*=\s*\(?key\s*==\s*KN_ESC\)?;[\s\S]*#if\s+defined\(RA_MOBILE_TOUCH\)[\s\S]*break_requested[\s\S]*KN_LMOUSE[\s\S]*#endif[\s\S]*\(BreakoutAllowed\s*\|\|\s*Debug_Flag\)[\s\S]*break_requested/s ? 0 : 1)' "$ROOT_DIR/CODE/CONQUER.CPP" \
  || fail "mobile VQA playback must accept a tap through the existing guarded skip path"

perl -0ne 'exit(/Is_Icon_Cached\([^)]*\)\s*\{\s*return 0;\s*\}/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "Is_Icon_Cached must return -1 when the hardware cache is disabled"

grep -F 'dest_ptr + (y * 2) * dest_width' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" >/dev/null \
  && fail "Asm_Interpolate must treat dest_width as the two-row stride passed by Interpolate_2X_Scale"

grep -F 'dst1 = dst0 + dest_width;' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" >/dev/null \
  && fail "Asm_Interpolate must use half of dest_width for the second doubled row"

grep -F 'int row_pitch = dest_width / 2;' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" >/dev/null \
  || fail "Asm_Interpolate must derive the single destination row pitch from dest_width"

grep -F 'char mac_cd_paths[] = "C:\\;D:\\";' "$ROOT_DIR/CODE/INIT.CPP" >/dev/null \
  && fail "bootstrap mixfile search must not force Allies before Soviet"

grep -F 'char mac_cd_paths[] = "?:\\";' "$ROOT_DIR/CODE/INIT.CPP" >/dev/null \
  || fail "bootstrap mixfile search must use the current-CD placeholder"

perl -0ne 'exit(/int Com_Scenario_Dialog\(bool\)\s*\{\s*return 0;\s*\}/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "Com_Scenario_Dialog must not remain an unconditional stub"

perl -0ne 'exit(/int Com_Scenario_Dialog\(bool skirmish\)/s ? 0 : 1)' "$ROOT_DIR/PORT/MAC/src/legacy_primitives.cpp" \
  && fail "Com_Scenario_Dialog must use the original skirmish setup dialog instead of the mac shortcut"

assert_file_contains cmake/cnc95_sources.cmake "CODE/NULLDLG.CPP"

grep -F 'SDL_WINDOW_FULLSCREEN_DESKTOP' "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" >/dev/null \
  || fail "mac SDL runtime must support desktop fullscreen"

grep -F 'SDL_SetWindowFullscreen' "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" >/dev/null \
  || fail "mac SDL runtime must be able to toggle fullscreen"

grep -F 'RA_FULLSCREEN' "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" >/dev/null \
  || fail "mac SDL runtime must allow fullscreen from the run environment"

grep -F 'KMOD_GUI' "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" >/dev/null \
  || fail "mac SDL runtime must support the mac Command key fullscreen shortcut"

grep -R -F "memcpy((char*)&Path" "$ROOT_DIR/CODE" >/dev/null \
  && fail "Path shifts must copy whole FacingType elements"

tmpdir="$(mktemp -d)"
trap 'rm -rf "$tmpdir"' EXIT
"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" "$ROOT_DIR/tests/ddraw_shim_test.cpp" -o "$tmpdir/ddraw_shim_test"
"$tmpdir/ddraw_shim_test"

"${CXX:-c++}" -std=gnu++98 -DENGLISH -DGAME_VERSION=0x00030003 -DINTERNET_OFF -DTRUE_FALSE_DEFINED -DVQADIRECT_SOUND=1 -DWIN32 -D_WINDOWS \
  -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WIN32LIB/INCLUDE" -I"$ROOT_DIR/WIN32LIB/KEYBOARD" \
  -I"$ROOT_DIR/WIN32LIB/DRAWBUFF" -I"$ROOT_DIR/WIN32LIB/IFF" -I"$ROOT_DIR/WIN32LIB/MISC" \
  -I"$ROOT_DIR/WIN32LIB/MEM" -I"$ROOT_DIR/WIN32LIB/MONO" -I"$ROOT_DIR/WIN32LIB/TILE" \
  -I"$ROOT_DIR/CODE" -I"$ROOT_DIR/CODE/ENG" -I"$ROOT_DIR/WINVQ/INCLUDE" \
  -I"$ROOT_DIR/WINVQ/INCLUDE/VQM32" -I"$ROOT_DIR/WINVQ/INCLUDE/WWLIB32" \
  -Wno-nonportable-include-path -Wno-deprecated-declarations -Wno-unknown-pragmas \
  "$ROOT_DIR/tests/coord_cell_test.cpp" -o "$tmpdir/coord_cell_test"
"$tmpdir/coord_cell_test"

"${CXX:-c++}" -std=gnu++98 -ffunction-sections -fdata-sections -DENGLISH -DGAME_VERSION=0x00030003 -DINTERNET_OFF -DTRUE_FALSE_DEFINED -DVQADIRECT_SOUND=1 -DWIN32 -D_WINDOWS \
  -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WIN32LIB/INCLUDE" -I"$ROOT_DIR/WIN32LIB/KEYBOARD" \
  -I"$ROOT_DIR/WIN32LIB/DRAWBUFF" -I"$ROOT_DIR/WIN32LIB/IFF" -I"$ROOT_DIR/WIN32LIB/MISC" \
  -I"$ROOT_DIR/WIN32LIB/MEM" -I"$ROOT_DIR/WIN32LIB/MONO" -I"$ROOT_DIR/WIN32LIB/TILE" \
  -I"$ROOT_DIR/CODE" -I"$ROOT_DIR/CODE/ENG" -I"$ROOT_DIR/WINVQ/INCLUDE" \
  -I"$ROOT_DIR/WINVQ/INCLUDE/VQM32" -I"$ROOT_DIR/WINVQ/INCLUDE/WWLIB32" \
  -Wno-nonportable-include-path -Wno-deprecated-declarations -Wno-unknown-pragmas \
  "$ROOT_DIR/tests/move_point_direction_oob_test.cpp" "$ROOT_DIR/CODE/COORD.CPP" -Wl,-dead_strip -o "$tmpdir/move_point_direction_oob_test"
"$tmpdir/move_point_direction_oob_test"

"${CXX:-c++}" -std=gnu++98 "$ROOT_DIR/tests/radar_icon_offset_width_test.cpp" -o "$tmpdir/radar_icon_offset_width_test"
(cd "$ROOT_DIR" && "$tmpdir/radar_icon_offset_width_test")

"${CXX:-c++}" -std=gnu++98 -DENGLISH -DGAME_VERSION=0x00030003 -DINTERNET_OFF -DTRUE_FALSE_DEFINED -DVQADIRECT_SOUND=1 -DWIN32 -D_WINDOWS \
  -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WIN32LIB/INCLUDE" -I"$ROOT_DIR/WIN32LIB/KEYBOARD" \
  -I"$ROOT_DIR/WIN32LIB/DRAWBUFF" -I"$ROOT_DIR/WIN32LIB/IFF" -I"$ROOT_DIR/WIN32LIB/MISC" \
  -I"$ROOT_DIR/WIN32LIB/MEM" -I"$ROOT_DIR/WIN32LIB/MONO" -I"$ROOT_DIR/WIN32LIB/TILE" \
  -I"$ROOT_DIR/CODE" -I"$ROOT_DIR/CODE/ENG" -I"$ROOT_DIR/WINVQ/INCLUDE" \
  -I"$ROOT_DIR/WINVQ/INCLUDE/VQM32" -I"$ROOT_DIR/WINVQ/INCLUDE/WWLIB32" \
  -Wno-nonportable-include-path -Wno-deprecated-declarations -Wno-unknown-pragmas \
  "$ROOT_DIR/tests/facing_wrap_test.cpp" "$ROOT_DIR/CODE/CONST.CPP" -o "$tmpdir/facing_wrap_test"
"$tmpdir/facing_wrap_test"

"${CXX:-c++}" -std=gnu++98 -DTRUE_FALSE_DEFINED -DBIG_ENDIAN=4321 -DLITTLE_ENDIAN=1234 -I"$ROOT_DIR/CODE" \
  "$ROOT_DIR/tests/fixed_endian_test.cpp" "$ROOT_DIR/CODE/FIXED.CPP" -o "$tmpdir/fixed_endian_test"
"$tmpdir/fixed_endian_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" \
  "$ROOT_DIR/tests/aspect_viewport_test.cpp" -o "$tmpdir/aspect_viewport_test"
"$tmpdir/aspect_viewport_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" \
  "$ROOT_DIR/tests/mobile_touch_gesture_test.cpp" -o "$tmpdir/mobile_touch_gesture_test"
"$tmpdir/mobile_touch_gesture_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" \
  "$ROOT_DIR/tests/mobile_pan_test.cpp" -o "$tmpdir/mobile_pan_test"
"$tmpdir/mobile_pan_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" \
  "$ROOT_DIR/tests/mobile_key_message_test.cpp" -o "$tmpdir/mobile_key_message_test"
"$tmpdir/mobile_key_message_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" \
  "$ROOT_DIR/tests/mobile_rubber_band_test.cpp" -o "$tmpdir/mobile_rubber_band_test"
"$tmpdir/mobile_rubber_band_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/WIN32LIB/WSA" \
  "$ROOT_DIR/tests/wsa_file_format_test.cpp" -o "$tmpdir/wsa_file_format_test"
"$tmpdir/wsa_file_format_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/WIN32LIB/WSA" \
  "$ROOT_DIR/tests/wsa_buffer_layout_test.cpp" -o "$tmpdir/wsa_buffer_layout_test"
"$tmpdir/wsa_buffer_layout_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/CODE" \
  "$ROOT_DIR/tests/shape_cache_capacity_test.cpp" -o "$tmpdir/shape_cache_capacity_test"
"$tmpdir/shape_cache_capacity_test"

"${CXX:-c++}" -std=gnu++98 -DTRUE_FALSE_DEFINED -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WIN32LIB/SHAPE" -I"$ROOT_DIR/WIN32LIB/INCLUDE" \
  "$ROOT_DIR/tests/shape_extract_test.cpp" "$ROOT_DIR/WIN32LIB/SHAPE/GETSHAPE.CPP" -o "$tmpdir/shape_extract_test"
"$tmpdir/shape_extract_test"

"${CXX:-c++}" -std=gnu++98 -DENGLISH -DGAME_VERSION=0x00030003 -DINTERNET_OFF -DTRUE_FALSE_DEFINED -DVQADIRECT_SOUND=1 -DWIN32 -D_WINDOWS \
  -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WIN32LIB/INCLUDE" -I"$ROOT_DIR/WIN32LIB/KEYBOARD" \
  -I"$ROOT_DIR/WIN32LIB/DRAWBUFF" -I"$ROOT_DIR/WIN32LIB/IFF" -I"$ROOT_DIR/WIN32LIB/MISC" \
  -I"$ROOT_DIR/WIN32LIB/MEM" -I"$ROOT_DIR/WIN32LIB/MONO" -I"$ROOT_DIR/WIN32LIB/TILE" \
  -I"$ROOT_DIR/CODE" -I"$ROOT_DIR/CODE/ENG" -I"$ROOT_DIR/WINVQ/INCLUDE" \
  -I"$ROOT_DIR/WINVQ/INCLUDE/VQM32" -I"$ROOT_DIR/WINVQ/INCLUDE/WWLIB32" \
  -Wno-nonportable-include-path -Wno-deprecated-declarations -Wno-unknown-pragmas \
  "$ROOT_DIR/tests/keyframe_decode_test.cpp" "$ROOT_DIR/CODE/2KEYFRAM.CPP" "$ROOT_DIR/CODE/CRC.CPP" \
  "$ROOT_DIR/CODE/LCWUNCMP.CPP" -o "$tmpdir/keyframe_decode_test"
if [[ -f "$ROOT_DIR/assets/cnc/gdi/CONQUER.MIX" ]]; then
  "$tmpdir/keyframe_decode_test" "$ROOT_DIR/assets/cnc/gdi/CONQUER.MIX"
else
  echo "Skipping keyframe decode test; local C&C assets are not present."
fi

"${CXX:-c++}" -std=gnu++98 -DTRUE_FALSE_DEFINED -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WIN32LIB/INCLUDE" \
  "$ROOT_DIR/tests/cps_uncompress_test.cpp" "$ROOT_DIR/WIN32LIB/IFF/LOAD.CPP" -o "$tmpdir/cps_uncompress_test"
"$tmpdir/cps_uncompress_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" "$ROOT_DIR/tests/dos_compat_test.cpp" "$ROOT_DIR/PORT/MAC/src/dos_compat.cpp" -o "$tmpdir/dos_compat_test"
"$tmpdir/dos_compat_test"

"${CXX:-c++}" -std=gnu++98 -DTRUE_FALSE_DEFINED -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WIN32LIB/INCLUDE" -I"$ROOT_DIR/WIN32LIB/AUDIO" \
  "$ROOT_DIR/tests/audio_shim_test.cpp" "$ROOT_DIR/PORT/MAC/src/mac_audio_stub.cpp" $(pkg-config --cflags --libs sdl2) -o "$tmpdir/audio_shim_test"
"$tmpdir/audio_shim_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" "$ROOT_DIR/tests/timer_shim_test.cpp" "$ROOT_DIR/PORT/MAC/src/mac_timer.cpp" -o "$tmpdir/timer_shim_test"
"$tmpdir/timer_shim_test"

"${CXX:-c++}" -std=gnu++98 -I"$ROOT_DIR/PORT/MAC/include" "$ROOT_DIR/tests/input_shim_test.cpp" "$ROOT_DIR/PORT/MAC/src/mac_sdl_runtime.cpp" "$ROOT_DIR/PORT/MAC/src/mac_timer.cpp" $(pkg-config --cflags --libs sdl2) -o "$tmpdir/input_shim_test"
"$tmpdir/input_shim_test"

"${CXX:-c++}" -std=gnu++98 -DTRUE_FALSE_DEFINED -DVQADIRECT_SOUND=1 -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WINVQ/INCLUDE" -I"$ROOT_DIR/WINVQ/INCLUDE/VQM32" -I"$ROOT_DIR/WINVQ/INCLUDE/WWLIB32" \
  "$ROOT_DIR/tests/vqa_decode_test.cpp" "$ROOT_DIR/PORT/MAC/src/mac_vqa.cpp" "$ROOT_DIR/PORT/MAC/src/mac_timer.cpp" "$ROOT_DIR/CODE/LCWUNCMP.CPP" $(pkg-config --cflags --libs sdl2) -o "$tmpdir/vqa_decode_test"
"$tmpdir/vqa_decode_test"

"${CXX:-c++}" -std=gnu++98 -DTRUE_FALSE_DEFINED -DVQADIRECT_SOUND=1 -I"$ROOT_DIR/PORT/MAC/include" -I"$ROOT_DIR/WINVQ/INCLUDE" -I"$ROOT_DIR/WINVQ/INCLUDE/VQM32" -I"$ROOT_DIR/WINVQ/INCLUDE/WWLIB32" \
  "$ROOT_DIR/tests/vqa_file_smoke_test.cpp" "$ROOT_DIR/PORT/MAC/src/mac_vqa.cpp" "$ROOT_DIR/PORT/MAC/src/mac_timer.cpp" "$ROOT_DIR/CODE/LCWUNCMP.CPP" $(pkg-config --cflags --libs sdl2) -o "$tmpdir/vqa_file_smoke_test"
(cd "$ROOT_DIR" && SDL_AUDIODRIVER=dummy "$tmpdir/vqa_file_smoke_test")

echo "run script tests passed"
