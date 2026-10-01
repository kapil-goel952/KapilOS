#!/usr/bin/env bash

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD="$ROOT/Build/Live"
OUTPUT="$ROOT/ISO"

echo
echo "=================================================="
echo "              KapilOS ISO BUILDER"
echo "=================================================="
echo
echo "Project : $ROOT"
echo "Build   : $BUILD"
echo "Output  : $OUTPUT"
echo

# --------------------------------------------------
# Check executable
# --------------------------------------------------

KAPILOS_BIN="$ROOT/Build/Core/KapilOS"

if [ ! -x "$KAPILOS_BIN" ]; then
    echo "[INFO] KapilOS executable not found."
    echo "[INFO] Building KapilOS first..."
    echo

    cmake -S "$ROOT/Source/Core" \
          -B "$ROOT/Build/Core"

    cmake --build "$ROOT/Build/Core" \
          -j"$(nproc)"
fi

if [ ! -x "$KAPILOS_BIN" ]; then
    echo "[ERROR] KapilOS executable could not be built."
    exit 1
fi

echo
echo "[OK] KapilOS executable:"
file "$KAPILOS_BIN"

# --------------------------------------------------
# Check required host tools
# --------------------------------------------------

echo
echo "[1/7] Checking build tools..."

for tool in lb xorriso grub-mkrescue qemu-system-x86_64; do
    if command -v "$tool" >/dev/null 2>&1; then
        echo "[OK] $tool"
    else
        echo "[ERROR] Missing: $tool"
        exit 1
    fi
done

# --------------------------------------------------
# Prepare workspace
# --------------------------------------------------

echo
echo "[2/7] Preparing live-build workspace..."

sudo mkdir -p "$BUILD"
sudo chown -R "$USER:$USER" "$BUILD"

rm -rf "$BUILD/config"

mkdir -p "$BUILD/config/package-lists"
mkdir -p "$BUILD/config/includes.chroot/usr/local/bin"
mkdir -p "$BUILD/config/includes.chroot/Assets"
mkdir -p "$BUILD/config/includes.chroot/home/kapil"
mkdir -p "$BUILD/config/hooks/live"

# --------------------------------------------------
# Copy KapilOS executable
# --------------------------------------------------

echo
echo "[3/7] Installing KapilOS executable..."

cp "$KAPILOS_BIN" \
   "$BUILD/config/includes.chroot/usr/local/bin/kapilos"

chmod +x \
   "$BUILD/config/includes.chroot/usr/local/bin/kapilos"

# --------------------------------------------------
# Copy assets
# --------------------------------------------------

echo
echo "[4/7] Installing KapilOS assets..."

cp -a \
   "$ROOT/Assets/." \
   "$BUILD/config/includes.chroot/Assets/"

# --------------------------------------------------
# Package list
# --------------------------------------------------

cat > "$BUILD/config/package-lists/kapilos.list.chroot" <<'EOF'
linux-image-generic
systemd
sudo

xorg
xserver-xorg-core
xserver-xorg-video-all
xinit
xauth
x11-xserver-utils

libsdl2-2.0-0
libsdl2-image-2.0-0

libgl1
libgl1-mesa-dri
mesa-utils

dbus
network-manager

fonts-dejavu-core
EOF

# --------------------------------------------------
# KapilOS startup hook
# --------------------------------------------------

cat > "$BUILD/config/hooks/live/010-kapilos.chroot" <<'EOF'
#!/usr/bin/env bash

set -e

echo "[KapilOS] Configuring user..."

# Create KapilOS desktop user.
if ! id kapil >/dev/null 2>&1; then
    useradd \
        --create-home \
        --shell /bin/bash \
        kapil
fi

# Give the desktop user sudo access.
usermod -aG sudo kapil

# Password is not needed for the live desktop.
passwd -d kapil >/dev/null 2>&1 || true

# --------------------------------------------------
# Xorg startup configuration
# --------------------------------------------------

mkdir -p /etc/X11

cat > /etc/X11/Xwrapper.config <<'XWRAPPER'
allowed_users=console
needs_root_rights=yes
XWRAPPER

# --------------------------------------------------
# Autologin on tty1
# --------------------------------------------------

mkdir -p /etc/systemd/system/getty@tty1.service.d

cat > /etc/systemd/system/getty@tty1.service.d/autologin.conf <<'GETTY'
[Service]
ExecStart=
ExecStart=-/sbin/agetty --autologin kapil --noclear %I $TERM
Type=idle
GETTY

# --------------------------------------------------
# Start KapilOS automatically
# --------------------------------------------------

cat > /home/kapil/.bash_profile <<'PROFILE'
#!/bin/bash

if [ "$(tty 2>/dev/null)" = "/dev/tty1" ] && \
   [ -z "${DISPLAY:-}" ]; then

    cd /home/kapil

    export SDL_VIDEODRIVER=x11
    export SDL_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR=0

    exec startx \
        /usr/local/bin/kapilos \
        -- \
        :0 \
        vt1 \
        -keeptty \
        -nolisten tcp
fi
PROFILE

chown kapil:kapil /home/kapil/.bash_profile
chmod 755 /home/kapil/.bash_profile

# --------------------------------------------------
# Basic hostname
# --------------------------------------------------

echo "kapilos" > /etc/hostname

# --------------------------------------------------
# Ensure tty1 starts with boot
# --------------------------------------------------

mkdir -p /etc/systemd/system/getty.target.wants

ln -sf \
    /lib/systemd/system/getty@.service \
    /etc/systemd/system/getty.target.wants/getty@tty1.service

echo "[KapilOS] User and startup configuration complete."
EOF

chmod +x "$BUILD/config/hooks/live/010-kapilos.chroot"

# --------------------------------------------------
# live-build configuration
# --------------------------------------------------

echo
echo "[5/7] Configuring live-build..."

cd "$BUILD"

lb config \
    --distribution noble \
    --architectures amd64 \
    --binary-images iso-hybrid \
    --archive-areas "main universe restricted multiverse" \
    --apt-recommends true \
    --linux-flavours generic \
    --debian-installer false

# --------------------------------------------------
# Build
# --------------------------------------------------

echo
echo "[6/7] Building KapilOS ISO..."
echo
echo "This stage creates:"
echo "  - Linux kernel"
echo "  - initramfs"
echo "  - root filesystem"
echo "  - Xorg"
echo "  - SDL2"
echo "  - KapilOS"
echo "  - GRUB"
echo "  - bootable ISO"
echo

sudo lb build

# --------------------------------------------------
# Locate output
# --------------------------------------------------

echo
echo "[7/7] Collecting ISO..."

ISO_FILE="$(find "$BUILD" -maxdepth 1 -type f -name '*.iso' | head -n 1 || true)"

if [ -z "$ISO_FILE" ]; then
    echo
    echo "[ERROR] live-build finished but no ISO was found."
    echo
    echo "Check:"
    echo "  $BUILD"
    exit 1
fi

mkdir -p "$OUTPUT"

FINAL="$OUTPUT/KapilOS-0.1-Genesis.iso"

sudo cp "$ISO_FILE" "$FINAL"
sudo chown "$USER:$USER" "$FINAL"

echo
echo "=================================================="
echo "             KAPILOS ISO READY"
echo "=================================================="
echo
echo "ISO:"
echo "  $FINAL"
echo
ls -lh "$FINAL"
echo
echo "Type:"
file "$FINAL"
echo
echo "You can test it with:"
echo
echo "  qemu-system-x86_64 -cdrom \"$FINAL\" -m 4096"
echo
echo "=================================================="
