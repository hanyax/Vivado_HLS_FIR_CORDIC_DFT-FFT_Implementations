// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmul_test.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMul_test_CfgInitialize(XMul_test *InstancePtr, XMul_test_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Mul_io_BaseAddress = ConfigPtr->Mul_io_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMul_test_Start(XMul_test *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_AP_CTRL) & 0x80;
    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMul_test_IsDone(XMul_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMul_test_IsIdle(XMul_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMul_test_IsReady(XMul_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMul_test_EnableAutoRestart(XMul_test *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_AP_CTRL, 0x80);
}

void XMul_test_DisableAutoRestart(XMul_test *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_AP_CTRL, 0);
}

u32 XMul_test_Get_out_r(XMul_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_OUT_R_DATA);
    return Data;
}

u32 XMul_test_Get_out_r_vld(XMul_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_OUT_R_CTRL);
    return Data & 0x1;
}

void XMul_test_Set_in_r(XMul_test *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_IN_R_DATA, Data);
}

u32 XMul_test_Get_in_r(XMul_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_IN_R_DATA);
    return Data;
}

void XMul_test_InterruptGlobalEnable(XMul_test *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_GIE, 1);
}

void XMul_test_InterruptGlobalDisable(XMul_test *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_GIE, 0);
}

void XMul_test_InterruptEnable(XMul_test *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_IER);
    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_IER, Register | Mask);
}

void XMul_test_InterruptDisable(XMul_test *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_IER);
    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_IER, Register & (~Mask));
}

void XMul_test_InterruptClear(XMul_test *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMul_test_WriteReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_ISR, Mask);
}

u32 XMul_test_InterruptGetEnabled(XMul_test *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_IER);
}

u32 XMul_test_InterruptGetStatus(XMul_test *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMul_test_ReadReg(InstancePtr->Mul_io_BaseAddress, XMUL_TEST_MUL_IO_ADDR_ISR);
}

