#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d\n", &n);
  int la, lb;
  scanf("%d %d\n", &la, &lb);
  int za, zb;
  scanf("%d %d\n", &za, &zb);
  if (n >= la && n <= lb && n >= za && n <= zb) 
    printf("possivel\n");
  else
    printf("impossivel\n");
  return 0;
}
