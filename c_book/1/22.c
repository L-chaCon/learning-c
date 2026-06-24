#include <stdio.h>

#define MAXLINE 1000
#define COLUMN_LENGH 10
#define TABSTOP 4

int getLine(char line[], int max);
void wrapLine(char from[], char to[], int length);
void copyStdout(char from[]);

int main() {
  int len;
  char line[MAXLINE]; /* current input line */
  char tline[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    wrapLine(line, tline, len);
    copyStdout(tline);
  }
  return 0;
}

int getLine(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

void copyStdout(char from[]) {
  int i;
  i = 0;
  while (from[i] != '\0') {
    putchar(from[i]);
    ++i;
  }
}

void wrapLine(char from[], char to[], int len) {
  int i, j, col, lastSpace;
  col = j = lastSpace = 0;
  for (i = 0; i < len; i++) {
    if (from[i] == ' ') {
      if (col == COLUMN_LENGH) {
        to[j] = '\n';
        j++;
        col = 0;
      } else {
        to[j] = from[i];
        lastSpace = j;
        j++;
        col++;
      }
    } else if (from[i] == '\n') {
      to[j] = from[i];
      j++;
      col = 0;
    } else if (from[i] == '\t') {
      if ((col + TABSTOP) >= COLUMN_LENGH) {
        to[j] = '\n';
        j++;
        col = 0;
      } else {
        int spaces = TABSTOP - (col % TABSTOP);
        while (spaces > 0) {
          to[j] = ' ';
          j++;
          spaces--;
          col++;
        }
      }
    } else {
      if (col == COLUMN_LENGH) {
        to[lastSpace] = '\n';
        col = j - lastSpace - 1;
      }
      to[j] = from[i];
      j++;
      col++;
    }
  }
  to[j] = '\0';
}

/*
#include <stdio.h>

#define MAXCOL  10
#define MAXWORD 1000

int main(void)
{
    int  c, col, wordlen, i;
    char word[MAXWORD];

    col     = 0;
    wordlen = 0;

    for (;;) {
        c = getchar();

        if (c == ' ' || c == '\n' || c == EOF) {

            // word is complete — decide where it goes
            if (wordlen > 0) {
                if (col > 0 && col + 1 + wordlen > MAXCOL) {
                    putchar('\n');
                    col = 0;
                }
                if (col > 0) {
                    putchar(' ');
                    col++;
                }
                for (i = 0; i < wordlen; i++)
                    putchar(word[i]);
                col    += wordlen;
                wordlen = 0;
            }

            if (c == '\n') { putchar('\n'); col = 0; }
            if (c == EOF)  break;

        } else {
            if (wordlen < MAXWORD - 1)
                word[wordlen++] = c;
        }
    }

    return 0;
}
*/
