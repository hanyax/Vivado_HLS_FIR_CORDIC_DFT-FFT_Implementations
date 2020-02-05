// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Mon Jan 27 21:36:18 2020
// Host        : DESKTOP-8CE0NHA running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/hax032/Desktop/CSE237C_hax032/pynq_mul/mul_test/mul_test.srcs/sources_1/bd/design_1/ip/design_1_mul_test_0_0/design_1_mul_test_0_0_stub.v
// Design      : design_1_mul_test_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "mul_test,Vivado 2019.1" *)
module design_1_mul_test_0_0(s_axi_mul_io_AWADDR, s_axi_mul_io_AWVALID, 
  s_axi_mul_io_AWREADY, s_axi_mul_io_WDATA, s_axi_mul_io_WSTRB, s_axi_mul_io_WVALID, 
  s_axi_mul_io_WREADY, s_axi_mul_io_BRESP, s_axi_mul_io_BVALID, s_axi_mul_io_BREADY, 
  s_axi_mul_io_ARADDR, s_axi_mul_io_ARVALID, s_axi_mul_io_ARREADY, s_axi_mul_io_RDATA, 
  s_axi_mul_io_RRESP, s_axi_mul_io_RVALID, s_axi_mul_io_RREADY, ap_clk, ap_rst_n, interrupt)
/* synthesis syn_black_box black_box_pad_pin="s_axi_mul_io_AWADDR[4:0],s_axi_mul_io_AWVALID,s_axi_mul_io_AWREADY,s_axi_mul_io_WDATA[31:0],s_axi_mul_io_WSTRB[3:0],s_axi_mul_io_WVALID,s_axi_mul_io_WREADY,s_axi_mul_io_BRESP[1:0],s_axi_mul_io_BVALID,s_axi_mul_io_BREADY,s_axi_mul_io_ARADDR[4:0],s_axi_mul_io_ARVALID,s_axi_mul_io_ARREADY,s_axi_mul_io_RDATA[31:0],s_axi_mul_io_RRESP[1:0],s_axi_mul_io_RVALID,s_axi_mul_io_RREADY,ap_clk,ap_rst_n,interrupt" */;
  input [4:0]s_axi_mul_io_AWADDR;
  input s_axi_mul_io_AWVALID;
  output s_axi_mul_io_AWREADY;
  input [31:0]s_axi_mul_io_WDATA;
  input [3:0]s_axi_mul_io_WSTRB;
  input s_axi_mul_io_WVALID;
  output s_axi_mul_io_WREADY;
  output [1:0]s_axi_mul_io_BRESP;
  output s_axi_mul_io_BVALID;
  input s_axi_mul_io_BREADY;
  input [4:0]s_axi_mul_io_ARADDR;
  input s_axi_mul_io_ARVALID;
  output s_axi_mul_io_ARREADY;
  output [31:0]s_axi_mul_io_RDATA;
  output [1:0]s_axi_mul_io_RRESP;
  output s_axi_mul_io_RVALID;
  input s_axi_mul_io_RREADY;
  input ap_clk;
  input ap_rst_n;
  output interrupt;
endmodule
