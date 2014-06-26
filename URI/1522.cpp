#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <string>

using namespace std;

map<string, bool> hash;
bool PD(int a, int b, int c, int d) {
  ostringstream ss;
  ss << a << " " << b << " " << c;
  string str = ss.str();
  hash[str] = d;
  return d;
}

int global;
bool solve(int matriz[][3], int a, int b, int c, int n) { 
  global++;
  int a1, b1, c1;
  ostringstream ss;
  ss << a << " " << b << " " << c;
  string str = ss.str();
  if(hash.count(str) == 1) {
  //  printf("Entrou\n");
    return hash[str];
  }
//  printf("%d %d %d %d\n", a, b, c, n);
  if(a >= n-1 && b >= n-1 && c >= n-1)
    return PD(a,b,c, true);
  if(a < n-1 && 0 == matriz[a][0]%3)
    if(solve(matriz, ++a, b, c, n)) 
      return PD(a,b,c, true);
  if(b < n-1 && 0 == matriz[b][1]%3)
    if(solve(matriz, a, ++b, c, n))
      return PD(a,b,c, true);
  if(c < n-1 && 0 == matriz[c][2]%3)
    if(solve(matriz, a, b, ++c, n))
      return PD(a,b,c, true);
  if(a < n-1 && b < n-1 && 0 == (matriz[a][0] + matriz[b][1]) %3)
    if(solve(matriz, ++a, ++b, c, n)) 
      return PD(a,b,c, true);
  if(a < n-1 && c < n-1 && 0 == (matriz[a][0] + matriz[c][2]) %3)
    if(solve(matriz, ++a, b, ++c, n)) 
      return PD(a,b,c, true);
  if(b < n-1 && c < n-1 && 0 == (matriz[b][1] + matriz[c][2]) %3)
    if(solve(matriz, a, ++b, ++c, n)) 
      return PD(a,b,c, true);
  if(a < n-1 && b < n-1 && c < n-1 && 0 == (matriz[a][0] + matriz[b][1] + matriz[c][2]) %3) 
    if(solve(matriz, ++a, ++b, ++c, n)) 
      return PD(a,b,c, true);
 return PD(a,b,c, false);
}

int main() {  
  while(true) {
    int n = 0;
    scanf("%d\n", &n); 
    if(0 == n) return 0;
    int matriz[n][3];
    int sum = 0;
    for(int i=0;i<n;i++) {
      int a,b,c;
      scanf("%d %d %d\n", &a, &b, &c);
      sum += a + b + c;
      matriz[i][0] = a;
      matriz[i][1] = b;
      matriz[i][2] = c;
    }
    if(0 != (sum % 3)) {
      printf("%d\n", 0);
    } else {
      printf("%d\n", (int) solve(matriz, 0, 0, 0, n));
    }
    global = -1;
    hash.erase(hash.begin(), hash.end());
   // printf("%d\n", global);
  }
  return 0;
}
