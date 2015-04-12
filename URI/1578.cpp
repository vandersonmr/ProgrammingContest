#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    int s;
    scanf("%d", &s);
    unsigned long long int matriz[s*s];
    int max[s];
    for(int j=0;j < s; j++) 
      max[j] = 0;
    for(int j =0; j < s*s; j++) {
      unsigned long long int p;
      scanf("%llu", &p);
      matriz[j] = p*p;
      int k = 0;
      p = matriz[j];
      while(p != 0) { 
        p /= 10;
        k++;
      }
      if(k > max[j%s])
        max[j%s] = k;
    }   

    printf("Quadrado da matriz #%d:", i+4);

    for(int j=0; j < s*s; j++) {
      if(j%s == 0 && s != 0) {
        printf("\n");
      }
      if(j%s == (s-1))
        printf("%*llu", max[j%s], matriz[j]);
      else
        printf("%*llu ", max[j%s], matriz[j]);
    }
    if(i == (n-1)) 
      printf("\n");
    else
      printf("\n\n");
  }
}
