bool Graph::isSC() {
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;
  DFSUtil(0, visited);
  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      return false;

  Graph gr = getTranspose();

  for (int i = 0; i < V; i++)
    visited[i] = false;

  gr.DFSUtil(0, visited);

  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      return false;
  return true;
}
