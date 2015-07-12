#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ll unsigned long long int

long long degree(long long a, long long k, long long p) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k%2) {
      res = (res * cur)%p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}

int get_degree(long long n, long long p) { // returns the degree with which p is in n!
  int degree_num = 0;
  long long u = p;
  long long temp = n;
  while (u <= temp) {
    degree_num += temp/u;
    u *= p;
  }
  return degree_num;
}

long long combinations(int n, int k, long long p) {
  int num_degree = get_degree(n,p) - get_degree(n- k,p);
  int den_degree = get_degree(k,p);
  if (num_degree > den_degree) {
    return 0;
  }
  long long res = 1;
  for (long long i = n; i > n- k; --i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res *ti)%p;
  }
  long long denom = 1;
  for (long long i = 1; i <= k; ++i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    denom = (denom * ti)%p;
  }
  res = (res * degree(denom, p-2, p)) % p;

  return res;
}

ll calc_bin(ll n, ll k) {
  ll r; 
  if (k == 0) {
    r = 1;
    return r;
  }
  r = calc_bin(n-1, k-1);

  r = ((n * r)/k);

  return r;
}

int main () {
  int a, b;
  scanf("%d %d\n", &a, &b);
  char map[a+1][b+1];
  for (int i = 0; i < a; i++) {
    char c;
    for (int j = 0; j < b; j++) {
      scanf("%c", &c);
      map[i+1][j+1] = c;
    }
    scanf("\n");
  }
  int xa, ya, xb, yb;
  while (scanf("%d %d %d %d\n", &xa, &ya, &xb, &yb) != EOF) {
    int n = ((xb - xa)+1) * ((yb - ya)+1);
    int z = 0;
    for (int i = xa; i <= xb; i++) {
      for (int j = ya; j <= yb; j++) {
        if (map[i][j] == '#') {
          ++z;
        }
      }
    }
    // n!/(z!(n-z)!)
    printf("%llu\n", (combinations(n, z, 1000000007) ) - 1);
  }
  return 0;
}
