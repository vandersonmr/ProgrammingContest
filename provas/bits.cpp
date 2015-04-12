#include <stdio.h>

int main() {
  int n;
  int i = 1;
  while(true) {
    scanf("%d", &n);
    if(n == 0) break;
    printf("Teste %d\n", i);
    printf("%d %d %d %d\n\n", (n/50), ((n%50)/10), (((n%50)%10)/5), (((n%50)%10))%5);
    i++;
  }
  return 0;
}
