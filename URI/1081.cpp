#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int dfsR(vector<vector<int> > &G, int v, vector<bool> &Visited, int Depth) {
  Visited[v] = true;
  sort(G[v].begin(), G[v].end());
  for (int i = 0; i < G[v].size(); i++) {
    int w = G[v].at(i); 
    for (int j = 0; j < Depth; j++)
      printf("  ");
    if (!Visited[w]) {
      printf("%d-%d pathR(G,%d)\n", v, w, w);
      dfsR(G, w, Visited, Depth+1);
    } else {
      printf("%d-%d\n", v, w);
    }
  }
}

int main() {
  int n = 0;
  scanf("%d", &n);
  for (int o = 0; o < n; o++) {
    printf("Caso %d:\n", o+1);
    int v, e;
    scanf("%d %d", &v, &e);

    vector<vector<int> > G(v);

    for (int ie = 0; ie < e; ie++) {
      int a, b;
      scanf("%d %d", &a, &b);
      G[a].push_back(b); 
    }

    vector<bool> Visited(v);

    for (int i = 0; i < v; i++) {
      if (!Visited[i]) {
        dfsR(G, i, Visited, 1);
        if (G[i].size() > 0)
          printf("\n");
      }
    }
  }

  return 0;
}
