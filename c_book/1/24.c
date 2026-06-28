#include <stdio.h>
#include <string.h>

// Will sart this program as basic as I can. Will try to come back later

#define IN_CODE 0
#define IN_STRIN 1
#define IN_CHAR 2
#define CHECKING_START_COMMENT 3
#define CHECKING_END_COMMENT 4
#define IN_COMMENT 5

void printResults(int commentError, int charError, int stringError);

int main(void) {
  int cE, chE, sE, state, c;
  cE = chE = sE = 0;
  state = IN_CODE;

  // Actual functionality
  while ((c = getchar()) != EOF) {

    // Parentesis check

    // String check (this include escape character)

    // Character check (this include escape character)

    // Comment check
    if (state == IN_COMMENT) {
      if (c == '*') {
        state = CHECKING_END_COMMENT;
      }
    } else if (state == CHECKING_START_COMMENT) {
      if (c == '*') {
        state = IN_COMMENT;
      } else {
        // I think there is a bug if I have // here that is going to never go
        // away from starting comment so `// /*` that is not a error will
        // expect the end of the multyline comment `*/`.
        state = IN_CODE;
      }
    } else if (state == CHECKING_END_COMMENT) {
    }

    // IN code
    if (state == IN_CODE) {
      if (c == '/') {
        state = CHECKING_START_COMMENT;
      }
    }
  }

  // Just a funtion to print at the end, this is not important for this exc
  printResults(cE, chE, sE);
  return 0;
}

void printResults(int cE, int chE, int sE) {
  char cM[6], chM[6], sM[6];
  if (cE != 0) {
    strcpy(cM, "ERROR");
  } else {
    strcpy(cM, "OK");
  }
  if (chE != 0) {
    strcpy(chM, "ERROR");
  } else {
    strcpy(chM, "OK");
  }
  if (sE != 0) {
    strcpy(sM, "ERROR");
  } else {
    strcpy(sM, "OK");
  }
  printf("String Error: %s", sM);
  printf("Char Error: %s", chM);
  printf("Comment Error: %s", cM);
}
