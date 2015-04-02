#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
  while(true){
    int n,b;
    scanf("%d %d\n", &n, &b);
    if(n==b && b==0) return 0;
    char s[300];
    scanf("%[^\n]\n", s);
    int bis[b];
    for(int i = 0; i < b; i++) {
      int bi;
      sscanf(s,"%d %[^\n]", &bi, s);
      bis[i] = bi;
    }
    bool go = true;
    int xs[n+1];
    int t = n+1;
    for(int i =0; i<n+1;i++) xs[i] = 0;
    for(int i = 0; i < b && go; i++){
      for(int j = 0; j < b && go; j++) {
        if(xs[abs(bis[i]-bis[j])] == 0) {
          xs[abs(bis[i]-bis[j])] = 1;
          t--;
          if(t == 0) go = false;
        } 
      }
    }
    if(t == 0) cout << "Y" << endl;
    else cout << "N" << endl;
  }
  return 0;
}
