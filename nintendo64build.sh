
## Check if $N64_INST is set.
if test ! $N64_INST; then { echo "ERROR: Set \$N64_INST installing libdragon before continuing."; exit 1; } fi

## We are using dreamcast branch including N64 changes 
git clone https://github.com/raylib4Consoles/raylib -b raylib4Consoles
## Copy file needed to build raylib
cp custom/raylib4Nintendo64.mk $N64_INST/include
cd raylib/src
make PLATFORM=PLATFORM_NINTENDO64
make PLATFORM=PLATFORM_NINTENDO64 install
