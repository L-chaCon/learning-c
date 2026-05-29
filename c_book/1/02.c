#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, steps;
  lower = 0;   /* lower limit of tempeture table */
  upper = 300; /* upper limit */
  steps = 20;  /* step size */

  fahr = lower;
  printf("Fah|Cel\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f%6.1f\n", fahr, celsius);
    fahr = fahr + steps;
  }
  return 0;
}
