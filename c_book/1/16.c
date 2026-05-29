#include <stdio.h>

#define MAXLINE 100

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len, lineLen, continuing, lineCopy;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  char candidate[MAXLINE];

  lineLen = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {
    continuing = (len == MAXLINE - 1);

    if (lineLen == 0) {
      lineLen = len;
      copy(candidate, line);
    } else {
      lineLen += len;
    }

    if (!continuing) {
      if (lineLen > max) {
        max = lineLen;
        copy(longest, candidate);
      }
      lineLen = 0;
    }
  }

  if (max > 0) {
    printf("%s", longest);
    printf("|Max Lengh: %d\n", max);
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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
