#include <stdio.h>
#include <stdlib.h>

#include <list>
#include <algorithm>

using namespace std;

#define MAX 50000

class UnionFind {
  public:
    int id[MAX], sz[MAX];
    UnionFind(int n) {
      for (int i = 0; i < n; ++i) {
        id[i] = i;
        sz[i] = 1;
      }
    }

    int root(int i) {
      while(i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
      }
      return i;
    }

    int find(int p, int q) {
      return root(p)==root(q);
    }

    void unite(int p, int q) {
      int i = root(p);
      int j = root(q);
      if(sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
      }
      else {
        id[j] = i;
        sz[i] += sz[j];
      }
    }
};

struct Edge {
  int x, y, z;
  Edge(int X, int Y, int Z) : x(X), y(Y), z(Z) {};

  bool operator< (const Edge &a) const {
    return a.z > z;
  }
};

int main() {
  int m, n;
  scanf("%d %d\n", &m, &n);
  while ( m != 0 || m != 0) {
    list<Edge> graph;
    UnionFind U(m);
    for (int i = 0; i < n; i++) {
      int x, y, z;
      scanf("%d %d %d\n", &x, &y, &z);
      graph.push_back(Edge(x, y, z));
    }

    graph.sort();

    long long int sum = 0;

    while (!graph.empty()) {
      Edge e = graph.front();
      graph.pop_front();

      if (!U.find(e.x, e.y)) {
        sum += e.z;
        U.unite(e.x, e.y);
      }
    }

    printf("%lld\n", sum);

    scanf("%d %d\n", &m, &n);
  }
  return 0;
}
