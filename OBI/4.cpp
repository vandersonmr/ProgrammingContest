#include <vector>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

double h(int b, int bz, double hz, double v) {
  return ((M_PI*hz)/3)*((bz*bz) + (b*bz) + (b*b));
}

int main(){
  int n;
  scanf("%d\n", &n);
  for(int i=0;i<n; i++) {
    int na, vl;
    scanf("%d %d\n", &na, &vl);
    int b, bz;
    int hzi;
    scanf("%d %d %d\n", &b, &bz, &hzi);
    double hz = hzi;
    while(true) {
      //printf("%f0.2\n", h(b,bz,hz,0));
      if(((int) h(b,bz,hz,0)) == (vl/na)) {
        printf("%f.2\n", hz);
        break;
      }
      hz-=0.01;    
    }
  }
  return 0;
}
