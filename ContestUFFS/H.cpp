#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 1100
#define EPS 1e-9
#define LEPS 1e-6
#define INF 112345678
#define geq(x, y) ((x) > (y) || fabs((x) - (y)) < EPS)

struct ponto {
  double x, y;
  ponto() {}
  ponto(double _x, double _y) : x(_x), y(_y) {}
};

struct vetor {
  double x, y;
  vetor() {}
  vetor(double _x, double _y) : x(_x), y(_y) {}
};

typedef struct { int id; ponto a, b; } seg;

vetor ponto2vetor(ponto a, ponto b) {
  return vetor(b.x - a.x, b.y - a.y);
}

ponto trans(ponto a, vetor u) {
  return ponto(a.x + u.x, a.y + u.y);
}

vetor scale(vetor u, double lambda) {
  return vetor(u.x * lambda, u.y * lambda);
}

double prod_esc(vetor u, vetor v) {
  return u.x * v.x + u.y * v.y;
}

double deucl(ponto a, ponto b) {
  vetor ab = ponto2vetor(a, b);
  return sqrt(prod_esc(ab, ab));
}

double dpseg(ponto p, seg s) {
  vetor ap = ponto2vetor(s.a, p), ab = ponto2vetor(s.a, s.b);
  double lambda = prod_esc(ap, ab) / prod_esc(ab, ab);
  if (geq(0., lambda)) return deucl(p, s.a);
  if (geq(lambda, 1.)) return deucl(p, s.b);
  return deucl(p, trans(s.a, scale(ab, lambda)));
}

double dseg(seg s1, seg s2) {
  double inf = 0., sup = 1., m1, m2, d1, d2, dinf, dsup;
  vetor u = ponto2vetor(s1.a, s1.b), v = ponto2vetor(s2.a, s2.b);
  if (prod_esc(u, u) < EPS && prod_esc(v, v) < EPS)
    return deucl(s1.a, s2.a);
  if (prod_esc(u, u) < EPS) return dpseg(s1.a, s2);
  if (prod_esc(v, v) < EPS) return dpseg(s2.a, s1);
  dinf = dpseg(s1.a, s2); dsup = dpseg(s1.b, s2);
  while (fabs(inf - sup) > EPS) {
    m1 = inf + (sup - inf) / 3.;
    m2 = inf + (sup - inf) * 2. / 3.;
    if (geq(m1, m2)) break;
    d1 = dpseg(trans(s1.a, scale(u, m1)), s2);
    d2 = dpseg(trans(s1.a, scale(u, m2)), s2);
    if (geq(dinf, d1) && geq(d1, d2)) { inf = m1; dinf = d1; }
    else if (geq(dsup, d2) && geq(d2, d1)) { sup = m2; dsup = d2; }
    else if (dinf < dsup) { sup = m2; dsup = d2; }
    else { inf = m1; dinf = d1; }
  }
  return dinf < dsup ? dinf : dsup;
}

bool shorter(const pair<seg, seg>& L1, const pair<seg, seg>& L2) {
  int A = dseg(L1.first, L1.second);
  int B = dseg(L2.first, L2.second);
  return A < B;
}

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
