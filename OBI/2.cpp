#include <vector>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int main(){
  int n;
  scanf("%d\n",&n);
  for(int i=0;i<n;i++) {
    int na, s;
    scanf("%d %d\n", &na, &s);
    char l[1000];
    int min = 1;
    int minv = 9999999;
    scanf("%d %[^\n]\n", &minv,l);
    for(int j=1; j < na; j++){
      int d;
      sscanf(l,"%d %[^\n]\n", &d,l);
      if(abs(d-s) < minv) {
        minv = abs(d-s);
        min = j+1; 
      }
    }
    cout << min << endl;
  }
  return 0;
}
