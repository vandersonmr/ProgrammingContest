#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int sendMsg(int n, int ttl, unordered_map<int, vector<int> >& G) {
  unordered_map<int, int> level;
  for (auto IT : G) 
    level[IT.first] = -1;

  queue<int> S;
  S.push(n);
  level[n] = 0;

  int num = 0;
  while (!S.empty()) {
    int node = S.front();
    S.pop();
    num++;

    for (int i = 0; i < G[node].size(); i++) {
      if(level[G[node][i]] == -1 && level[node]+1 <= ttl) {
        S.push(G[node][i]);
        level[G[node][i]] = level[node] + 1;
      }
    }
  }

  return num;
}

int main() {
  int NC;
  int c = 0;
  while(true) {
    scanf("%d\n", &NC);
    if (NC == 0) break;

    unordered_map<int, vector<int> > G;

    for (int i = 0; i < NC; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    scanf("\n");

    while (true) {
      int n, ttl;
      scanf("%d %d", &n, &ttl);
      if (n + ttl == 0) break;

      c++;

      int visitedNodes = sendMsg(n, ttl, G);

      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
          c, (int) G.size() - visitedNodes, n, ttl);
    }
  }
  return 0;
}
