#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <math.h>

int Ediv(int a, int b) {
  int r = a % b;
  if (r < 0) r += abs(b);
  return (a - r) / b;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int R = Ediv(a, b);
  printf("%d %d\n", R, a-(R*b));
  return 0;
}
