int main () {
  int n;
  scanf("%d\n", &n);
  std::vector<seg> Graph;
  bool visited[n];
  double weight[n];

  for (int i = 0; i < n; i++) {
    seg L;
    L.id = i;
    scanf("%lf %lf %lf %lf\n", &L.a.x, &L.a.y, &L.b.x, &L.b.y); 
    visited[i] = false;
    weight[i] = INF;
    Graph.push_back(L);
  }

  weight[0] = 0;

  double T = 0.;
  for (int u = 0; u < n; u++) {
    int i = 0;
    double svalue = INF;
    for (int f = 0; f < n; f++) {
      if (!visited[f] && weight[f] < svalue) { 
        svalue = weight[f];
        i = f;
      }
    }
    visited[i] = true;
    T += weight[i];
    for (int j = 0; j < n; j++) {
      if (!visited[j]) {
        double d = dseg(Graph[j], Graph[i]);
        if (d < weight[j]) 
          weight[j] = d;
      }
    }
  }
  
  printf("%.0lf\n", fabs(ceil(T - LEPS)));
  return 0; 
}
