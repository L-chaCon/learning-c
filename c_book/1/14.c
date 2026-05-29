#include <stdio.h>

#define AMOUNT_OF_CHARACTERS 26
#define MAX_COUNT 30

int main() {
  int c, i, j, count, state;
  int nchar[AMOUNT_OF_CHARACTERS];
  for (i = 0; i < AMOUNT_OF_CHARACTERS; i++) {
    nchar[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      //
    } else if (c >= 'a' && c <= 'z') {
      ++nchar[c - 'a'];
    }
  }

  // Printing functionality
  printf("\n");
  printf("Character count histogram:\n");
  printf("    ");
  for (i = 0; i < MAX_COUNT; i++) {
    printf(" %2d", i + 1);
  }
  printf("\n");
  printf("    ");
  for (i = 0; i < MAX_COUNT; i++) {
    printf("---");
  }
  printf("\n");
  for (i = 0; i < AMOUNT_OF_CHARACTERS; i++) {
    printf("%c|", i + 'a');
    for (j = 0; j < nchar[i]; j++) {
      printf("000");
    }
    printf("\n");
  }
  return 0;
}
