#!/bin/bash

TOOLCHAIN_DIR=${HOME}/output/toolchain_xburst1_musl_gcc13/per-package/toolchain/host
CROSS_COMPILE=mipsel-linux-
#KERNEL_DIR=${HOME}/output/cinnado_d1_t31l_sc2336_pru/build/linux-custom
KERNEL_DIR=${HOME}/ingenic-t31-zrt-kernel-4.4.94-matteius

case "$1" in
	clean)
		find . -type f -name "*.o"     -delete
		find . -type f -name "*.o.*"   -delete
		find . -type f -name "*.ko"    -delete
		find . -type f -name "*.ko.*"  -delete
		find . -type f -name "*.mod.c" -delete
		rm -f Module.symvers
		rm -f modules.order
		rm -rf .tmp_versions
		exit 0
		;;
	t10 | t20 | t21 | t23 | t30 | t31 | t40 | t41)
		export ISP_ENV_KERNEL_DIR="${KERNEL_DIR}"
		export CROSS_COMPILE="${TOOLCHAIN_DIR}/bin/${CROSS_COMPILE}"

		FAM="SOC_FAMILY=$1 CONFIG_SOC_${1^^}=y"
		make V=2 ARCH=mips $FAM -C $ISP_ENV_KERNEL_DIR M=$PWD ${@:2}
		;;
	*)
		echo "Usage: $0 <soc|clean>"
		;;
esac

exit 0
