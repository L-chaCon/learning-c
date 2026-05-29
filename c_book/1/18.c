#include <stdio.h>

#define MAXLINE 100

int getLine(char line[], int maxline);
void cleanLine(char line[], int lenght);

int main() {
  int len, newLen;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    cleanLine(line, len);
    if (line[0] != '\n')
      printf("%s", line);
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

void cleanLine(char s[], int len) {
  while (len >= 0) {
    if (s[len] == '\n') {
      while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\t')) {
        --len;
      }
      s[len] = '\n';
      s[len + 1] = '\0';
    }
    --len;
  }
}
