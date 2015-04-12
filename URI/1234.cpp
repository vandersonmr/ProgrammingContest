#include <stdio.h>

char mai(char c) {
  if(c >= 'a' && c <= 'z') 
    return (c - 'a') + 'A';
  return c;
}

char min(char c) {
  if(c <= 'Z' && c >= 'A') 
    return (c - 'A') + 'a';
  return c;
}

int main() {
  char c;
  bool up = true;
  while(scanf("%c", &c) != EOF) {
    if(c == '\n')
      up = false;
    if(c == ' ') {
      printf(" ");
      continue;
    }
    if(up) {
      printf("%c", mai(c));
      up = false;
    } else {
      printf("%c", min(c));
      up = true;
    }
  }
}
