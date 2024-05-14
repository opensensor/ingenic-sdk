#!/bin/bash

KERNEL_DIR="/home/matteius/output/exp_t31x_gc2053_rtl8189ftv_kernel44/build/linux-custom/"
CROSS_COMPILE=/home/matteius/output/exp_t31x_gc2053_rtl8189ftv_kernel44/per-package/prudynt-t/host/bin/mipsel-thingino-linux-musl-
DEFAULT_KERNEL_VERSION="4.4"

# Check if KERNEL_DIR is empty
if [ -z "$KERNEL_DIR" ]; then
  echo "Error: KERNEL_DIR is not set. Please specify the kernel directory in this script."
  exit 1
fi

# Extract SoC and Kernel Version from arguments
SOC_MODEL="$1"
KERNEL_VERSION="${2:-$DEFAULT_KERNEL_VERSION}" # Use second argument or default to 3.10

case "$SOC_MODEL" in
  clean)
   find . -type f -name "*.o"     -delete
   find . -type f -name "*.o.*"   -delete
   find . -type f -name "*.ko"    -delete
   find . -type f -name "*.ko.*"  -delete
   find . -type f -name "*.so"    -delete
   find . -type f -name "*.mod.c" -delete
   rm -f Module.symvers
   rm -f modules.order
   rm -rf .tmp_versions
   exit 0
   ;;
  t10 | t20 | t21 | t23 | t30 | t31 | t40 | t41)
   export ISP_ENV_KERNEL_DIR="${KERNEL_DIR}"
   export CROSS_COMPILE="/home/matteius/output/exp_t31x_gc2053_rtl8189ftv_kernel44/per-package/prudynt-t/host/bin/mipsel-thingino-linux-musl-"

   FAM="SOC_FAMILY=$SOC_MODEL CONFIG_SOC_${SOC_MODEL^^}=y KERNEL_VERSION=${KERNEL_VERSION}"

   # Modify the Makefile to build the shared object (.so) file
   sed -i 's/obj-m += $(OUT).o/$(OUT).so: $($(OUT)-objs)\n\t$(CXX) -shared -fPIC $(CFLAGS_MODULE) -o $@ $^/' Makefile

   make V=2 ARCH=mips $FAM -C $ISP_ENV_KERNEL_DIR M=$PWD EXTRA_CFLAGS="-gdwarf-4 -Og" OPTIONS="!strip debug" ${@:3}
   ;;
  *)
   echo "Usage: $0 <soc> [kernel_version] <make_args>"
   echo "Usage: $0 clean"
   echo "Example: $0 t20 3.10"
   exit 1
   ;;
esac

exit 0