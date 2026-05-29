#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, steps;
  lower = 0;   /* lower limit of tempeture table */
  upper = 100; /* upper limit */
  steps = 10;  /* step size */

  celsius = lower;
  printf("Cel|Fah\n");
  while (celsius <= upper) {
    fahr = (celsius * (9.0 / 5.0)) + 32.0;
    printf("%3.0f%6.1f\n", celsius, fahr);
    celsius = celsius + steps;
  }
}
