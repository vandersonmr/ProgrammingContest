#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int maiorLucroGrupo(int* lDias, int nDias, int custo) {
  int lMaior = 0;
  int lAtual = 0;

  for(int i = 0; i < nDias; i++) {
    lAtual += (lDias[i] - custo);
    if(lAtual > 0) {
      if(lMaior < lAtual) 
        lMaior = lAtual;
    } else { 
      lAtual = 0;
      continue;
    }
  }

  return lMaior;
}

int main() {
  int nDias;
  while(scanf("%d\n", &nDias) != EOF) {
    int custo;
    scanf("%d", &custo);

    int lDias[nDias];
    for(int i = 0; i < nDias; i++) {
      scanf("%d\n", &lDias[i]);
    }

    printf("%d\n", maiorLucroGrupo(lDias, nDias, custo));
  }

  return 0;
}
