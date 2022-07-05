# Hardware Accelerator of Kyber

Slow-running functions were found in the Kyber algorithm with the analyzes obtained as a result of the profiling. Therefore, we predict that the Kyber algorithm will be 
accelerated thanks to the hardware design of the function with the most used operations in slow-running functions. We used Xilinx Vitis High-Level Synthesis 2019.2 to 
create the hardware design. Here you can find the C code we wrote to create hardware design in HLS and the custom SoC accelerator module we designed.

![image](https://user-images.githubusercontent.com/90928820/177389937-902e92fc-3edc-4d1d-a7f0-afd6eacab4bd.png)
                                                   Figure. Hardware Design of Kyber
