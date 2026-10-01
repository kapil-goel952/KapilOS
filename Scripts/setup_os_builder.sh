#!/usr/bin/env bash

set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo
echo "=============================================="
echo "        KapilOS OS Builder Setup"
echo "=============================================="
echo

echo "[1/5] Updating package lists..."
sudo apt update

echo
echo "[2/5] Installing live-build..."
sudo apt install -y \
    live-build \
    squashfs-tools \
    xorriso

echo
echo "[3/5] Installing QEMU..."
sudo apt install -y \
    qemu-system-x86

echo
echo "[4/5] Checking tools..."

echo
echo "live-build:"
lb --version || true

echo
echo "xorriso:"
xorriso --version | head -n 2

echo
echo "QEMU:"
qemu-system-x86_64 --version | head -n 1

echo
echo "GRUB:"
grub-mkrescue --version

echo
echo "[5/5] Creating ISO build workspace..."

mkdir -p "$ROOT/ISO"
mkdir -p "$ROOT/Build/Live"

echo
echo "=============================================="
echo "          KapilOS Builder Ready"
echo "=============================================="
echo
echo "Project : $ROOT"
echo
echo "Next stage:"
echo "  Linux kernel"
echo "  live root filesystem"
echo "  Xorg"
echo "  SDL2"
echo "  KapilOS GUI"
echo "  GRUB"
echo "  ISO"
echo
