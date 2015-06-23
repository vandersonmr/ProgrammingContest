#include <stdio.h>
#include <stdlib.h>

char s[100000000];
int main() {
  double media;
  int i = 0;
  while (scanf("%[^\n]\n", s) != EOF) {
    i++;
    int t;
    scanf("%d", &t);
    media += t;
  }
  printf("%.1lf\n", media/i);
  return 0;
}
