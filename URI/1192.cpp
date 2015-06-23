#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    char n1, op, n2;
    scanf("%c%c%c\n", &n1, &op, &n2);
    if (n1 != n2) {
      if (op <= 90) printf("%d\n", (n2-'0') - (n1-'0'));
      else printf("%d\n", (n2-'0') + (n1-'0'));
    } else {
      printf("%d\n", (n2-'0') * (n1-'0'));
    }
  }
  return 0;
}

