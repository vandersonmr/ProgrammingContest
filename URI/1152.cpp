#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vi taken; 
priority_queue<ii> pq;
vector<vii> AdjList;
void process(int vtx)
{
  taken[vtx] = 1;
  for (int j = 0; j < AdjList[vtx].size(); j++)
  {
    ii v = AdjList[vtx][j];
    if (!taken[v.first])
      pq.push(ii(-v.second, -v.first));
  }
}
int main()
{
  int V, A, u, v, w, soma;
  while (scanf("%d %d", &V, &A) && (V || A))
  {
    soma = 0;
    AdjList.assign(V, vii());
    for (int i = 0; i < A; i++)
    {
      scanf("%d %d %d", &u, &v, &w);
      AdjList[u].push_back(ii(v, w));
      AdjList[v].push_back(ii(u, w));
      soma += w;
    }
    // Prim
    taken.assign(V, 0);
    process(0);
    int mst_cost = 0;
    while (!pq.empty())
    {
      ii front = pq.top(); pq.pop();
      u = -front.second, w = -front.first; // Armazenei o oposto
      if (!taken[u])
        mst_cost += w, process(u);
    }
    printf("%d\n", soma - mst_cost);
  }
  return 0;
}
