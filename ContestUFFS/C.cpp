#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ll unsigned long long int

ll degree(ll a, ll k, ll p) {
  ll res = 1;
  ll cur = a;

  while (k) {
    if (k%2) {
      res = (res * cur)%p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}

int get_degree(ll n, ll p) { // returns the degree with which p is in n!
  int degree_num = 0;
  ll u = p;
  ll temp = n;
  while (u <= temp) {
    degree_num += temp/u;
    u *= p;
  }
  return degree_num;
}

ll combinations(int n, int k, ll p) {
  int num_degree = get_degree(n,p) - get_degree(n- k,p);
  int den_degree = get_degree(k,p);
  if (num_degree > den_degree) {
    return 0;
  }
  ll res = 1;
  for (ll i = n; i > n- k; --i) {
    ll ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res *ti)%p;
  }
  ll denom = 1;
  for (ll i = 1; i <= k; ++i) {
    ll ti = i;
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

#define ac(i, j) (i == 0 || j == 0 ? 0 : w[i][j])

int main () {
  int a, b;
  scanf("%d %d\n", &a, &b);
  char map[a+1][b+1];
  int w[a+1][b+1];
  for (int i = 0; i < a; i++) {
    char c;
    for (int j = 0; j < b; j++) {
      scanf("%c", &c);
      map[i+1][j+1] = c;
      w[i+1][j+1] = ac(i, j+1) + ac(i+1, j) + (c == '#'? 1 : 0) - ac(i, j);
    }
    scanf("\n");
  }
  int xa, ya, xb, yb;
  while (scanf("%d %d %d %d\n", &xa, &ya, &xb, &yb) != EOF) {
    int n = ((xb - xa)+1) * ((yb - ya)+1);
    int z = ac(xb, yb) - ac(xb, ya - 1) - ac(xa - 1, yb) + ac(xa-1, ya-1);
    printf("%llu\n", (combinations(n, z, 1000000007) ) - 1);
  }
  return 0;
}
