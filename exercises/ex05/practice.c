#include <stdio.h>
#include <stdlib.h>
#define BYTE_TO_BINARY_PATTERN "%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x8000000 ? '1' : '0'), \
  (byte & 0x4000000 ? '1' : '0'), \
  (byte & 0x2000000 ? '1' : '0'), \
  (byte & 0x1000000 ? '1' : '0'), \
  (byte & 0x0800000 ? '1' : '0'), \
  (byte & 0x0400000 ? '1' : '0'), \
  (byte & 0x0200000 ? '1' : '0'), \
  (byte & 0x0100000 ? '1' : '0'), \
  (byte & 0x80000 ? '1' : '0'), \
  (byte & 0x40000 ? '1' : '0'), \
  (byte & 0x20000 ? '1' : '0'), \
  (byte & 0x10000 ? '1' : '0'), \
  (byte & 0x08000 ? '1' : '0'), \
  (byte & 0x04000 ? '1' : '0'), \
  (byte & 0x02000 ? '1' : '0'), \
  (byte & 0x01000 ? '1' : '0'), \
  (byte & 0x8000 ? '1' : '0'), \
  (byte & 0x4000 ? '1' : '0'), \
  (byte & 0x2000 ? '1' : '0'), \
  (byte & 0x1000 ? '1' : '0'), \
  (byte & 0x0800 ? '1' : '0'), \
  (byte & 0x0400 ? '1' : '0'), \
  (byte & 0x0200 ? '1' : '0'), \
  (byte & 0x0100 ? '1' : '0'), \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')


union {
  float f;
  u_int32_t i;
}b;


void printb (byte){
  printf(BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(byte));
}


u_int32_t get_exponent(float x){
  b.f = x;
  u_int32_t mask = 0xff;
  u_int32_t expon = (b.i >> 23) & mask;
  return expon;
}



float div_by_pow_2(float x, int n){
  // First exponent, second is int n
  b.f = x;
  printb(b.i);

  u_int32_t u = get_exponent(x);
  b.i = b.i << 9;

  b.i = b.i >> 9;

  u_int32_t y = u-n;
  printf("\n");

  printb(b.i | (y<<23));
  b.i = b.i | (y<<23);
  return b.f;
 // printb(n);
 // printb(y);
 // b.f = x;
 // u_int32_t z = b.i << 8; // (y << 23) | b.i;
 // u_int32_t a = b.i >> 8;
 // printb(a);
 // printf("%i\n", y);
 // printf("%d\n", z);
 // printf("%d\n", a);


}

u_int8_t flip_nybble( u_int8_t input){
  u_int8_t nybble1 = input & 0x0f;
  u_int8_t nybble2 = input & 0xf0;
  return (nybble1 << 4) | (nybble2 >> 4);
}
int main (){

  float f = 4;
  u_int8_t n = 0xcb;
  // printf("%f\n",div_by_pow_2(f,n));
  printf("%x",flip_nybble(n));



  // printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(f);
  // printf("%i\n", get_exponent(f)-127);
  // printf("%i\n", get_exponent(2)-127);
  // printf("%i\n", get_exponent(4)-127);
  // printf("%i\n", get_exponent(8)-127);
  // printf("%i\n", get_exponent(16)-127);
  // printf("%i\n", get_exponent(32)-127);
  // printf("%i\n", get_exponent(64)-127);
  // printf("%i\n", get_exponent(128)-127);
  // printf("%i\n", get_exponent(256)-127);
  // printf("%i\n", get_exponent(512)-127);
  // printf("%i\n", get_exponent(1024)-127);
  // printf("%i\n", get_exponent(2048)-127);
  // printf("%i\n", get_exponent(4096)-127);
  // printf("%f\n",div_by_pow_2(f,n));
}
