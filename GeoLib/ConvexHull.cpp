// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <algorithm>
#include <vector>
#include "geo.h"

using namespace std;

bool compare(const Point &p1, const Point &p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

long cross(const Point &O, const Point &A, const Point &B) {
  return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P) {
  int n = P.size(), k = 0;
  vector<Point> H(2*n);

  // Sort points lexicographically
  sort(P.begin(), P.end(), compare);

  // Build lower hull
  for (int i = 0; i < n; ++i) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  // Build upper hull
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  H.resize(k);
  return H;
}

int main() {
  vector<Point> P;
  return 0;
}
