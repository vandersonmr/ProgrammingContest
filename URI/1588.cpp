#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

struct Time {
  int pontos;
  int vitorias;
  int gols;
  char *nome;

  bool operator< (const Time &a) const {
    if (a.pontos < pontos) return true;
    else if (a.vitorias < vitorias) return true;
    else if (a.gols < gols) return true;
    return false;
  }
};

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Time> campeonato;
    unordered_map<string, Time*> pog;
    for (int j = 0; j < n; j++) {
      char *n = (char*) malloc(110);
      scanf("%s", n);
      Time *t = new Time;
      t->nome = n;
      pog[string(n)] = t;
    }
    for (int j = 0; j < m; j++) {
      char *a = (char*) malloc(110);
      char *b = (char*) malloc(110); 
      int gola, golb;
      scanf("%d %s %d %s", &gola, a, &golb, b);
      pog[string(a)]->gols += gola;
      pog[string(b)]->gols += golb;
      if (gola == golb) {
        pog[string(a)]->pontos += 1;
        pog[string(b)]->pontos += 1;
      } else if (gola < golb) {
        pog[string(b)]->pontos += 3;
        pog[string(b)]->vitorias += 1;
      } else {
        pog[string(a)]->pontos += 3;
        pog[string(a)]->vitorias += 1;
      }
    }
    for (auto &j : pog) 
      campeonato.push_back(*j.second);
    sort(campeonato.begin(), campeonato.end());
    for (auto j : campeonato) 
      printf("%s\n", j.nome);
  }
  return 0;
}
