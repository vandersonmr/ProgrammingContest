#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main() {
  double a;
  while (scanf("%lf", &a) != EOF) {
    double Sqrt = a*a;
    double Circ = (M_PI * a*a)/4;
    double Btw = a*a * (((2*M_PI)/3) - (std::sqrt(3)/2));   
    double C = Sqrt - 4*Circ + 2*Btw;
    double A = Sqrt - 2*Circ + Btw/2;
    double B = 3*Circ - Btw - Sqrt;
    printf("%.3lf %.3lf %.3lf\n", C, B*4, A*4);
  }
  return 0;
}
