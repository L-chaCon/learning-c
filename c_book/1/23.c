#include <stdio.h>

int main() {
  int c, write, checking, cLine, cMulty, checking2;
  write = 1;
  checking = checking2 = cLine = cMulty = 0;
  while ((c = getchar()) != EOF) {
    if (cLine) {
      if (c == '\n') {
        write = 1;
        cLine = 0;
      }
    }
    if (cMulty) {
      if (checking2) {
        if (c == '/') {
          write = 1;
        } else {
          checking2 = 0;
        }
      }
      if (c == '*') {
        checking2 = 1;
      }
    }
    if (checking) {
    }
    if (c == '/') {
      if (checking) {
        cLine = 1;
        checking = 0;
      }
    } else {
      checking = 1;
      write = 0;
    }
    if (write) {
      if (cMulty) {
        cMulty = 0;
      } else {
        putchar(c);
      }
    }
  }
}
