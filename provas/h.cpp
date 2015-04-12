#include <vector>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <map>

using namespace std;

int main(){
  int n,k;
  scanf("%d %d\n", &n, &k);
  while(n != 0 && k != 0){
    int total=0;
    map<int,int> perguntas;
    char s[60000];
    scanf("%[^\n]\n", s);
    for(int i=0;i < n;i++) {
      int p;
      sscanf(s,"%d %[^\n]\n",&p, s);
      perguntas[p]++;
    }
    for (std::map<int,int>::iterator it=perguntas.begin(); it!=perguntas.end(); ++it) {
      if(it->second >= k) {
        total++;
      }
    }
    cout << total << endl;
    scanf("%d %d\n", &n, &k);
  }
  return 0;
}
