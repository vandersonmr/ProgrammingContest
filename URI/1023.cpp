#include <cstdio>
#include <utility>
#include <iostream>
#include <map>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Cidade {
  public:
    int n;
    int totalPessoas;
    int soma;
    map<int, int> v;
}; 

int main() {
  int p = 0;
  while(true) {
    Cidade c;
    c.v.clear();
    int n;
    scanf("%d", &n);
    if(n == 0) break;
    if(p) printf("\n");
    p++;

    c.soma = 0;
    c.totalPessoas = 0;
    c.n = p;

    int a,b;
    for(int i=0;i < n; i++){
      scanf("%d %d", &a, &b);
      c.soma += b;
      c.totalPessoas += a;
      c.v[b/a] += a;
    }

    printf("Cidade# %d:\n", c.n);

    auto t = c.v.begin();
    printf("%d-%d", t->second, t->first);

    for(++t; t != c.v.end(); ++t) 
      printf(" %d-%d", t->second, t->first);

    double media = floor(100.0 * c.soma / c.totalPessoas) / 100;

    printf("\nConsumo medio: %.2lf m3.\n", media);
  }
  return 0;
}
