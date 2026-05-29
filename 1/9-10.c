#include <stdio.h>

void rDScpaces(void) {
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
}

void rawCopy(void) {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      putchar('\\');
      putchar('n');
      putchar('\n');
    } else if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else {
      putchar(c);
    }
  }
}

int main(void) { rawCopy(); }
