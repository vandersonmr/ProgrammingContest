double prim(vector<Vertice> &G) {
  double total = 0;
  while (!G.empty()) {
    sort_heap(G.begin(), G.end());
    Vertice u = G.front();
    pop_heap(G.begin(), G.end()); 
    G.pop_back();
    total += u.chave;
    for (int i = 0; i < G.size(); i++) 
      if (w(u, G[i]) < G[i].chave) 
        G[i].chave = w(u, G[i]);
  }
  return total/100;
}

