#include <vector>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;
int invert(int a) {
  int i = 0;
  int a1 = a;
  while (a1 > 0) {
    i *= 10;
    i += (a1 % 10);
    a1 /= 10;
  }
  return i; 
}

int solve(int a,int b) {
  int total = 0;
  int bi = b;
  while(a != b) {
    if((a%10) < (bi%10)) {
      total++;
      a++;
    }
    if((a%10) - (bi%10) == 0){
      a = invert(a);
    if(a != invert(a)) 
      total++;
    }
    bi = (bi == invert(b))? b : invert(b);
  }
  return total;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    int a,b;
    scanf("%d %d", &a, &b);
    int j=1;
    cout << solve(a,b) << endl;
  }
  return 0;
}
