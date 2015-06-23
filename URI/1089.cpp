#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  while (true) {
    scanf("%d\n", &n);
    if (n == 0) break;
    int picos = 0;
    int musica[n];
    for (int i = 0; i < n; i++) {
      int a;
      scanf(" %d", &a);
      musica[i] = a;
    }
    for (int i = 0; i < n; i++) {
      int a, b, c;
      if (i == 0) {
        a = musica[n-1];
      } else {
        a = musica [i-1];
      }

      if (i == (n-1)) {
        c = musica[0];
      } else {
        c = musica[i+1];
      }

      b = musica[i];

      if ((b > a && b > c) || (b < a && b < c)) {
        picos++;
      }
    }
    printf("%d\n", picos);
  }
  return 0;
}
