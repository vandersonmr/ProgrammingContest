#include <stdio.h>
#include <stdlib.h>

int main() {
  int p, n, c;
  while (true) {
    scanf("%d %d %d", &p, &n, &c);
    if ((n + p + c) == 0) break;
    int last[p];
    int sum[p];
    for (int i = 0; i < p; i++) {
      last[i] = 0;
      sum[i] = 0;
    }

    int a = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p; j++) {
        int d;
        scanf(" %d", &d);
        if (d == 1) {
          last[j] = 1;
          sum[j] += 1;
        } else {
          last[j] = 0;
          if (sum[j] >= c) a++;
          sum[j] = 0;
        }
      }
    }
    
    for (int j = 0; j < p; j++) 
      if (sum[j] >= c && last[j] == 1) a++;
    printf("%d\n", a);
  }
  return 0;
}
