#include <stdio.h>
#include <math.h>

int main(){
  double l;
  while (scanf("%lf", &l) != EOF){
    double area;
    area = ((2 * sqrt(3)) / 5) * (l * l);
    printf("%.2lf\n", area);
  }
  return 0;
}
