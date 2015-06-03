#include <stdio.h>
#include <stdlib.h>

int main() {
  while(true) {
    int h1, m1, h2, m2;
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    if ((h1 + m1 + h2 + m2) == 0) break;
    int t1 = h1*60 + m1;
    int t2 = h2*60 + m2;
    if (t2 < t1) t2 += 24*60;
    printf("%d\n", t2 - t1);
  }
  return 0;
}
