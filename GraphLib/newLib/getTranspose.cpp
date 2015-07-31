Graph Graph::getTranspose() {
  Graph g(V);
  for (int v = 0; v < V; v++) {
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
      g.adj[*i].push_back(v);
  }
  return g;
}
