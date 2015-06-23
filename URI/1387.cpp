#include <stdio.h>
#include <stdlib.h>

int main() {
  while (true) {
    int n, x;
    scanf("%d %d", &n, &x);
    if (n == 0 && x == 0) return 0;
    printf("%d\n", n+x);
  }
  return 0;
}
