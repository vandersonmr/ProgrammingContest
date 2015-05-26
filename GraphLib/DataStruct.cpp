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
};
