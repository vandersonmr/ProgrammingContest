void Graph::BFS(int s, bool visited[]) {
  list<int> q;
  list<int>::iterator i;
  visited[s] = true;
  q.push_back(s);
  while (!q.empty()) {
    s = q.front();
    q.pop_front();
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
      if (!visited[*i]) {
        visited[*i] = true;
        q.push_back(*i);
      }
    }
  }
}
