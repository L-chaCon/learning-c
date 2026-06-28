#include <stdio.h>

#define TABSTOP 4

int main() {
  int c, col, spaces;

  col = 0;
  spaces = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      while (spaces > 0) {
        putchar(' ');
        spaces--;
      }
      putchar(c);
      col = 0;
    } else if (c == '\t') {
      putchar(c);
      col += TABSTOP - (col % TABSTOP);
    } else if (c == ' ') {
      spaces++;
      ++col;
      if (col % TABSTOP == 0) {
        putchar('\t');
        spaces = 0;
      }
    } else {
      while (spaces > 0) {
        putchar(' ');
        spaces--;
      }
      putchar(c);
      col++;
    }
  }
  return 0;
}

/*
 * I need to use more the concept of a column, I'm not using that at all
---------------------------------------------------
int main(void) {
  int c, col, spaces;

  col = 0;
  spaces = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++spaces;
      ++col;
      if (col % TABSTOP == 0) {
        putchar('\t');
        spaces = 0;
      }
    } else {
      for (int i = 0; i < spaces; i++) {
        putchar(' ');
      }
      spaces = 0;
      if (c == '\n') {
        putchar(c);
        col = 0;
      } else if (c == '\t') {
        putchar(c);
        col += TABSTOP - (col % TABSTOP);
      } else {
        putchar(c);
        ++col;
      }
    }
  }
  return 0;
}
*/
