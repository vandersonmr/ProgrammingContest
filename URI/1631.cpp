#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <vector>

struct Point {
  int x, y;
};

struct Line {
  Point Pa, Pb;
  int a, b, c;
  Line() {}
  Line(Point A, Point B) {
    Pa = A; 
    Pb = B;
    a = A.y - B.y;
    b = B.x - A.x;    
    c = A.x*B.y - B.x*A.y;
  }
};

double distance(Point P, Line L) {
  return (std::abs(L.a*P.x + L.b*P.y + L.c)) / 
    std::sqrt(std::pow(L.a, 2) + std::pow(L.b, 2));
}

bool isLeft(Point c, Line L) {
  Point a = L.Pa;
  Point b = L.Pb;
  return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) > 0;
}

int main() {
  int n;
  while(true) {
    scanf("%d", &n);
    if (n == 0) break;

    std::vector<Point> points(n);

    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      points[i].x = a;
      points[i].y = b;
    }

    double menorDif = DBL_MAX; 
    std::vector<Point>::iterator I, J, A;
    for (I = points.begin(); I != points.end(); ++I) {
      for (J = points.begin(); J != points.end(); ++J) {
        Line L(*I, *J);
        double DL = 0;
        double DR = 0;
        for (A = points.begin(); A != points.end(); ++A)  {
          if (isLeft(*A, L)) 
            DL += distance(*A, L);
          else 
            DR += distance(*A, L);
        }
        if (std::abs(DL- DR) < menorDif)
          menorDif = std::abs(DL - DR);
      }
    }

    printf("%.3lf\n", menorDif);
  }
  return 0;
}
