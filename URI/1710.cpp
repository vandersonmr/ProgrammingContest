#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

struct Point {
  int x, y, z;
};

struct Plane {
  int a, b, c, d;

  bool isOnLeft(Point P) {
    long long int a1 = a*P.x;
    long long int b1 = b*P.y;
    long long int c1 = c*P.z;
    return (a1 + b1 + c1 - d) > 0;
  }
};

unsigned maxCut(std::vector<Plane>& planes, int j, std::vector<Point>& points) {
  std::vector<Point> left;
  std::vector<Point> right;
  
  for (int i = 0; i < points.size(); i++) {
    if (planes[j].isOnLeft(points[i])) 
      left.push_back(points[i]);
    else
      right.push_back(points[i]);
  }

  if ((j+1) == planes.size()) 
    return std::max(left.size(), right.size());

  int l = 0; 
  int r = 0;
  if (left.size() > 0)
    l = maxCut(planes, j+1, left);
  if (right.size() > 0)
    r = maxCut(planes, j+1, right);
  return std::max(l, r);
}

int main() {  
  int m, n;
  scanf("%d %d", &m, &n); 
  std::vector<Plane> planes(m);
  std::vector<Point> points(n);
  for (int i = 0; i < m; i++) 
    scanf("%d %d %d %d", &planes[i].a, &planes[i].b, &planes[i].c, &planes[i].d);
  for (int i = 0; i < n; i++) 
    scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z);
  
  printf("%u\n", maxCut(planes, 0, points));
  return 0;
}
