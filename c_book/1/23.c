#include <stdio.h>

#define OUT 0
#define CHECKING_START 1
#define CHECKING_END 2
#define LINE_COMMENT 3
#define MULTY_COMMENT 4

int main() {
  int s, c;
  s = OUT;
  while ((c = getchar()) != EOF) {
    if (s == CHECKING_START) {
      if (c == '/') {
        s = LINE_COMMENT;
      } else if (c == '*') {
        s = MULTY_COMMENT;
      } else {
        putchar('/');
        s = OUT;
      }
    } else if (s == OUT) {
      if (c == '/') {
        s = CHECKING_START;
      } else {
        putchar(c);
      }
    } else if (s == LINE_COMMENT) {
      if (c == '\n') {
        s = OUT;
      }
    } else if (s == CHECKING_END) {
      if (c == '/') {
        s = OUT;
      }
    } else if (s == MULTY_COMMENT) {
      if (c == '*') {
        s = CHECKING_END;
      }
    }
  }
}
