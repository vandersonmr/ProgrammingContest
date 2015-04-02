lude <cstdio>
#include <cmath>

int solve(long long int p) {
  double t = floor((sqrt(1+(8*p))+1)/2); 

  /*while(t != floor(t)) {
   *     --p;
   *         t = (sqrt(1+(8*p))+1)/2; 
   *           } */
  return (int)t-1; 
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    long long int p;
    scanf("%lld", &p);
    printf("%d\n", solve(p));
  } 
  return 0;
}
