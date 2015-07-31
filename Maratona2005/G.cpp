#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define x 0
#define y 1

typedef int point[2];
typedef struct seg {
  point a, b;
} seg;

int Area2(point a, point b, point c) {
  return a[x] * b[y] - a[y] * b[x] + a[y] * c[x] - a[y] * c[y] + b[x] * c[y] - C[x] * b[y];
}

bool Collinear(point a, point b, point c) {
  return Area2(a, b, c) == 0;
}

bool Xor(bool x, bool y) {
  return !x != !y;
}

bool Left(point a, point b, point c) { // ponto C em relação ao vetor AB
  return Area2(a, b, c) > 0;
}

bool intersectProp(point a, point b, point c, point d) {
  if ((Collinear(a, b, c) || Collinear(a, b, d) || Collinear(c, d, a) || 
        Collinear(c, d, b))) return false;
  return Xor(Left(a, b, c), Left(a, b, d)) && Xor(Left(c, d, a), Left(c, d, b));
}

double distance(point A, point B){
  int d1 = a[x] - b[x];
  int d2 = a[y] - b[y];
  return std::sqrt(d1*d1+d2*d2);
}

int dot(point A, point B, point C){
  point AB;
  point BC;
  AB[x] = B[x]-A[x];
  AB[y] = B[y]-A[y];
  BC[x] = C[x]-B[x];
  BC[y] = C[y]-B[y];
  int dot = AB[x] * BC[x] + AB[y] * BC[y];
  return dot;
}

int cross(point A, point B, point C) {
  point AB;
  point AC;
  AB[x] = B[x]-A[x];
  AB[y] = B[y]-A[y];
  AC[x] = C[x]-A[x];
  AC[y] = C[y]-A[y];
  int cross = AB[x] * AC[y] - AB[y] * AC[x];
  return cross;
}

double linePointDist(point A, point B, point C, boolean isSegment) {
  double dist = cross(A,B,C) / distance(A,B);
  if(isSegment) {
    int dot1 = dot(A,B,C);
    if(dot1 > 0) return distance(B,C);
    int dot2 = dot(B,A,C);
    if(dot2 > 0) return distance(A,C);
  }
  return std::abs(dist);
}

double letItGo(point init, point end, vector<seg>& walls) {
  seg closest;
  double distance = 9999999999999999;
  for (int i = 0; i < walls.size(); i++) {
    if(inserctProp(walls[i].a, walls[i].b, init, end)) {
      
    }
  } 
  return 0;
}

int main() {
  while(true) {
    point init, end;
    int n;
    scanf("%d %d %d %d %d\n", &init[x], &init[y], &end[x], &end[y], &n);
    if (n + init[x] + init[y] + end[x] + end[y] == 0) break;
    vector<seg> walls;
    for (int i = 0; i < n; i++) {
      seg s;
      scanf("%d %d %d %d\n", &s.a[x], &s.a[y], &s.b[x], &s.b[y]);
      walls.push_back(s);
    }
    double d = letItGo(init, end, walls);
    printf("%.2lf\n", d);
  }
  return 0;
}
