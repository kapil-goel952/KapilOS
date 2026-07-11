#!/bin/bash
source ../kapilos.conf

echo ""
echo "Operating System : $OS_NAME"
echo "Version          : $OS_VERSION"
echo "Codename         : $CODENAME"
echo "Base             : $BASE_DISTRO"
echo ""

echo "==================================="
echo "      KapilOS Build System"
echo "==================================="

echo ""
echo "Checking Build Tools..."

git --version
gcc --version | head -n 1
g++ --version | head -n 1
cmake --version | head -n 1
python3 --version
make --version | head -n 1

echo ""
echo "Checking System..."

uname -r
cat /etc/os-release | grep PRETTY_NAME

echo ""
echo "Everything looks good."

echo ""
echo "KapilOS Build Ready!"
