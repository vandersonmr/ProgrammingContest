#include <cstdio>

int solve(int d) {
  int total = 0;
  for(int i = d; i >= 1; i--) {
    total += i*i;
  }
  return total;
}

int main() {
  while(true) {
    int d;
    scanf("%d", &d);
    if(d == 0) break;
    printf("%d\n", solve(d));
  }
  return 0;
}
