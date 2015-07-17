#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>

using namespace std;

struct Vertice {
  double x, y;
};

double w(const Vertice &a, const Vertice &b) {
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

#define INF 9999999

int main() {
  int c;
  scanf("%d\n", &c);
  for(int k = 0; k < c; k++) {
    int n;
    scanf("%d\n", &n); 
    vector<Vertice> G;
    double weight[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
      Vertice a;
      scanf("%lf %lf\n", &a.x, &a.y);
      weight[i] = INF;
      visited[i] = false;
      G.push_back(a);
    }
    
    weight[0] = 0;

    double T = 0;
    for (int t = 0; t < n; t++) {
      int i = 0;
      double min = INF;
      for (int u = 0; u < n; u++) {
        if (!visited[u] && weight[u] < min) {
          min = weight[u];
          i = u;
        }
      }
      visited[i] = true;
      T += min;
      for (int u = 0; u < n; u++) {
        if (!visited[u]) {
          double d = w(G[i], G[u]);
          if (d < weight[u]) weight[u] = d;
        }
      }
    }
    printf("%.2lf\n", T/100);
  }
  return 0;
}
