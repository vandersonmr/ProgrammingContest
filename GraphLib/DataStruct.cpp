#include <vector>

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
    
    void addEdge(int a, int b) {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    void addDirectEdge(int a, int b) {
      adj[a].push_back(b);
    }

    vector<int>& getEdges(int a) {
      return adj[a];
    }  

    bool isEulerian();

    bool isConnected();

    void DFSUtil(int v, bool visited[]);
};


void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;

  vector<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFSUtil(*i, visited);
}
