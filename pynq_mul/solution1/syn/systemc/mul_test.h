// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _mul_test_HH_
#define _mul_test_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "mul_test_mul_io_s_axi.h"

namespace ap_rtl {

template<unsigned int C_S_AXI_MUL_IO_ADDR_WIDTH = 5,
         unsigned int C_S_AXI_MUL_IO_DATA_WIDTH = 32>
struct mul_test : public sc_module {
    // Port declarations 20
    sc_in< sc_logic > s_axi_mul_io_AWVALID;
    sc_out< sc_logic > s_axi_mul_io_AWREADY;
    sc_in< sc_uint<C_S_AXI_MUL_IO_ADDR_WIDTH> > s_axi_mul_io_AWADDR;
    sc_in< sc_logic > s_axi_mul_io_WVALID;
    sc_out< sc_logic > s_axi_mul_io_WREADY;
    sc_in< sc_uint<C_S_AXI_MUL_IO_DATA_WIDTH> > s_axi_mul_io_WDATA;
    sc_in< sc_uint<C_S_AXI_MUL_IO_DATA_WIDTH/8> > s_axi_mul_io_WSTRB;
    sc_in< sc_logic > s_axi_mul_io_ARVALID;
    sc_out< sc_logic > s_axi_mul_io_ARREADY;
    sc_in< sc_uint<C_S_AXI_MUL_IO_ADDR_WIDTH> > s_axi_mul_io_ARADDR;
    sc_out< sc_logic > s_axi_mul_io_RVALID;
    sc_in< sc_logic > s_axi_mul_io_RREADY;
    sc_out< sc_uint<C_S_AXI_MUL_IO_DATA_WIDTH> > s_axi_mul_io_RDATA;
    sc_out< sc_lv<2> > s_axi_mul_io_RRESP;
    sc_out< sc_logic > s_axi_mul_io_BVALID;
    sc_in< sc_logic > s_axi_mul_io_BREADY;
    sc_out< sc_lv<2> > s_axi_mul_io_BRESP;
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_out< sc_logic > interrupt;
    sc_signal< sc_logic > ap_var_for_const0;
    // Port declarations for the virtual clock. 
    sc_in_clk ap_virtual_clock;


    // Module declarations
    mul_test(sc_module_name name);
    SC_HAS_PROCESS(mul_test);

    ~mul_test();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    mul_test_mul_io_s_axi<C_S_AXI_MUL_IO_ADDR_WIDTH,C_S_AXI_MUL_IO_DATA_WIDTH>* mul_test_mul_io_s_axi_U;
    sc_signal< sc_logic > ap_start;
    sc_signal< sc_logic > ap_done;
    sc_signal< sc_logic > ap_idle;
    sc_signal< sc_logic > ap_ready;
    sc_signal< sc_lv<32> > out_r;
    sc_signal< sc_logic > out_r_ap_vld;
    sc_signal< sc_lv<32> > in_r;
    sc_signal< sc_logic > ap_rst_n_inv;
    static const sc_logic ap_const_logic_1;
    static const int C_S_AXI_DATA_WIDTH;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_rst_n_inv();
    void thread_out_r();
    void thread_out_r_ap_vld();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif
