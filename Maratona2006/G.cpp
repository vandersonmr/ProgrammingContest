// O(E+V)
#include <list>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

#define NIL -1

using namespace std;

class Graph {
  private:
    int S;
    vector<int> *adj;

  public:
    Graph(int Size) {
      adj = new vector<int>[Size];
      S = Size; 
    }

    int getSize() {
      return S;
    }

    void addDirectEdge(int a, int b) {
      adj[a].push_back(b);
    }

    vector<int>& getEdges(int a) {
      return adj[a];
    }  
};

vector<pair<int, int> >* bridgeUtil(int u, bool visited[], int disc[], 
    int low[], int parent[], Graph &G, vector<pair<int, int> >* briges) {
  static int time = 0;

  visited[u] = true;

  disc[u] = low[u] = ++time;

  vector<int> &adj = G.getEdges(u);
  vector<int>::iterator i;
  for (i = adj.begin(); i != adj.end(); ++i) {
    int v = *i;  

    if (!visited[v]) {
      parent[v] = u;
      bridgeUtil(v, visited, disc, low, parent, G, briges);

      low[u] = min(low[u], low[v]);

      if (low[v] > disc[u]) 
        briges->push_back(pair<int, int>(u, v));
    }

    else if (v != parent[u])
      low[u]  = min(low[u], disc[v]);
  }

  return briges;
}

vector<pair<int, int> >& bridges(Graph &G) {
  bool *visited = new bool[G.getSize()];
  int *disc = new int[G.getSize()];
  int *low = new int[G.getSize()];
  int *parent = new int[G.getSize()];

  for (int i = 0; i < G.getSize(); i++) {
    parent[i] = NIL;
    visited[i] = false;
  }

  vector<pair<int, int> > *briges = new vector<pair<int, int> >;

  for (int i = 0; i < G.getSize(); i++)
    if (visited[i] == false) 
      bridgeUtil(i, visited, disc, low, parent, G, briges);

  return *briges;
}


int main() {
  int n, m;
  while(true) {
    scanf("%d %d\n", &n, &m);
    Graph G(n);
    if (n + m == 0) break;
    int i = 0;

    map<string, int> myPog;
    map<int, string> myLife;

    for (int i = 0; i < n; i++) {
      char s[21];
      scanf("%s", s);
      printf("%s => %d\n", s, i);
      myPog[string(s)] = i;
      myLife[i] = string(s);
    }

    for (int i = 0; i < m; i++) {
      char s[21], s1[21];
      scanf("%s %s", s, s1);
      G.addDirectEdge(myPog[string(s)], myPog[string(s1)]);
    }

    vector<pair<int, int> > B = bridges(G);
    if (B.size() == 0) printf("Nenhuma\n");
    for (int i = 0; i < B.size(); i++) {
      printf("%d - %d\n", B[i].first, B[i].second);
      printf("%s %s\n", myLife[B[i].first].c_str(), myLife[B[i].second].c_str());
    }
    printf("\n");
  }
  return 0;
}
