#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define TABSTOP 4

int getLine(char line[], int max);
void transformSpace(char to[], char form[], int lineLen);
void copyStdout(char from[]);

int main() {
  int len;
  char line[MAXLINE]; /* current input line */
  char tline[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    transformSpace(tline, line, len);
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

// This has a bug, the problem is for `abcde  f`
void transformSpace(char to[], char from[], int len) {
  int spaces, i, j;
  j = 0;
  spaces = 0;
  for (i = 0; i < len; i++) {
    if (from[i] == ' ') {
      spaces++;
      if (spaces > 1 && (i + 1) % TABSTOP == 0) {
        to[j] = '\t';
        spaces = 0;
        ++j;
      }
    } else {
      while (spaces > 0) {
        spaces--;
        to[j] = ' ';
        j++;
      }
      to[j] = from[i];
      j++;
    }
  }
  to[j] = '\0';
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
