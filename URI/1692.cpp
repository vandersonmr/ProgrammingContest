#include <stdlib.h>
#include <stdio.h>

#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
  int n, k;
  while(scanf("%d %d", &n, &k) != EOF) {
    vector<vector<int> > G(n+1);

    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }

    bool revenged = false;
    long unsigned max = 0;
    for (int h = 1; h <= n; h++) {
      unordered_map<int, bool> onTheList;
      onTheList[h] = true;
      bool first = true;
      for (int f = 0; f <= n; f++) {
        int i = 0;
        if (first) i = h; 
        else i = f;
        if (onTheList.count(i) != 0) {
          vector<bool> visited(n+1, false);
          vector<int> Dist(n+1); 
          list<int> queue; 
          queue.push_back(i);
          Dist[i] = 0;
          while(!queue.empty()) {
            int p = queue.front();
            queue.pop_front();

            for (int j = 0; j < G[p].size(); j++) {
              if (visited[G[p].at(j)]) continue;
              visited[G[p].at(j)] = true;
              Dist[G[p].at(j)] = Dist[p] + 1;
              if (Dist[G[p].at(j)] == k) revenged = true;
              if (Dist[G[p].at(j)] <= k && (onTheList.count(G[p].at(j)) != 0 || first)) {
                queue.push_back(G[p].at(j));
                onTheList[G[p].at(j)] = true;
              } else {
                onTheList.erase(G[p].at(j));
              }
            }
          }
          first = false;
        }
      }
      if (onTheList.size() > max) max = onTheList.size();  
    }
    if (!revenged) printf("Impossible revenge!\n");
    else printf("%lu\n", max);
  }
  return 0;
}
