#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main() {
  while (true) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
    if (x1 + x2 + y1 + y2 == 0)
      break;
    if (x1 == x2 && y1 == y2)
      printf("0\n");
    else if ((std::abs(x1 - x2) == std::abs(y1 - y2)) || (x1 == x2 || y1 == y2))
      printf("1\n");
    else
      printf("2\n");
  }
  return 0;
}
