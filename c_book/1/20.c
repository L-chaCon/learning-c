#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define TABSTOP 8

int getLine(char line[], int max);
void transformTab(char to[], char form[], int lineLen);
void copyStdout(char from[]);

int main() {
  int len;
  char line[MAXLINE]; /* current input line */
  char tline[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    transformTab(tline, line, len);
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

void transformTab(char to[], char from[], int len) {
  int i;
  int j = 0;

  for (i = 0; i < len; i++) {
    if (j >= MAXLINE - 1) {
      // Here can be some warning that the line exided we will asume that the
      // overflow is not going to afect anything in case of overflow.
      to[MAXLINE - 1] = '\0';
      return;
    }
    if (from[i] == '\t') {
      int s;
      s = TABSTOP - (j % TABSTOP);
      while (s > 0) {
        to[j] = ' ';
        ++j;
        --s;
      }
    } else {
      to[j] = from[i];
      ++j;
    }
  }
  // Add it here because len count this value
  to[j] = '\0';
}

/*
 * This is the Claude Sonnet version done after doing the excercie.
 * The column aproach makes sense. way more simple that whay I have.
 * Using `putchar()` instead of haveing to have a line in memory with the
 * `getLine()` funtion, I can just let the c lib to manage the memory.
---------------------------------------------------
int main(void) {
    int c, col;

    col = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABSTOP - (col % TABSTOP);
            for (int i = 0; i < spaces; i++) {
                putchar(' ');
            }
            col += spaces;
        } else if (c == '\n') {
            putchar(c);
            col = 0;
        } else {
            putchar(c);
            ++col;
        }
    }
    return 0;
}
*/
