#include <stdio.h>

void cDigits() {
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;

  for (i = 0; i < 10; i++) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }
  printf("digits =");
  for (i = 0; i < 10; i++) {
    printf(" %d", ndigit[i]);
  }
  printf(",white space = %d, other =%d\n", nwhite, nother);
}

#define IN 1
#define OUT 0
#define WORD_MAX_LENG 10
#define WORD_MAX_COUNT 13

void hLengthWord() {
  int c, i, j, count, state;
  int nlwords[WORD_MAX_LENG];
  for (i = 0; i < WORD_MAX_LENG; i++) {
    nlwords[i] = 0;
  }
  state = OUT;
  count = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN && count > 0) {
        ++nlwords[count - 1];
      }
      count = 0;
      state = OUT;
    } else {
      state = IN;
      ++count;
    }
  }

  // Printing functionality
  printf("\n");
  printf("Word lenght histogram:\n");
  printf("    ");
  for (i = 0; i < WORD_MAX_COUNT; i++) {
    printf(" %2d", i + 1);
  }
  printf("\n");
  printf("    ");
  for (i = 0; i < WORD_MAX_COUNT; i++) {
    printf("---");
  }
  printf("\n");
  for (i = 0; i < WORD_MAX_LENG; i++) {
    printf("%2dn|", i + 1);
    for (j = 0; j < nlwords[i]; j++) {
      printf("000");
    }
    printf("\n");
  }
}

#define AMOUNT_OF_CHARACTERS 26
#define MAX_COUNT 30

void hCharCount() {
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
}
int main() { hCharCount(); }
