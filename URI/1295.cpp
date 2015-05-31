#include <stdio.h>
#include <float.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>

struct Point {
  double x, y;
};

double distance(Point& P1, Point& P2) {                                              
  return std::sqrt(std::pow(P1.x - P2.x, 2) + std::pow(P1.y - P2.y, 2));           
}    

int compareX(const void* a, const void* b) {
  Point *p1 = (Point *)a,  *p2 = (Point *)b;
  return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) {
  Point *p1 = (Point *)a,   *p2 = (Point *)b;
  return (p1->y - p2->y);
}

float bruteForce(Point P[], int n) {
  float min = FLT_MAX;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      if (distance(P[i], P[j]) < min)
        min = distance(P[i], P[j]);
  return min;
}

float stripClosest(Point strip[], int size, float d) {
  float min = d;  
  for (int i = 0; i < size; ++i)
    for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
      if (distance(strip[i],strip[j]) < min)
        min = distance(strip[i], strip[j]);

  return min;
}

float closestUtil(Point Px[], Point Py[], int n) {
  if (n <= 3)
    return bruteForce(Px, n);

  int mid = n/2;
  Point midPoint = Px[mid];

  Point Pyl[mid+1];   
  Point Pyr[n-mid-1];  
  int li = 0, ri = 0; 
  for (int i = 0; i < n; i++) {
    if (Py[i].x <= midPoint.x)
      Pyl[li++] = Py[i];
    else
      Pyr[ri++] = Py[i];
  }

  float dl = closestUtil(Px, Pyl, mid);
  float dr = closestUtil(Px + mid, Pyr, n-mid);

  float d = std::min(dl, dr);

  Point strip[n];
  int j = 0;
  for (int i = 0; i < n; i++)
    if (abs(Py[i].x - midPoint.x) < d)
      strip[j] = Py[i], j++;

  return std::min(d, stripClosest(strip, j, d));
}

float closest(Point P[], int n) {
  Point Px[n];
  Point Py[n];
  for (int i = 0; i < n; i++) {
    Px[i] = P[i];
    Py[i] = P[i];
  }

  qsort(Px, n, sizeof(Point), compareX);
  qsort(Py, n, sizeof(Point), compareY);

  return closestUtil(Px, Py, n);
}

Point P[10001];

int main() {
  while(true) {
    long n;
    scanf("%ld", &n);
    if (n == 0) return 0;
    for (long i = 0; i < n; i++) 
      scanf("%lf %lf", &(P[i].x), &(P[i].y));
    double d = closest(P, n);
    if (d < 1000)
      printf("%.4lf\n", d);
    else
      printf("INFINITY\n");
  }
  return 0;
}
