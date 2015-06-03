#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main() {
  int n;
  int resolvido['Z' - 'A' + 1];
  int tentativas['Z' - 'A' + 1];
  while (scanf("%d\n", &n) != EOF) {
    if (n == 0) break;
    for (int i = 'A'; i <= 'Z'; i++) {
      resolvido[i - 'A'] = 0;
      tentativas[i - 'A'] = 0;
    }

    int ta = 0;
    int tt = 0;
    for (int i = 0; i < n; i++) {
      char s;
      int t;
      char a[10];
      scanf("%c %d %s\n", &s, &t, a);
      if (strcmp("correct", a) == 0 && resolvido[s-'A'] == 0) {
        ta++;
        resolvido[s-'A'] = 1;
        tt += t;
      } else {
        tentativas[s-'A'] += 1;
      }

    }
    for (int i = 'A'; i <= 'Z'; i++) {
      if (resolvido[i - 'A'] == 1) 
        tt += (tentativas[i-'A'] * 20);
    }

    printf("%d %d\n", ta, tt);
  }
  return 0;
}
