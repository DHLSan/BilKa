# BilKa
BilKa: Design and Implement an SoC Architecture with a CRYSTALS-Kyber Accelerator

Team Number: xohw22-108

This project was carried out within the scope of the EEM464 course at the Department of Electrical and Electronics Engineering at Eskişehir Technical University.

Board used in the project: ZedBoard
# Project Description
  In the world, which has entered a new era with the effect of the increasing digitalization process in recent years, using of more complex System-on-Chips (SoC) has become widesp-read in order to keep up with the speed of technological developments. Also, the importance of data has increased with era of digitalization, the volume of data has grown and the data increase rate has been affected by these technologi-cal developments. Thus, it has become a requirement to securely store increasing importance and number of the data. The most widely used method of securely storing the data is encryption. Since the algorithms used for encryption operation at the present time involve complex and intensive arithmetic calculations, they consume a significant amount of time on the standard processors. Therefore, the slow encryption operation needs to be accelerated by developing a SoC architecture in order to keep up with the speed of the changing world. 
  For many centuries, the desire of human beings to protect confidentiality during the transmission and storage of the data has led to the emergence of the cryptography. The main developments in the field of the cryptography date back to the 20th century, when supercomputers were invented. In that period, quantum cryptography based on public-key encryption was developed, involving difficult mathematical problems that would consume a lot of resources and time to compute the solution and break the system in classical com-puters. However, the security of public-key system data encryption used nowadays will be greatly compromised if large-scale quantum computers are built. Accordingly, Nati-onal Institute of Standards and Technology (NIST) initiated a standardization process to develop post-quantum cryptog-raphic systems that are secure against both quantum and classical computers and can interoperate with existing com-munication protocols and networks in 2017. 
  Designing a whole complex-system on a single chip is very efficient in terms of power and performance. Thanks to ever increasing size of transistors on a single-die silicon chip, a very complex system can be synthesized into a single silicon device. As the size of the system is increasing, the data bandwidth of such systems reaches very high levels. Data security is of utmost importance and designing high-throughput encryption/decryption hardware IP cores to provide data security is a challenging task especially at RTL-level. Conventional cryptographic systems provide security at very high frequency, but some of asymmetric cryptograp-hic algorithms might be broken with quantum computing. Quantum-processor based systems may become available in near future and solve some conventially secure systems. Thus, designing a secure system from attacks using quantum computers is a challenging research topic. Hardware accele-ration of the computation of quantum-secure algorithms on a conventional computing device is needed to reach higher-bandwidth and quantum-level security and the design space is huge.
  In this project, we aim to accelerate the CRYSTALS-Kyber algorithm, which is currently one of the finalists in the third round of the Post-Quantum Cryptography competition initi-ated by NIST, with an HW/SW codesign methodology and application-specific hardware accelerators by using High-Level Synthesis (HLS). In the study of Dang et al. [1], it was concluded that the hardware architecture of CRYSTAL-Kyber algorithm runs better than other finalist algorithms at higher security levels (e.g., Level 3 and Level 5) in Artix-7 FPGAs and Zynq Ultrascale+ devices. Since the information in security level 3 and 5 categories contain risky social, psyc-hological and financial information that can harm individu-als or groups if disclosed, it is a basic requirement that these data be stored securely. We aim to hardware accelerate of the CRYSTAL-Kyber algorithm using HLS to ensure the security of applications with high security level requirements with low latency and explore the design space faster thanks to higher design productivity of HLS.
# Participants
  - Bilge Deniz ÖZÇELİK
Contact: bilgedenizozcelik@eskisehir.edu.tr
  - Selahattin Kaan TOSUN
Contact: selahattinkaantosun@eskisehir.edu.tr
# Supervisor
   Assist. Prof. Dr. İsmail San
Contact: isan@eskisehir.edu.tr
# Platform and Tools
Ubuntu 18.04 LTS Operating System
Xilinx Vivado 2019.2 Design Suite
Xilinx Vitis High-Level Synthesis 2019.2
Xilinx Vitis 2019.2
Xilinx PetaLinux 2019.2
SD Card for Booting Ubuntu on ZedBoard
