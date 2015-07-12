#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1100

class UnionFind {
  public:
    int id[MAX], sz[MAX];
    UnionFind(int n) {
      for (int i = 0; i < n; ++i) {
        id[i] = i;
        sz[i] = 1;
      }
    }

    int root(int i) {
      while(i != id[i]) {
        id[i] = id[id[i]];    //path Compression
        i = id[i];
      }
      return i;
    }

    int find(int p, int q) {
      return root(p)==root(q);
    }

    void unite(int p, int q) {
      int i = root(p);
      int j = root(q);
      if(sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
      }
      else {
        id[j] = i;
        sz[i] += sz[j];
      }
    }
};

class point {
  public:
  double x;
  double y;
  double z;
  point() {
    z = 0;
  }
};

class line {
  public:
    int id;
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    line() {
      z1 = 0;
      z2 = 0;
    }
};

double dot(point& c1, point& c2) {
    return (c1.x * c2.x + c1.y * c2.y + c1.z * c2.z);
}
 
double norm(point& c1) {
    return sqrt(dot(c1, c1));
}

int getShortestDistance(const line& line1, const line& line2)
{
    double EPS = 0.00000001;
 
    point delta21;
    delta21.x = line1.x2 - line1.x1;
    delta21.y = line1.y2 - line1.y1;
    delta21.x = line1.z2 - line1.z1;
 
    point delta41;
    delta41.x = line2.x2 - line2.x1;
    delta41.y = line2.y2 - line2.y1;
    delta41.z = line2.z2 - line2.z1;
 
    point delta13;
    delta13.x = line1.x1 - line2.x1;
    delta13.y = line1.y1 - line2.y1;
    delta13.z = line1.z1 - line2.z1;
 
    double a = dot(delta21, delta21);
    double b = dot(delta21, delta41);
    double c = dot(delta41, delta41);
    double d = dot(delta21, delta13);
    double e = dot(delta41, delta13);
    double D = a * c - b * b;
 
    double sc, sN, sD = D;
    double tc, tN, tD = D;
 
    if (D < EPS)
    {
        sN = 0.0;
        sD = 1.0;
        tN = e;
        tD = c;
    }
    else
    {
        sN = (b * e - c * d);
        tN = (a * e - b * d);
        if (sN < 0.0)
        {
            sN = 0.0;
            tN = e;
            tD = c;
        }
        else if (sN > sD)
        {
            sN = sD;
            tN = e + b;
            tD = c;
        }
    }
 
    if (tN < 0.0)
    {
        tN = 0.0;
 
        if (-d < 0.0)
            sN = 0.0;
        else if (-d > a)
            sN = sD;
        else
        {
            sN = -d;
            sD = a;
        }
    }
    else if (tN > tD)
    {
        tN = tD;
        if ((-d + b) < 0.0)
            sN = 0;
        else if ((-d + b) > a)
            sN = sD;
        else
        {
            sN = (-d + b);
            sD = a;
        }
    }
 
    if (abs(sN) < EPS) sc = 0.0;
    else sc = sN / sD;
    if (abs(tN) < EPS) tc = 0.0;
    else tc = tN / tD;
 
    point dP;
    dP.x = delta13.x + (sc * delta21.x) - (tc * delta41.x);
    dP.y = delta13.y + (sc * delta21.y) - (tc * delta41.y);
    dP.z = delta13.z + (sc * delta21.z) - (tc * delta41.z);
 
    return ceil(sqrt(dot(dP, dP)));
}
 

bool shorter(const pair<line, line>& L1, const pair<line, line>& L2) {
  int A = getShortestDistance(L1.first, L1.second);
  int B = getShortestDistance(L2.first, L2.second);
  return A < B;
}

int main () {
  int n;
  scanf("%d\n", &n);
  std::vector<line> Graph;
  std::vector<std::pair<line, line> > Adj;

  for (int i = 0; i < n; i++) {
    line L;
    L.id = i;
    scanf("%lf %lf %lf %lf\n", &L.x1, &L.y1, &L.x2, &L.y2); 
    Graph.push_back(L);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      Adj.push_back(pair<line, line>(Graph[i], Graph[j]));
    }
  }
  std::sort(Adj.begin(), Adj.end(), shorter); 
  UnionFind U(n);

  int T = 0;
  for (auto &I : Adj) {
    if (!U.find(I.first.id, I.second.id)) {
      T += getShortestDistance(I.first, I.second);
      U.unite(I.first.id, I.second.id);
    }
  }
  printf("%d\n", T - 3);
  return 0; 
}
