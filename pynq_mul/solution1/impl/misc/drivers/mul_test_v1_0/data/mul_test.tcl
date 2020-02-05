# ==============================================================
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
# Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
# ==============================================================
proc generate {drv_handle} {
    xdefine_include_file $drv_handle "xparameters.h" "XMul_test" \
        "NUM_INSTANCES" \
        "DEVICE_ID" \
        "C_S_AXI_MUL_IO_BASEADDR" \
        "C_S_AXI_MUL_IO_HIGHADDR"

    xdefine_config_file $drv_handle "xmul_test_g.c" "XMul_test" \
        "DEVICE_ID" \
        "C_S_AXI_MUL_IO_BASEADDR"

    xdefine_canonical_xpars $drv_handle "xparameters.h" "XMul_test" \
        "DEVICE_ID" \
        "C_S_AXI_MUL_IO_BASEADDR" \
        "C_S_AXI_MUL_IO_HIGHADDR"
}

