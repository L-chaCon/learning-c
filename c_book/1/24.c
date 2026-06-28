#include <stdio.h>
#include <string.h>

// Will sart this program as basic as I can. Will try to come back later

#define IN_CODE 0
#define IN_STRING 1
#define IN_CHAR 2
#define CHECKING_START_COMMENT 3
#define CHECKING_END_COMMENT 4
#define IN_MULTY_COMMENT 5
#define IN_LINE_COMMENT 6

// subStates
#define NORMAL 0
#define IN_ESC 1

void printResults(int commentError, int charError, int stringError,
                  int parenthesesError, int bracketsError, int bracesError);

int main(void) {
  int cE, chE, sE, state, c, chCount, subState, pCount, bCount, bcCount, pE, bE,
      bcE;
  cE = chE = sE = chCount = bcCount = bCount = pCount = pE = bE = bcE = 0;
  state = IN_CODE;
  subState = NORMAL;

  // Actual functionality
  while ((c = getchar()) != EOF) {

    // Parentesis check
    if (state == IN_CODE) {
      if (c == '(') {
        pCount++;
      } else if (c == ')') {
        pCount--;
      } else if (c == '[') {
        bCount++;
      } else if (c == ']') {
        bCount--;
      } else if (c == '{') {
        bcCount++;
      } else if (c == '}') {
        bcCount--;
      }
    }

    // String check (this include escape character)
    if (state == IN_STRING) {
      // This is assuming that the \ just works for one character
      if (subState == IN_ESC) {
        subState = NORMAL;
      } else if (c == '\\') {
        subState = IN_ESC;
      }

      if (c == '"' && subState != IN_ESC) {
        state = IN_CODE;
      }
    }

    // Character check (this include escape character)
    if (state == IN_CHAR) {
      if (subState == IN_ESC) {
        subState = NORMAL;
      } else if (c == '\\') {
        subState = IN_ESC;
      } else {
        ++chCount;
      }
      if (c == '\'') {
        if (chCount > 1) {
          chE = 1; // there is a error in character
        }
        state = IN_CODE;
      }
    }

    // Comment check
    if (state == IN_MULTY_COMMENT) {
      if (c == '*') {
        state = CHECKING_END_COMMENT;
      }
    } else if (state == CHECKING_START_COMMENT) {
      if (c == '*') {
        state = IN_MULTY_COMMENT;
      } else if ('/') {
        state = IN_LINE_COMMENT;
      } else {
        // I think there is a bug if I have // here that is going to never go
        // away from starting comment so `// /*` that is not a error will
        // expect the end of the multyline comment `*/`.
        state = IN_CODE;
      }
    } else if (state == CHECKING_END_COMMENT) {
      if (c == '/') {
        state = IN_CODE;
      } else {
        state = IN_MULTY_COMMENT;
      }
    } else if (state == IN_LINE_COMMENT) {
      if (c == '\n') {
        state = IN_CODE;
      }
    }

    // IN code
    if (state == IN_CODE) {
      if (c == '/') {
        state = CHECKING_START_COMMENT;
      } else if (c == '"') {
        state = IN_STRING;
      } else if (c == '\'') {
        state = IN_CHAR;
      }
    }
  }

  if (state == IN_STRING) {
    sE = 1;
  } else if (state == IN_CHAR) {
    chE = 1;
  } else if (state == IN_MULTY_COMMENT) {
    cE = 1;
  }
  if (pCount != 0) {
    pE = 1;
  }
  if (bCount != 0) {
    bE = 1;
  }
  if (bcCount != 0) {
    bcE = 1;
  }

  // Just a funtion to print at the end, this is not important for this exc
  printResults(cE, chE, sE, pE, bE, bcE);
  return 0;
}

void printResults(int cE, int chE, int sE, int pE, int bE, int bcE) {
  char cM[6], chM[6], sM[6], pM[6], bM[6], bcM[6];
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
  if (pE != 0) {
    strcpy(pM, "ERROR");
  } else {
    strcpy(pM, "OK");
  }
  if (bE != 0) {
    strcpy(bM, "ERROR");
  } else {
    strcpy(bM, "OK");
  }
  if (bcE != 0) {
    strcpy(bcM, "ERROR");
  } else {
    strcpy(bcM, "OK");
  }

  printf("Parentheses Error: %s", pM);
  printf("Brackets Error: %s", bM);
  printf("Braces Error: %s", bcM);
  printf("String Error: %s", sM);
  printf("Char Error: %s", chM);
  printf("Comment Error: %s", cM);
}
