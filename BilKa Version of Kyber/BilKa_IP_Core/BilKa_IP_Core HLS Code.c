#include <stddef.h>
#include <stdint.h>


  void load_bigendian(const uint8_t *x, const uint8_t *y){
#pragma HLS INTERFACE s_axilite port = x bundle = BUS_A
#pragma HLS INTERFACE s_axilite port = y bundle = BUS_A
#pragma HLS INTERFACE s_axilite port = return bundle = BUS_A

  y =
        (uint32_t) (x[3]) \
    | (((uint32_t) (x[2])) << 8) \
    | (((uint32_t) (x[1])) << 16) \
    | (((uint32_t) (x[0])) << 24)
    ;
  }

