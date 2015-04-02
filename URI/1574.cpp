#include <stdio.h>
#include <cmath>

int main() {
  while(true) {
    char a[10];
    char b[10];

    scanf("%s %s", a, b);
    
    if(a[0] == '0' && b[0] == '0') 
      break;

    int res = rec(a, b, 0, 0, false);

    if(res == 0) {
      printf("No carry operation.\n");
    } else if(res == 1) {
      printf("%d carry operation.\n", res);
    } else {
      printf("%d carry operations.\n", res);
    }
  }
  return 0;
}

int rec(char *a, char *b, int i, int res, bool has) {
  if(!(i < 10 && b[i] != '\0' && a[i] != '\0')) 
    return res;

  if ((b[i] - 48) + (a[i] - 48) >= 10) {
    return rec(a, b, ++i, res, true) + 1;
  }

  return rec(a, b, ++i, res, false);
}


