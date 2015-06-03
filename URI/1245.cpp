#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main() {
  int n;
  while (scanf("%d\n", &n) != EOF) {
    int e[31];
    int d[31];
    for (int j = 0; j < 31; j++) {
      d[j] = 100000;
      e[j] = 100000;
    }

    for (int i = 0; i < n; i++) {
      int t; 
      char l;
      scanf("%d %c\n", &t, &l);
      if (l == 'E') { 
        if (e[t-30] > 10000) e[t-30] = 0;
        e[t-30]++;
      } else if (l == 'D') {
        if (d[t-30] > 10000) d[t-30] = 0;
        d[t-30]++;
      }
    }

    int m = 0;
    for (int j = 0; j < 31; j++) {
      if (e[j] > 10000 || d[j] > 10000) continue;
      m += std::min(e[j], d[j]);
    }
    printf("%d\n", m);
  }
}
