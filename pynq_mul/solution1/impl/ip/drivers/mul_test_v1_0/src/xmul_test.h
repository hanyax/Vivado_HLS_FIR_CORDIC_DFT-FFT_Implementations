// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMUL_TEST_H
#define XMUL_TEST_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmul_test_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Mul_io_BaseAddress;
} XMul_test_Config;
#endif

typedef struct {
    u32 Mul_io_BaseAddress;
    u32 IsReady;
} XMul_test;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMul_test_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMul_test_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMul_test_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMul_test_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMul_test_Initialize(XMul_test *InstancePtr, u16 DeviceId);
XMul_test_Config* XMul_test_LookupConfig(u16 DeviceId);
int XMul_test_CfgInitialize(XMul_test *InstancePtr, XMul_test_Config *ConfigPtr);
#else
int XMul_test_Initialize(XMul_test *InstancePtr, const char* InstanceName);
int XMul_test_Release(XMul_test *InstancePtr);
#endif

void XMul_test_Start(XMul_test *InstancePtr);
u32 XMul_test_IsDone(XMul_test *InstancePtr);
u32 XMul_test_IsIdle(XMul_test *InstancePtr);
u32 XMul_test_IsReady(XMul_test *InstancePtr);
void XMul_test_EnableAutoRestart(XMul_test *InstancePtr);
void XMul_test_DisableAutoRestart(XMul_test *InstancePtr);

u32 XMul_test_Get_out_r(XMul_test *InstancePtr);
u32 XMul_test_Get_out_r_vld(XMul_test *InstancePtr);
void XMul_test_Set_in_r(XMul_test *InstancePtr, u32 Data);
u32 XMul_test_Get_in_r(XMul_test *InstancePtr);

void XMul_test_InterruptGlobalEnable(XMul_test *InstancePtr);
void XMul_test_InterruptGlobalDisable(XMul_test *InstancePtr);
void XMul_test_InterruptEnable(XMul_test *InstancePtr, u32 Mask);
void XMul_test_InterruptDisable(XMul_test *InstancePtr, u32 Mask);
void XMul_test_InterruptClear(XMul_test *InstancePtr, u32 Mask);
u32 XMul_test_InterruptGetEnabled(XMul_test *InstancePtr);
u32 XMul_test_InterruptGetStatus(XMul_test *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
