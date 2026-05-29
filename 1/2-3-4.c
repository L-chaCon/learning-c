#include <stdio.h>

void fahrCel() {
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
}

void celFahr() {
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

/*pritn Fahrenheit-Celius table
 for fahr = 0,20,...300*/
int main(void) {
  fahrCel();
  printf("-----------------\n");
  celFahr();
}
