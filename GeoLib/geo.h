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

bool isLeft(Point c, Line L) {
  Point a = L.Pa;
  Point b = L.Pb;
  return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) > 0;
}

int dot(Point& A, Point& B, Point& C){
  Point AB;
  Point BC;
  AB.x = B.x-A.x;
  AB.y = B.y-A.y;
  BC.x = C.x-B.x;
  BC.y = C.y-B.y;
  int dot = AB.x * BC.x + AB.y * BC.y;
  return dot;
}

int cross(Point& A, Point& B, Point& C) {
  Point AB;
  Point AC;
  AB.x = B.x-A.x;
  AB.y = B.y-A.y;
  AC.x = C.x-A.x;
  AC.y = C.y-A.y;
  int cross = AB.x * AC.y - AB.y * AC.x;
  return cross;
}

double distance(Point& A, Point& B){
  int d1 = A.x - B.x;
  int d2 = A.y - B.y;
  return std::sqrt(d1*d1+d2*d2);
}

double linePointDist(Point& A, Point& B, Point& C, boolean isSegment) {
  double dist = cross(A,B,C) / distance(A,B);
  if(isSegment) {
    int dot1 = dot(A,B,C);
    if(dot1 > 0) return distance(B,C);
    int dot2 = dot(B,A,C);
    if(dot2 > 0) return distance(A,C);
  }
  return std::abs(dist);
}
