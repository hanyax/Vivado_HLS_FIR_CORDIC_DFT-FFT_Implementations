// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmul_test.h"

extern XMul_test_Config XMul_test_ConfigTable[];

XMul_test_Config *XMul_test_LookupConfig(u16 DeviceId) {
	XMul_test_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMUL_TEST_NUM_INSTANCES; Index++) {
		if (XMul_test_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMul_test_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMul_test_Initialize(XMul_test *InstancePtr, u16 DeviceId) {
	XMul_test_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMul_test_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMul_test_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

