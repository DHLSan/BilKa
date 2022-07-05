# BilKa Version of Kyber




# Step-by-step Building and Testing Instructions

Step 1: Installation of software tools on Ubuntu operating system (Vivado, Vitis, PetaLinux)

Step 2: Partition your SD card into two parts: BOOT and rootfs

Step 3: Installation Ubuntu operating system files to rootfs part

Step 4: Creation of PetaLinux project, designed to run the code only in pure software (only Zynq)

Step 5: Booting Bitstream and Ubuntu from SD card

Step 6: Downloading gcc compiler and required libraries with ethernet

Step 7: Running the reference code of the CRYSTALS-Kyber algorithm in the software

Step 8: Finding the slowest functions by measuring the runtimes of the functions

Step 9: Finding which functions to speed up with analysis

Step 10: Designing hardware accelerators of slowest functions using HLS

Step 11: Accelerating the Kyber algorithm with HW-SW co-design
