#include <stdio.h>

int main(void) {
  int c, nl, bl, tl;
  nl = 0;
  bl = 0;
  tl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n') {
      ++nl;
    } else if (c == '\t') {
      ++tl;
    } else if (c == ' ') {
      ++bl;
    }
  printf("New Lines: %d\nTabs: %d\nBlank: %d\n", nl, tl, bl);
}
