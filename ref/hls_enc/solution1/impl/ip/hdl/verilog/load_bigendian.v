// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="load_bigendian,hls_ip_2017_4,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020clg484-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=0.000000,HLS_SYN_LAT=0,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=64,HLS_SYN_LUT=72}" *)

module load_bigendian (
        s_axi_BUS_A_AWVALID,
        s_axi_BUS_A_AWREADY,
        s_axi_BUS_A_AWADDR,
        s_axi_BUS_A_WVALID,
        s_axi_BUS_A_WREADY,
        s_axi_BUS_A_WDATA,
        s_axi_BUS_A_WSTRB,
        s_axi_BUS_A_ARVALID,
        s_axi_BUS_A_ARREADY,
        s_axi_BUS_A_ARADDR,
        s_axi_BUS_A_RVALID,
        s_axi_BUS_A_RREADY,
        s_axi_BUS_A_RDATA,
        s_axi_BUS_A_RRESP,
        s_axi_BUS_A_BVALID,
        s_axi_BUS_A_BREADY,
        s_axi_BUS_A_BRESP,
        ap_clk,
        ap_rst_n,
        interrupt
);

parameter    C_S_AXI_BUS_A_DATA_WIDTH = 32;
parameter    C_S_AXI_BUS_A_ADDR_WIDTH = 5;
parameter    C_S_AXI_DATA_WIDTH = 32;

parameter C_S_AXI_BUS_A_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_WSTRB_WIDTH = (32 / 8);

input   s_axi_BUS_A_AWVALID;
output   s_axi_BUS_A_AWREADY;
input  [C_S_AXI_BUS_A_ADDR_WIDTH - 1:0] s_axi_BUS_A_AWADDR;
input   s_axi_BUS_A_WVALID;
output   s_axi_BUS_A_WREADY;
input  [C_S_AXI_BUS_A_DATA_WIDTH - 1:0] s_axi_BUS_A_WDATA;
input  [C_S_AXI_BUS_A_WSTRB_WIDTH - 1:0] s_axi_BUS_A_WSTRB;
input   s_axi_BUS_A_ARVALID;
output   s_axi_BUS_A_ARREADY;
input  [C_S_AXI_BUS_A_ADDR_WIDTH - 1:0] s_axi_BUS_A_ARADDR;
output   s_axi_BUS_A_RVALID;
input   s_axi_BUS_A_RREADY;
output  [C_S_AXI_BUS_A_DATA_WIDTH - 1:0] s_axi_BUS_A_RDATA;
output  [1:0] s_axi_BUS_A_RRESP;
output   s_axi_BUS_A_BVALID;
input   s_axi_BUS_A_BREADY;
output  [1:0] s_axi_BUS_A_BRESP;
input   ap_clk;
input   ap_rst_n;
output   interrupt;

wire    ap_start;
wire    ap_done;
wire    ap_idle;
wire    ap_ready;
wire   [7:0] x;
wire   [7:0] y;
reg    ap_rst_n_inv;

load_bigendian_BUS_A_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_BUS_A_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_BUS_A_DATA_WIDTH ))
load_bigendian_BUS_A_s_axi_U(
    .AWVALID(s_axi_BUS_A_AWVALID),
    .AWREADY(s_axi_BUS_A_AWREADY),
    .AWADDR(s_axi_BUS_A_AWADDR),
    .WVALID(s_axi_BUS_A_WVALID),
    .WREADY(s_axi_BUS_A_WREADY),
    .WDATA(s_axi_BUS_A_WDATA),
    .WSTRB(s_axi_BUS_A_WSTRB),
    .ARVALID(s_axi_BUS_A_ARVALID),
    .ARREADY(s_axi_BUS_A_ARREADY),
    .ARADDR(s_axi_BUS_A_ARADDR),
    .RVALID(s_axi_BUS_A_RVALID),
    .RREADY(s_axi_BUS_A_RREADY),
    .RDATA(s_axi_BUS_A_RDATA),
    .RRESP(s_axi_BUS_A_RRESP),
    .BVALID(s_axi_BUS_A_BVALID),
    .BREADY(s_axi_BUS_A_BREADY),
    .BRESP(s_axi_BUS_A_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .ap_start(ap_start),
    .interrupt(interrupt),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_idle(ap_idle),
    .x(x),
    .y(y)
);

assign ap_done = ap_start;

assign ap_idle = 1'b1;

assign ap_ready = ap_start;

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

endmodule //load_bigendian
