#include <stdio.h>
#include <map>
#include <stdlib.h>
using namespace std;

int main(){
  int n;
  while (scanf("%d\n", &n) != EOF){
      map<int,int> largadar;
      int largada[n], chegada[n];
      int ultrapassagens = 0;
      char s[100];
      scanf("%[^\n]\n", s);
      for(int i=0; i < n; i++) {
            int d;
            sscanf(s,"%d %[^\n]\n", &d, s);
            largada[i] = d;
            largadar[d] = i;
      }
      scanf("%[^\n]\n",s);
      for (int i = 0; i < n; i++){
          sscanf(s, "%d %[^\n]\n", &chegada[i], s);
      }
      for (int i = n-1; i >= 0; i--){
        if (chegada[i] != largada[i]){
          int id = largadar[chegada[i]];
          printf("%d %d\n", id, i);
          ultrapassagens += abs(id - i);
          int aux = chegada[i];
          //chegada[i] = chegada[id];
          //chegada[id] = aux;
          for (int j = n; j > i; j--){
            chegada[j] = chegada[j-1];
          }
          chegada[i] = chegada[id];
          chegada[id] = aux;
        }
      }
      printf("%d\n", ultrapassagens);
  }
}
