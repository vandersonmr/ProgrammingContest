#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 1123
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

typedef struct { ponto a, b; } seg;

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

