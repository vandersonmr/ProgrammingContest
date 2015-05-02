#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Rena {
  int peso, idade;
  float altura;
  char *nome;

  bool operator< (const Rena &a) const {
    if (a.peso < peso) return true;
    else if (a.peso == peso) {
      if (idade < a.idade) return true;
      else if (idade == a.idade) {
        if (altura < a.altura) return true;
        else if (altura == a.altura) {
          int i = 0;
          string sa(a.nome);
          string sb(nome);
          if (sb < sa) return true;
        }
      }
    }
    return false;
  }
};

int main() {
  int T;
  scanf("%d\n", &T);
  for (int i = 0; i < T; i++) {
    int N, M;
    scanf("%d %d\n", &N, &M);
    vector<Rena> Natal;
    for (int j = 0; j < N; j++) {
      char *nome = (char*) malloc(200);
      int p, i;
      float a;
      scanf("%s %d %d %f", nome, &p, &i, &a);
      Rena r;
      r.nome = nome;
      r.peso = p;
      r.idade = i;
      r.altura = a;
      Natal.push_back(r);
    }  
    printf("CENARIO {%d}\n", i+1);
    sort(Natal.begin(), Natal.end());
    for (int j = 0; j < M; j++)
      printf("%d - %s\n", j+1, Natal[j].nome);
  }
  return 0;
}
