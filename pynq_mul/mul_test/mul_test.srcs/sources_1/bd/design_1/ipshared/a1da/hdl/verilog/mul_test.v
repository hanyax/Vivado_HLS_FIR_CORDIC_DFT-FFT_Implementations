// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="mul_test,hls_ip_2019_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020-clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=2.000000,HLS_SYN_LAT=0,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=112,HLS_SYN_LUT=168,HLS_VERSION=2019_1}" *)

module mul_test (
        s_axi_mul_io_AWVALID,
        s_axi_mul_io_AWREADY,
        s_axi_mul_io_AWADDR,
        s_axi_mul_io_WVALID,
        s_axi_mul_io_WREADY,
        s_axi_mul_io_WDATA,
        s_axi_mul_io_WSTRB,
        s_axi_mul_io_ARVALID,
        s_axi_mul_io_ARREADY,
        s_axi_mul_io_ARADDR,
        s_axi_mul_io_RVALID,
        s_axi_mul_io_RREADY,
        s_axi_mul_io_RDATA,
        s_axi_mul_io_RRESP,
        s_axi_mul_io_BVALID,
        s_axi_mul_io_BREADY,
        s_axi_mul_io_BRESP,
        ap_clk,
        ap_rst_n,
        interrupt
);

parameter    C_S_AXI_MUL_IO_DATA_WIDTH = 32;
parameter    C_S_AXI_MUL_IO_ADDR_WIDTH = 5;
parameter    C_S_AXI_DATA_WIDTH = 32;

parameter C_S_AXI_MUL_IO_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_WSTRB_WIDTH = (32 / 8);

input   s_axi_mul_io_AWVALID;
output   s_axi_mul_io_AWREADY;
input  [C_S_AXI_MUL_IO_ADDR_WIDTH - 1:0] s_axi_mul_io_AWADDR;
input   s_axi_mul_io_WVALID;
output   s_axi_mul_io_WREADY;
input  [C_S_AXI_MUL_IO_DATA_WIDTH - 1:0] s_axi_mul_io_WDATA;
input  [C_S_AXI_MUL_IO_WSTRB_WIDTH - 1:0] s_axi_mul_io_WSTRB;
input   s_axi_mul_io_ARVALID;
output   s_axi_mul_io_ARREADY;
input  [C_S_AXI_MUL_IO_ADDR_WIDTH - 1:0] s_axi_mul_io_ARADDR;
output   s_axi_mul_io_RVALID;
input   s_axi_mul_io_RREADY;
output  [C_S_AXI_MUL_IO_DATA_WIDTH - 1:0] s_axi_mul_io_RDATA;
output  [1:0] s_axi_mul_io_RRESP;
output   s_axi_mul_io_BVALID;
input   s_axi_mul_io_BREADY;
output  [1:0] s_axi_mul_io_BRESP;
input   ap_clk;
input   ap_rst_n;
output   interrupt;

wire    ap_start;
wire    ap_done;
wire    ap_idle;
wire    ap_ready;
wire   [31:0] out_r;
reg    out_r_ap_vld;
wire   [31:0] in_r;
 reg    ap_rst_n_inv;

mul_test_mul_io_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_MUL_IO_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_MUL_IO_DATA_WIDTH ))
mul_test_mul_io_s_axi_U(
    .AWVALID(s_axi_mul_io_AWVALID),
    .AWREADY(s_axi_mul_io_AWREADY),
    .AWADDR(s_axi_mul_io_AWADDR),
    .WVALID(s_axi_mul_io_WVALID),
    .WREADY(s_axi_mul_io_WREADY),
    .WDATA(s_axi_mul_io_WDATA),
    .WSTRB(s_axi_mul_io_WSTRB),
    .ARVALID(s_axi_mul_io_ARVALID),
    .ARREADY(s_axi_mul_io_ARREADY),
    .ARADDR(s_axi_mul_io_ARADDR),
    .RVALID(s_axi_mul_io_RVALID),
    .RREADY(s_axi_mul_io_RREADY),
    .RDATA(s_axi_mul_io_RDATA),
    .RRESP(s_axi_mul_io_RRESP),
    .BVALID(s_axi_mul_io_BVALID),
    .BREADY(s_axi_mul_io_BREADY),
    .BRESP(s_axi_mul_io_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .ap_start(ap_start),
    .interrupt(interrupt),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_idle(ap_idle),
    .out_r(out_r),
    .out_r_ap_vld(out_r_ap_vld),
    .in_r(in_r)
);

always @ (*) begin
    if ((ap_start == 1'b1)) begin
        out_r_ap_vld = 1'b1;
    end else begin
        out_r_ap_vld = 1'b0;
    end
end

assign ap_done = ap_start;

assign ap_idle = 1'b1;

assign ap_ready = ap_start;

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign out_r = in_r << 32'd1;

endmodule //mul_test