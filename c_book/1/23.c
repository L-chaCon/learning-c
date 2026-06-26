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
    // start with checking start becasue if I do after is going to enter every
    // time the character is '/'
    if (s == CHECKING_START) {
      if (c == '/') {
        s = LINE_COMMENT;
      } else if (c == '*') {
        s = MULTY_COMMENT;
      } else {
        putchar('/');
        s = OUT;
      }
    }
    if (s == OUT && c == '/') {
      s = CHECKING_START;
    }
    // Will deside that in case a comment with line is remove a \n will still
    // stay there, this is for cases like some code like thie `s=0 //comment`
    if (s == LINE_COMMENT && c == '\n') {
      s = OUT;
    }
    if (s == OUT) {
      putchar(c);
    }
    // This needs to go after the out because I want to insert the character
    // after the end, not the end one
    if (s == CHECKING_END && c == '/') {
      s = OUT;
    }
    if (s == MULTY_COMMENT && c == '*') {
      s = CHECKING_END;
    }
  }
}
