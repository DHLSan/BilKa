#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "kem.h"
#include "kex.h"
#include "params.h"
#include "indcpa.h"
#include "polyvec.h"
#include "poly.h"
#include <time.h>

#define NTESTS 1000

uint64_t t[NTESTS];
uint8_t seed[KYBER_SYMBYTES] = {0};

int main()
{
  unsigned int i;
  uint8_t pk[CRYPTO_PUBLICKEYBYTES];
  uint8_t sk[CRYPTO_SECRETKEYBYTES];
  uint8_t ct[CRYPTO_CIPHERTEXTBYTES];
  uint8_t key[CRYPTO_BYTES];
  uint8_t kexsenda[KEX_AKE_SENDABYTES];
  uint8_t kexsendb[KEX_AKE_SENDBBYTES];
  uint8_t kexkey[KEX_SSBYTES];
  polyvec matrix[KYBER_K];
  poly ap;
  clock_t tStart, tEnd;
  int sec, nsec;
  double ElapsedTime = 0.0;


  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    gen_matrix(matrix, seed, 0);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("gen_a %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    poly_getnoise_eta1(&ap, seed, 0);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("poly_getnoise_eta1 %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    poly_getnoise_eta2(&ap, seed, 0);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("poly_getnoise_eta2 %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    poly_ntt(&ap);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("NTT: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    poly_invntt_tomont(&ap);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("INVNTT: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    polyvec_basemul_acc_montgomery(&ap, &matrix[0], &matrix[1]);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("polyvec_basemul_acc_montgomery: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    poly_tomsg(ct,&ap);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("poly_tomsg: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    poly_frommsg(&ap,ct);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("poly_frommsg: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    poly_compress(ct,&ap);
    tEnd = clock();;
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("poly_compress: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    poly_decompress(&ap,ct);
    tEnd = clock();
    ElapsedTime +=(double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("poly_decompress: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    polyvec_compress(ct,&matrix[0]);
    tEnd = clock();
    ElapsedTime += (double)(tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("polyvec_compress: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    polyvec_decompress(&matrix[0],ct);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("polyvec_decompress: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    indcpa_keypair(pk, sk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("indcpa_keypair: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    indcpa_enc(ct, key, pk, seed);
    tEnd = clock();
    ElapsedTime +=(double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("indcpa_enc: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    indcpa_dec(key, ct, sk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("indcpa_dec: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    crypto_kem_keypair(pk, sk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kyber_keypair: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    crypto_kem_enc(ct, key, pk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kyber_encaps: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    crypto_kem_dec(key, ct, sk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kyber_decaps: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    kex_uake_initA(kexsenda, key, sk, pk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kex_uake_initA: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    kex_uake_sharedB(kexsendb, kexkey, kexsenda, sk);
    tEnd = clock();
    ElapsedTime +=(double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kex_uake_sharedB: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    kex_uake_sharedA(kexkey, kexsendb, key, sk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kex_uake_sharedA: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    kex_ake_initA(kexsenda, key, sk, pk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kex_ake_initA: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    kex_ake_sharedB(kexsendb, kexkey, kexsenda, sk, pk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kex_ake_sharedB: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  for(i=0;i<NTESTS;i++) {
    tStart = clock();
    kex_ake_sharedA(kexkey, kexsendb, key, sk, sk);
    tEnd = clock();
    ElapsedTime += (double) (tEnd - tStart) / (CLOCKS_PER_SEC);
  }
  sec = (int)ElapsedTime;
  nsec = (int)((ElapsedTime - sec) * 1000000000);
  printf("kex_ake_sharedA: %d.%09d  seconds\n\r",sec,nsec);
  ElapsedTime = 0.0;

  return 0;
}
