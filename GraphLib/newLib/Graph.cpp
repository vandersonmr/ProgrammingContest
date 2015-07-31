#include <iostream>
#include <list>
#include <queue>

using namespace std;

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
    void BFS(int s, bool visited[]);
    void DFS(int s, bool visited[]);
    Graph getTranspose();
    bool isConnected();
};

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  //adj[w].push_back(v); // Direct graph
}

