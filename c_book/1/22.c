#include <stdio.h>

#define MAXLINE 1000
#define COLUMN_LENGH 10

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
  int i, j, col;
  j++;
  col = j = 0;
  for (i = 0; i < len; i++) {
    if (col == COLUMN_LENGH) {
      to[j] = '\n';
      j++;
      col = 0;
    }
    to[j] = from[i];
    j++;
    col++;
  }
  to[j] = '\0';
}
