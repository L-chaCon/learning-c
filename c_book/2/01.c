#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  // all this information was taken from Appendix B.
  // char
  printf("CHAR_MAX: %d\n", CHAR_MAX);
  printf("CHAR_MIN: %d\n", CHAR_MIN);
  // signed char
  printf("SCHAR_MAX: %d\n", SCHAR_MAX);
  printf("SCHAR_MIN: %d\n", SCHAR_MIN);
  // un-signed char
  printf("UCHAR_MAX: %d\n", UCHAR_MAX);
  // signed int
  printf("INT_MAX: %d\n", INT_MAX);
  printf("INT_MIN: %d\n", INT_MIN);
  // un-signed int
  printf("UINT_MAX: %u\n", UINT_MAX);
  // signed short
  printf("SHRT_MAX: %d\n", SHRT_MAX);
  printf("SHRT_MIN: %d\n", SHRT_MIN);
  // un-signed short
  printf("USHRT_MAX: %d\n", USHRT_MAX);
  // signed long
  printf("LONG_MAX: %ld\n", LONG_MAX);
  printf("LONG_MIN: %ld\n", LONG_MIN);
  // un-signed long
  printf("ULONG_MAX: %lu\n", ULONG_MAX);
  printf("--------------------------\n");
  // get the values by calculation
  // int
  int c;
  unsigned int num_c = 0;
  c = ~(num_c) >> 1;
  printf("INT_MAX: %d\n", c);
  c = -c - 1;
  printf("INT_MIN: %d\n", c);
  // long
  long l;
  unsigned long num_l = 0;
  l = ~(num_l) >> 1;
  printf("LONG_MAX: %ld\n", l);
  l = -l - 1;
  printf("LONG_MIN: %ld\n", l);
  return 0;
}
