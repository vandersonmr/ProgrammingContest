#include <stdio.h>
#include <cmath>

int main(){
  double pi = 3.141592654;
  double a, b, c;
  while (scanf("%lf", &a) != EOF){
    scanf("%lf %lf", &b, &c);
    double co = tan((a*pi)/180) * b;
    double cordao = (co + c) * 5;
    printf("%.2lf\n", cordao);
  }
}
