#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  while (true) {
    scanf("%d\n", &n);
    if (n == 0) break;
    int f = 0;
    for (int i = 0; i < n; i++) {
      char d;
      scanf("%c", &d);
      if (d == 'D') f++;
      else if (d == 'E') f--;
    }
    f = f%4;
    if (f == 0) printf("N\n");
    else if (f == 1 || f == -3) printf("L\n");
    else if (f == 2 || f == -2) printf("S\n");
    else if (f == 3 || f == -1) printf("O\n");
  }
  return 0;
}
