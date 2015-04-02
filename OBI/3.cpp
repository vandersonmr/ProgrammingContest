#include <vector>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int n;
  scanf("%d\n",&n);
  for(int i=0;i<n;i++) {
    int d;
    scanf("%d\n", &d);
    vector<int> notas;
    vector<int> notas2;
    char s[10000];
    scanf("%[^\n]\n", s);
    for(int j=0;j<d;j++) {
      int gr;
      sscanf(s,"%d %[^\n]\n", &gr, s);
      notas.push_back(-gr);
      notas2.push_back(-gr);
    }
    sort(notas.begin(), notas.end());
    int total = 0;
    for(int j=0;j<d;j++){ 
      if(notas[j] == notas2[j]) 
        total++;
    }
    cout << total << endl;
  }
  return 0;
}
