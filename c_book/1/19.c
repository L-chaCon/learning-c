#include <stdio.h>

#define MAXLINE 100

int getLine(char line[], int maxline);
void reverse(char from[], char to[], int lenght);

int main() {
  int len;
  char line[MAXLINE];
  char revLine[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    reverse(line, revLine, len);
    printf("%s", revLine);
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

void reverse(char s[], char to[], int len) {
  int i;
  i = 0;
  while (len >= 0) {
    if (s[len] != '\n' && s[len] != '\0') {
      to[i] = s[len];
      i++;
    }
    --len;
  }
  to[i] = '\n';
  i++;
  to[i] = '\0';
}
