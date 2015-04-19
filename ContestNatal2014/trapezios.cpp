#include <stdio.h>

int main(){
  int t, q;
  double a,b;
  while (scanf("%d", &t) != 0){
    double area;
    if (t == 0) goto fim;
    for (int i = 0; i < t; i++){
      scanf("%d %lf %lf", &q, &a, &b);
      area = (((a + b) * 5.0) / 2.0);
      printf("Size #%d:\n", i+1);
      printf("Ice Cream Used: %.2lf cm2\n", q * area);
    }
    printf("\n");
  }

fim:
  return 0;
}
