#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>

using namespace std;

struct Vertice {
  double x, y;
  double chave;

  bool operator< (const Vertice &a) const {
    return chave < a.chave;
  }
};

double w(const Vertice &a, const Vertice &b) {
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double prim(vector<Vertice> &G) {
  double total = 0;
  while (!G.empty()) {
    sort_heap(G.begin(), G.end());
    Vertice u = G.front();
    pop_heap(G.begin(), G.end()); 
    G.pop_back();
    total += u.chave;
    for (int i = 0; i < G.size(); i++) 
      if (w(u, G[i]) < G[i].chave) 
        G[i].chave = w(u, G[i]);
  }
  return total/100;
}

int main() {
  int c;
  scanf("%d\n", &c);
  for(int k = 0; k < c; k++) {
    int n;
    scanf("%d\n", &n); 
    vector<Vertice> G;
    for (int i = 0; i < n; i++) {
      double x, y;
      scanf("%lf %lf\n", &x, &y);
      Vertice a;
      a.x = x;
      a.y = y;
      a.chave = INT_MAX;
      if (i == 0) a.chave = 0; 
      G.push_back(a);
    }
    make_heap(G.begin(), G.end());
    printf("%.2lf\n", prim(G));
  }
  return 0;
}
