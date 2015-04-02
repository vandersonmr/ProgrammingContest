#include <stdio.h>
#include <stdlib.h>

int main() {
  int k = 0;
  while (true) {
    scanf("%d", &k);
    if (k == 0) return 0;
    int n, m = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < k; i++) {
      int x, y = 0;
      scanf("%d %d", &x, &y);
      if (x == n || y == m) {
        printf("divisa\n");
      } else {

        if (y > m) {
          printf("N");
        } else {
          printf("S");
        }

        if (x > n) {
          printf("E\n");
        } else {
          printf("O\n");
        }
      }
    }
  }
  return 0;
}
