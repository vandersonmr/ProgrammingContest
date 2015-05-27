#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>

int main() {
  int L, C, R1, R2;
  while (scanf("%d %d %d %d", &L, &C, &R1, &R2)) {
    if (L == 0 && C == 0 && R1 == 0 && R2 == 0) break;
    if (R1*2 > L || R1*2 > C || R2*2 > L || R2*2 > C) {
      printf("N\n");
      continue;
    } else {
      float d = 
        std::sqrt(std::pow(R1 - (L - R2), 2) + std::pow(R1 - (C - R2), 2));
      if (d < R1 + R2) {
        printf("N\n");
      } else {
        printf("S\n");
      }
    }
  }
  return 0;
}
