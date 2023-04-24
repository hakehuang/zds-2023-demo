# NXP SoC family CMake file
#
# Copyright (c) 2021 NXP
# SPDX-License-Identifier: Apache-2.0

zephyr_interface_library_named(NXP_FUSION_DSP_COMMON)

zephyr_library_named(nxp_fusion_dsp_common)
zephyr_library_include_directories(include)
zephyr_library_include_directories(${ZEPHYR_BASE}/drivers)

zephyr_library_sources(soc.c)
zephyr_library_sources(mu.c)

zephyr_library_link_libraries(NXP_FUSION_DSP_COMMON)

target_include_directories(NXP_FUSION_DSP_COMMON INTERFACE include)
target_link_libraries(NXP_FUSION_DSP_COMMON INTERFACE nxp_fusion_dsp_common)
