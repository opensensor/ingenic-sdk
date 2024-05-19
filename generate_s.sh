#!/bin/bash

# Check if the library path is provided
if [ -z "$1" ]; then
    echo "Usage: $0 /path/to/static_library.a"
    exit 1
fi

# Get the absolute path of the static library
LIB_PATH=$(realpath $1)

# Get the directory and base name of the library
LIB_DIR=$(dirname $LIB_PATH)
LIB_BASE=$(basename $LIB_PATH .a)

# Create a directory to store the extracted object files and assembly files
EXTRACT_DIR=${LIB_BASE}-disassembly
mkdir -p $EXTRACT_DIR
cd $EXTRACT_DIR

# Extract the object files from the static library
/home/matteius/output/exp_t31x_gc2053_rtl8189ftv_kernel44/per-package/prudynt-t/host/bin/mipsel-thingino-linux-musl-ar x $LIB_PATH

# Disassemble each object file to generate .S files
for obj_file in *.o; do
    objdump -d $obj_file > ${obj_file%.o}.S
done

echo "Disassembly complete. Assembly files are located in $EXTRACT_DIR"

