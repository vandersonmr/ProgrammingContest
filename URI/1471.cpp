#include <stdlib.h>
#include <stdio.h>

int main() {
  int n, r;
  while (scanf("%d %d\n", &n, &r) != EOF) {
    int mergulhadores[n];
    for (int i = 0; i < n; i++) 
      mergulhadores[i] = 0;
    for (int i = 0; i < r; i++) {
      int m;
      scanf(" %d", &m);
      mergulhadores[m-1] = 1;
    }
    bool first = true;
    for (int i = 0; i < n; i++) {
      if (mergulhadores[i] == 0) { 
        if (first) {
          printf("%d ", i+1);
          first = false;
        } else {
          printf("%d ", i+1);
        }
      }
    }
    if (first) printf("*");
    printf("\n");
  }
  return 0;
}
