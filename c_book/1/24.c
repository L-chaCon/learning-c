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

  for (;;) {
    c = getchar();
    if (c == EOF) {
      break;
    }

    // The brakets check don't chamge status, so will just do this at the start
    // of the iteration, and then I can forget about it until the end.
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
      // Will do the in code as a higer level state.
      if (c == '/') {
        state = CHECKING_START_COMMENT;
      } else if (c == '"') {
        state = IN_STRING;
      } else if (c == '\'') {
        state = IN_CHAR;
      }
    } else {
      // String check (this include escape character)
      if (state == IN_STRING) {
        // This is assuming that the \ just works for one character
        if (c == '"' && subState != IN_ESC) {
          state = IN_CODE;
        }
        if (subState == IN_ESC) {
          subState = NORMAL;
        } else if (c == '\\') {
          subState = IN_ESC;
        }
      } // Character check (this include escape character)
      else if (state == IN_CHAR) {
        if (subState == IN_ESC) {
          subState = NORMAL;
          ++chCount;
        } else if (c == '\\') {
          subState = IN_ESC;
        } else if (c == '\'') {
          if (chCount > 1)
            chE = 1;
          state = IN_CODE;
          chCount = 0;
        } else {
          ++chCount;
        }
      } // Comment check
      else if (state == IN_MULTY_COMMENT) {
        if (c == '*') {
          state = CHECKING_END_COMMENT;
        }
      } // Check if we are entering a comment
      else if (state == CHECKING_START_COMMENT) {
        if (c == '*') {
          state = IN_MULTY_COMMENT;
        } else if (c == '/') {
          state = IN_LINE_COMMENT;
        } else {
          // I think there is a bug if I have // here that is going to never go
          // away from starting comment so `// /*` that is not a error will
          // expect the end of the multyline comment `*/`.
          state = IN_CODE;
        }
      } // Check if we are exiting a comment
      else if (state == CHECKING_END_COMMENT) {
        if (c == '/') {
          state = IN_CODE;
        } else {
          state = IN_MULTY_COMMENT;
        }
      } // Checking if we are closing the inline comment
      else if (state == IN_LINE_COMMENT) {
        if (c == '\n') {
          state = IN_CODE;
        }
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

/*
 * K&R Exercise 1-24 - rudimentary syntax checker (reference version).
 *
 * Reads a C program on stdin and reports unbalanced () [] {},
 * unterminated string and character literals, and unterminated
 * block comments.
 *
 * Character-level state machine: one getchar, one transition.
 * Brackets are counted only in CODE, so any delimiter inside a
 * string, char constant or comment is ignored automatically.

enum state {
    CODE,           // ordinary program text
    STRING,         // inside a double-quoted string literal
    CHARCONST,      // inside a single-quoted character constant
    SLASH,          // just saw a slash, deciding if a comment opens
    LINE_COMMENT,   // inside a line comment, up to end of line
    BLOCK_COMMENT,  // inside a block comment
    BLOCK_STAR      // inside a block comment, just saw a star
};

int main(void)
{
    int  c;
    enum state st = CODE;
    int  escaped = 0;               // prev char in string/char was a backslash
    long line = 1;
    long paren = 0, brack = 0, brace = 0;
    long str_line = 0, chr_line = 0, com_line = 0;
    int  err = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            line++;
reprocess:
        switch (st) {
        case CODE:
            switch (c) {
            case '(':  paren++;                          break;
            case ')':  paren--;                          break;
            case '[':  brack++;                          break;
            case ']':  brack--;                          break;
            case '{':  brace++;                          break;
            case '}':  brace--;                          break;
            case '"':  st = STRING;    str_line = line;  break;
            case '\'': st = CHARCONST; chr_line = line;  break;
            case '/':  st = SLASH;                       break;
            }
            break;

        case SLASH:
            if (c == '*') {
                st = BLOCK_COMMENT;
                com_line = line;
            } else if (c == '/') {
                st = LINE_COMMENT;
            } else {
                st = CODE;
                goto reprocess;   // re-evaluate c in CODE state
}
break;

case LINE_COMMENT:
if (c == '\n')
  st = CODE;
break;

case BLOCK_COMMENT:
if (c == '*')
  st = BLOCK_STAR;
break;

case BLOCK_STAR:
if (c == '/')
  st = CODE;
else if (c != '*')
  st = BLOCK_COMMENT;
//stay in BLOCK_STAR if next char is also '*'
break;

case STRING:
if (escaped) {
  escaped = 0;
} else if (c == '\\') {
  escaped = 1;
} else if (c == '"') {
  st = CODE;
}
break;

case CHARCONST:
if (escaped) {
  escaped = 0;
} else if (c == '\\') {
  escaped = 1;
} else if (c == '\'') {
  st = CODE;
}
break;
}
}

// check for unterminated constructs
if (st == STRING) {
  printf("ERROR: unterminated string at line %ld\n", str_line);
  err = 1;
}
if (st == CHARCONST) {
  printf("ERROR: unterminated char constant at line %ld\n", chr_line);
  err = 1;
}
if (st == BLOCK_COMMENT || st == BLOCK_STAR) {
  printf("ERROR: unterminated comment starting at line %ld\n", com_line);
  err = 1;
}
if (paren != 0) {
  printf("ERROR: unbalanced ()\n");
  err = 1;
}
if (brack != 0) {
  printf("ERROR: unbalanced []\n");
  err = 1;
}
if (brace != 0) {
  printf("ERROR: unbalanced {}\n");
  err = 1;
}
if (!err)
  printf("OK\n");

return err;
}
*/
