#include <vector>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main(){
  int n;
  scanf("%d\n", &n);
  for(int i=0;i<n;i++) {
    char s[1001];
    scanf("%[^\n]\n", s);
    int alfabeto[26];
    for(int j=0;j<26; j++){
      alfabeto[j] = 0;
    }
    for(int j=0;j<strlen(s);j++) {
      if(s[j] >= 97 && s[j] <= 122) {
        alfabeto[s[j]-97]++;
      }
    }
    int total = 0;
    for(int j=0; j<26; j++) {
      if(alfabeto[j] > 0) 
        total++;
    }
    if(total == 26) cout << "frase completa" << endl;
    else if(total >= 13) cout << "frase quase completa" << endl;
    else cout << "frase mal elaborada" << endl;
  }
  return 0;
}
