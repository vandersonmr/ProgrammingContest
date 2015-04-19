#include <stdlib.h>
#include <stdio.h>

#define PESO 50

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int knapsac(int n, int *qt, int *p) {
  int m[n+1][PESO+1], i, j;
  for (i = 0; i < PESO+1; i++)
    m[0][i] = 0;
  for (i = 0; i < n+1; i++)
    m[i][0] = 0;

  for (i = 1; i <= n; i++) {
    for (j = 0; j <= PESO; j++) {
      if (p[i] > j)
        m[i][j] = max(m[i-1][j], m[i-1][j-p[i]] + qt[i]);
      else
        m[i][j] = m[i-1][j];
    }
  }

  return m[n][PESO];
}

int main() {
  int test;
  scanf("%d", &test);

  while (test > 0) {
    int pac, i;
    scanf("%d", &pac);
    
    int qt[pac+1], p[pac+1];
    qt[0] = 0;
    p[0] = 0;
    for (i = 1; i < pac; i++)
      scanf("%d %d", &qt[i], &p[i]);


    test--;
  }

}
