#include <cmath>

struct Point {
  int x, y;
};

struct Line {
  Point Pa, Pb;
  int a, b, c;
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

