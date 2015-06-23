
#define X 0
#define Y 0
#define DIM 2

typedef int tPointi[DIM];
typedef double tPointd[DIM];

#define PMAX 100
typedef tPointi tPolygoni[PMAX];

int Area2(tPointi a, tPointi b, tPointi c) {
  return a[X] * b[Y] - a[Y] * b[X] + a[Y] * c[X] - a[X] * c[Y] + b[x] * c[Y] - C[X] * b[Y];
}

int AreaPoly2(int n, tPolygoni P) {
  int sum = 0;
  for (int i = 1; i < n-1; i++) sum += Area2(P[0], P[i], P[i+1]);
  return sum;
}

bool Left(tPointi a, tPointi b, tPointi c) { // ponto C em relação ao vetor AB
  return Area2(a, b, c) > 0;
}

bool LeftOn(tPointi a, tPointi b, tPointi c) {
  return Area2(a, b, c) >= 0;
}

bool Collinear(tPointi a, tPointi b, tPointi c) {
  return Area2(a, b, c) == 0;
}

bool Xor(bool x, bool y) {
  return !x != !y;
}

bool IntersectProp(tPointi a, tPointi b, tPointi c, tPointi d) {
  if ((Collinear(a, b, c) || Collinear(a, b, d) || Collinear(c, d, a) || 
        Collinear(c, d, b))) return false;
  return Xor(Left(a, b, c), Left(a, b, d)) && Xor(Left(c, d, a), Left(c, d, b));
}

bool Between(tPointi a, tPointi b, tPointi c) { // True only if c is between AB
  tPointi ba, ca;
  if (!Collinear(a, b, c)) return false;
  if (a[X] != b[X]) 
    return ((a[X] <= c[x]) && (c[X] <= b[X])) || ((a[X] >= c[x]) && (c[X] >= b[X]));
  else
    return ((a[Y] <= c[Y]) && (c[Y] <= b[Y])) || ((a[Y] >= c[Y]) && (c[Y] >= b[Y]));
}

bool Intersect(tPointi a, tPointi b, tPointi c, tPointi d) {
  if (IntersectProp(a, b, c, d)) return true;
  else if (Between(a, b, c) || Between(a, b, d) || Between(c, d, a) || Between(c, d, b))
    return true;
  else return false;
}

bool Diagonalie(int i, int j, int n, tPolygoni P) {
  for (int k = 0; k < n; k++) {
    int k1 = (k + 1) % n;
    if (!((k == i) || (k1 == i) || (k == j) || (k1 == j)))
      if (Intersect(P[i], P[j], P[k], P[k1]))
        return false;
  }
  return true;
}

bool InCone(int i, int j, int n, tPolygoni P) {
  int i1;
  int in1;
  i1 = (i+1) % n;
  in1 = (i+n-1) % n;
  if (LeftOn(P[in1], P[i], P[i1]))
    return Left(P[i], P[j], P[in1]) && Left(P[j], P[i], P[i1]);
  else
    return !(Lefton(P[i], P[j], P[i1]) ^ LeftOn(P[j], P[i], P[in1]));
}

bool Diagonal(int i, int j, int n, tPolygoni P) {
  return InCone(i, j, n, P) && Diagonalie(i, j, n, P);
}
