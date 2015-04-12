#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <stack>

#define long long int lli
using namespace std;

int dfs(int i, vector<vector<int> > &graph, vector<int> &color) {
  color[i] = 1;
  for (int j = 0; j < graph[i].size(); j++) {
    int z = graph[i][j];
    if (color[z] == 0) {
      if (dfs(z, graph, color) == 1) {
        return 1;
      }
    } else if (color[z] == 1) {
      return 1;
    }
  }
  color[i] = 2;
  return 0;
}

int main() {
  int T = 0;
  scanf("%d\n", &T);
  for (int t = 0; t < T; t++) {
    int N, M;
    scanf("%d %d\n", &N, &M);
    vector<vector<int> > graph(N+1);
    vector<int> color(N+1, 0);
    char ma[N+1][N+1];
    for (int i = 0; i < N+1; i++) {
      for (int j = 0; j < N+1; j++) {
        ma[i][j] = 0;
      }
    }
    for (int i = 0; i < M; i++) {
      int A, B;
      scanf("%d %d\n", &A, &B);
      if (A != B && ma[A][B] == 0)
        graph[A].push_back(B);
      ma[A][B] = 1;
    }

    bool c = false;
    for (int i = 0; i < N; i++) {
        if (color[i] == 2) continue;
        color[i] = 1;
        if (dfs(i, graph, color) == 1) {
          c = true;
          break;
        }        
    }
    if (c)
      printf("SIM\n");
    else 
      printf("NAO\n");
  }
  return 0;
}
