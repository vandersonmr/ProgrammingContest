bool Graph::isConnected() {
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;
  BFS(0, visited);
  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      return false;
  Graph gr = getTranspose();
  for (int i = 0; i < V; i++)
    visited[i] = false;
  gr.BFS(0, visited);
  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      return false;
  return true;
}
