#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

int main() {
  int a, b;
  while(scanf("%d %d\n", &a, &b)) {
    if (a + b == 0) break; 
    int c = -1000000000;
    int m = (c + a + b) / 3;
    if (std::min(a, b) >= m && std::max(a,b) <= m) {
       
    } 

  }

  return 0;
}
