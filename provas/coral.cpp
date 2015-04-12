#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  while (scanf("%d", &n) != EOF){
    int notas[n];
    int compassos;
    int soma, distancia, distancia_total;
    int media;
    soma = 0;
    distancia_total = 0;
    for (int i = 0; i < n; i++){
      scanf("%d", &notas[i]);
      soma += notas[i];
      //printf("%d ", notas[i]); 
    }
    media = soma / n;
    if ((n * media) != soma){
      printf("-1\n");
    } else {
    
      for (int i = 0; i < n; i++){
        distancia =  abs(notas[i] - media);
        distancia_total += distancia;
      }
    compassos = (distancia_total / (2)) + 1;
    //printf("\n%d\n", n);
    printf("%d\n", compassos);
    }
  }
}
