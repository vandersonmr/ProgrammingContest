#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>

#define INF INT_MAX

using namespace std;

class AdjListNode {
  int v;
  int weight;
  public:
  AdjListNode(int _v, int _w) {
    v = _v;
    weight = _w;
  }

  int getV() {
    return v;
  }

  int getWeight() {
    return weight;
  }

};

class GraphW {
  int V; // No. of vertices'
  list<AdjListNode> *adj;
  void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
  public:
  GraphW(int V); 
  void addEdge(int u, int v, int weight);
  int shortestPath(int s, int en);
};

GraphW::GraphW(int V) {
  this->V = V;
  adj = new list<AdjListNode> [V];
}

void GraphW::addEdge(int u, int v, int weight) {
  AdjListNode node(v, weight);
  adj[u].push_back(node); // Add v to u's list
}

void GraphW::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
  visited[v] = true;
  list<AdjListNode>::iterator i;

  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    AdjListNode node = *i;
    if (!visited[node.getV()])
      topologicalSortUtil(node.getV(), visited, Stack);
  }
  Stack.push(v);
}

int GraphW::shortestPath(int s, int en) {
  stack<int> Stack;
  int dist[V];

  bool *visited = new bool[V];

  for (int i = 0; i < V; i++)
    visited[i] = false;

  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      topologicalSortUtil(i, visited, Stack);

  for (int i = 0; i < V; i++)
    dist[i] = INF;
  dist[s] = 0;

  while (Stack.empty() == false) {
    int u = Stack.top();
    Stack.pop();
    list<AdjListNode>::iterator i;
    if (dist[u] != INF) {
      for (i = adj[u].begin(); i != adj[u].end(); ++i)
        if (dist[i->getV()] > dist[u] + i->getWeight())
          dist[i->getV()] = dist[u] + i->getWeight();
    }
  }

  return dist[en];
}

class Graph {
  private:
    int V;
    list<int> *adj;
  public:
    Graph(int V) {
      this->V = V;
      adj = new list<int> [V];
    }
    void addEdge(int v, int w);
    list<int> getEdges(int v) {
      return adj[v];
    }
    void DFS(int s, bool visited[], vector<int>&);
    Graph getTranspose();
    void fillOrder(int, bool[], stack<int>&);
    vector<vector<int> > printSCCs();
};

Graph Graph::getTranspose() {
  Graph g(V);
  for (int v = 0; v < V; v++) {
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
      g.adj[*i].push_back(v);
  }
  return g;
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  //adj[w].push_back(v); // Direct graph
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) {
  visited[v] = true;
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      fillOrder(*i, visited, Stack);
  Stack.push(v);
}

vector<vector<int> > Graph::printSCCs() {
  stack<int> Stack;
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      fillOrder(i, visited, Stack);

  Graph gr = getTranspose();

  for (int i = 0; i < V; i++)
    visited[i] = false;
  int count = 0;
  vector<vector<int> > SCCs;
  while (Stack.empty() == false) {
    int v = Stack.top();
    Stack.pop();
    if (visited[v] == false) {
      vector<int> SCC;
      gr.DFS(v, visited, SCC);
      if (!SCC.empty())
        SCCs.push_back(SCC);
    }
    count++;
  }
  return SCCs;
}

void Graph::DFS(int v, bool visited[], vector<int>& SCC) {
  visited[v] = true;
  if (v == 0) return;
  SCC.push_back(v);
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFS(*i, visited, SCC);
}

int main() {
  while(true) {
    int n, e;
    scanf("%d %d\n", &n, &e);
    if (n + e == 0) break;
    int weight[n+1][n+1];
    Graph G(n+1);
    
    for (int i = 0; i < e; i++) {
      int a, b, w;
      scanf("%d %d %d\n", &a, &b, &w);
      G.addEdge(a, b);
      weight[a][b] = w;
    }

    vector<vector<int> > SCCs = G.printSCCs();
    int reverseSCCs[n+1];
    for (int i = 0; i < SCCs.size(); i++) {
      for (int j = 0; j < SCCs[i].size(); j++) {
        reverseSCCs[SCCs[i][j]] = i;
      }
    }
    
    GraphW gSCC(SCCs.size());

    for (int i = 1; i <= n; i++) {
      list<int> E = G.getEdges(i);
      for (list<int>::iterator J = E.begin(); 
           J != E.end(); ++J) {
        if (reverseSCCs[i] != reverseSCCs[*J]) {
          gSCC.addEdge(reverseSCCs[i], reverseSCCs[*J], weight[i][*J]);
        }
      }
    }

    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
      int a, b;
      scanf("%d %d\n", &a, &b);
      if (reverseSCCs[a] == reverseSCCs[b]) printf("0\n");
      else {
        int d = gSCC.shortestPath(reverseSCCs[a], reverseSCCs[b]);
        if (d == INF) printf("Nao e possivel entregar a carta\n");
        else printf("%d\n", d);
      }
    }
    printf("\n");
  }
  return 0;
}
