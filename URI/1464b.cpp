// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <algorithm>
#include <stdio.h>
#include <vector>

struct Point {
  long x, y;
};

using namespace std;

bool compare(const Point &p1, const Point &p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

long cross(const Point &O, const Point &A, const Point &B) {
  return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

vector<int> convex_hull(vector<Point> &P, vector<bool>& used) {
  int n = P.size(), k = 0;
  vector<int> H(2*n);

  sort(P.begin(), P.end(), compare);

  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      while (k >= 2 && cross(P[H[k-2]], P[H[k-1]], P[i]) <= 0) k--;
      H[k++] = i;
    }
  }

  for (int i = n-2, t = k+1; i >= 0; i--) {
    if (!used[i]) {
      while (k >= t && cross(P[H[k-2]], P[H[k-1]], P[i]) <= 0) k--;
      H[k++] = i;
    }
  }

  H.resize(k);
  return H;
}

int main() {
  long n;
  while (scanf("%ld", &n) != EOF) {
    if (n == 0) break;
    vector<Point> P(n);
    vector<bool> used(n);
    for (long i = 0; i < n; i++) {
      used[i] = false;
      Point ps;
      scanf("%ld %ld", &(ps.x), &(ps.y));
      P.push_back(ps);
    }

    int j = 0;
    while (true) {
      vector<int> C = convex_hull(P, used);
      n -= C.size();
      if (n < 3) break;
      vector<int>::iterator I = C.begin();
      for (; I !=  C.end(); ++I) {
        used[*I] = true;
      }
      j++; 
    }

    if (j % 2 == 0) {
      printf("Do not take this onion to the lab!\n");
    } else {
      printf("Take this onion to the lab!\n");
    }
  }
  return 0;
}
