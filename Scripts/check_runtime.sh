#!/usr/bin/env bash

set -u

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN="$ROOT/Build/Core/KapilOS"

echo "=============================================="
echo "        KapilOS Runtime Check"
echo "=============================================="
echo

echo "[1] Project"
echo "Root : $ROOT"
echo

echo "[2] Executable"

if [ -f "$BIN" ]; then
    echo "FOUND: $BIN"
    ls -lh "$BIN"
else
    echo "ERROR: KapilOS executable not found."
    echo
    echo "Try building it first:"
    echo
    echo "  cd \"$ROOT/Source/Core\""
    echo "  cmake -S . -B ../../Build/Core"
    echo "  cmake --build ../../Build/Core -j\$(nproc)"
    exit 1
fi

echo
echo "[3] Executable type"
file "$BIN" || true

echo
echo "[4] Architecture"
readelf -h "$BIN" 2>/dev/null | grep -E \
'Class:|Data:|Type:|Machine:' || true

echo
echo "[5] Dynamic libraries"
ldd "$BIN" 2>/dev/null || true

echo
echo "[6] SDL libraries"
ldconfig -p 2>/dev/null | grep -E \
'libSDL2|libSDL2_image' || true

echo
echo "[7] GUI environment"

echo "DISPLAY=${DISPLAY:-<not set>}"
echo "WAYLAND_DISPLAY=${WAYLAND_DISPLAY:-<not set>}"
echo "XDG_RUNTIME_DIR=${XDG_RUNTIME_DIR:-<not set>}"

echo
echo "[8] Graphics backends"

echo "SDL_VIDEODRIVER=${SDL_VIDEODRIVER:-<not set>}"

echo
echo "[9] Required asset locations"

for f in \
    "$ROOT/Assets/Wallpapers/wallpaper.jpg" \
    "$ROOT/Assets/Wallpapers/wallpaper.avif" \
    "$ROOT/Assets/Icons/PNG" \
    "$ROOT/Assets/Icons/SVG"
do
    if [ -e "$f" ]; then
        echo "FOUND: $f"
    else
        echo "MISSING: $f"
    fi
done

echo
echo "=============================================="
echo " Runtime check complete"
echo "=============================================="
