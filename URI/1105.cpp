#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
  int b, n;
  while (true) {
    scanf("%d %d", &b, &n);
    if ((b + n) == 0) break;
    int saldo[b];
    for (int i = 0; i < b; i++) 
      scanf(" %d", &(saldo[i]));
    for (int i = 0; i < n; i++) {
      int d, c, v;
      scanf("%d %d %d", &d, &c, &v);
      saldo[d-1] -= v;
      saldo[c-1] += v;
    }
    bool deu = true;
    for (int i = 0; i < b; i++) { 
      if (saldo[i] < 0) {
        deu = false;
        break;
      }
    }
    if (deu) printf("S\n");
    else printf("N\n");
  }

  return 0;
}
