// O(E+V)
#include <list>
#include <stdio.h>

#define NIL -1

using namespace std;

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

      if (low[v] > disc[u]) {
        briges->push_back(pair<int, int>(u, v));
      }
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
