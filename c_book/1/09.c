#include <stdio.h>

int main(void) {
  int c, bs;
  bs = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++bs;
    } else {
      bs = 0;
    }
    if (bs < 2) {
      putchar(c);
    }
  }
  return 0;
}
