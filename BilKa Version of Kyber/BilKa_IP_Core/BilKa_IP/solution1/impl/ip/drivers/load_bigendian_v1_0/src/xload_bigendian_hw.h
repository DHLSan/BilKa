// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

// BUS_A
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/SC)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        others - reserved
// 0x10 : Data signal of x
//        bit 7~0 - x[7:0] (Read/Write)
//        others  - reserved
// 0x14 : reserved
// 0x18 : Data signal of y
//        bit 7~0 - y[7:0] (Read/Write)
//        others  - reserved
// 0x1c : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XLOAD_BIGENDIAN_BUS_A_ADDR_AP_CTRL 0x00
#define XLOAD_BIGENDIAN_BUS_A_ADDR_GIE     0x04
#define XLOAD_BIGENDIAN_BUS_A_ADDR_IER     0x08
#define XLOAD_BIGENDIAN_BUS_A_ADDR_ISR     0x0c
#define XLOAD_BIGENDIAN_BUS_A_ADDR_X_DATA  0x10
#define XLOAD_BIGENDIAN_BUS_A_BITS_X_DATA  8
#define XLOAD_BIGENDIAN_BUS_A_ADDR_Y_DATA  0x18
#define XLOAD_BIGENDIAN_BUS_A_BITS_Y_DATA  8

