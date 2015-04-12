#include <stdio.h>
#include <cmath>
#include <cstring>

int main(){
  int n, l, c;
  while (scanf("%d %d %d\n", &n, &l, &c) != EOF){
    int linha, pagina, caractere;
    caractere = linha = pagina = 0;
    linha = 1;
    pagina = 1;
    for(int i=0;i < n; i++) { 
      char string[100];
      scanf("%s", string);

      caractere += strlen(string)+1;
      if((caractere-1) > c) {
        caractere = strlen(string)+1;
        linha++;
      }      
      if(linha > l) {
        linha = 1;
        pagina++;
      }

    }
    printf("%d\n", pagina);
 }
}
