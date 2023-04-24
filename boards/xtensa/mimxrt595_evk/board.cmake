#
# Copyright (c) 2020, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

set(SUPPORTED_EMU_PLATFORMS qemu)

set(QEMU_CPU_TYPE_${ARCH} sample_controller)

set(QEMU_FLAGS_${ARCH}
	-machine xt-rt595-nommu -semihosting -nographic -cpu sample_controller
  )

