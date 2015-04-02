#include <cstdio>

int main() {
  while(true) {
    int n,d;
    scanf("%d %d", &n, &d);
    if(n==0) return 0;
    int totalE = 0;
    int totalV = 0;
    for(int i=0;i < n; i++) {
      char d[100];
      int v;
      scanf("%s %d", d, &v);
      totalE += v % 3;
      totalV += v/3;
    }
    while((totalE/2) + totalV != d) {
      totalV -= 1;
      totalE += 3;
    }
    printf("%d\n",(totalE/2));
  }
  return 0;
}
