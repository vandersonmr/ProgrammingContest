#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
 
int tamanhos[6];

bool solve(int t[]) {
  if(t[0]==-1) return true;
  tamanhos[t[0]] -= 1;
  if(tamanhos[t[0]] >= 0) {
    if(solve(t+2)) {
      return true;
    } else {
      tamanhos[t[0]] += 1;
      tamanhos[t[1]] -= 1;
      if(tamanhos[t[1]] >= 0) {
        if(solve(t+2)){
          return true;
        }else{
          tamanhos[t[1]] += 1;
          return false;
        }
      }else {
          tamanhos[t[1]] += 1;
          return false;
      }
    }
  } else{
    tamanhos[t[0]] += 1;
    tamanhos[t[1]] -= 1;
    if(tamanhos[t[1]] >= 0){
      if(solve(t+2)) {
        return true;
      } else {
        tamanhos[t[1]] += 1;
        return false;
      }
    } else {
      tamanhos[t[1]] += 1;
      return false;
    }
  }
}

int getCamisa(char* s1) {
  string s = string(s1);
  if(s == "XXL")
    return 0;
  if(s == "XL")
    return 1;
  if(s == "L")
    return 2;
  if(s == "M")
    return 3;
  if(s == "S")
    return 4;
  if(s == "XS")
    return 5;
}

int main(void) {
  int q;
  scanf("%d", &q);
  for(int i=0;i<q;i++) {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int k=0;k < 6;k++)
      tamanhos[k] = n/6;
    int t[2*m+1];
    t[2*m] = -1;
    for(int j=0; j<2*m;j+=2){
      char* s1 = new char(2);
      char* s2 = new char(2);
      scanf("%s %s", s1, s2);
      t[j]   = getCamisa(s1);
      t[j+1] = getCamisa(s2);
      delete s1;
      delete s2;
    }
    if(solve(t))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

