#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) break;
    int j = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
      char moeda;
      scanf(" %c", &moeda);
      if (moeda == '1') j++;
      else m++;
    }
    printf("Mary won %d times and John won %d times\n", m, j);
  }
  return 0;
}
