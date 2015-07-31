#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>

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

Point simulate(int x, std::vector<Line>& L) {
  Point a;
  return a;
}

int main() {
  int n, c;
  while (scanf("%d %d", &n, &c) != EOF) {
    std::vector<Line> L;
    for (int i = 0; i < n; i++) {
      Point a, b;
      scanf("%d %d %d %d\n", &a.x, &a.y, &b.x, &b.y);
      L.push_back(Line(a, b));
    }

    for (int i = 0; i < c; i++) {
      int x;
      scanf("%d\n", &x);
      Point c = simulate(x, L);
      if (c.y == -1) printf("%d\n", c.x);
      else printf("%d %d\n", c.x, c.y);
    }
  }
  return 0;
}
