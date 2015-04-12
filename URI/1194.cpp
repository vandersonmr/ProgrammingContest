#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void posfix(char *prefix, char *infix, int s, int e, string &res) {
  char raiz = prefix[0];

  if (raiz == '\0') return;
  int p = s;
  for (; p < e; p++) {
    if (infix[p] == raiz) break;
  }

  if (s < p) {
    posfix(prefix+1, infix, s, p, res);
  }
  if (p+1 < e) {
    posfix(prefix+(p+1 - s), infix, p+1, e, res);  
  }
  res.push_back(raiz);
  return;
}

int main() {
  int t;
  scanf("%d\n", &t);
  for (int i = 0; i < t; i++) {
    int s;
    scanf("%d", &s);
    char prefix[s];
    char infix[s];
    scanf("%s %s\n", prefix, infix);
    string res;
    posfix(prefix, infix, 0, s, res);
    printf("%s\n", res.c_str());
  }
  return 0;
}
