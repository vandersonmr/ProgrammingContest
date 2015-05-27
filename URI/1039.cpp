#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main() {
  int Rc, Xc, Yc;
  int Rf, Xf, Yf;
  while (scanf("%d %d %d %d %d %d", &Rc, &Xc, &Yc, &Rf, &Xf, &Yf) != EOF) {
    float d = std::sqrt(std::pow(Xc - Xf, 2) + std::pow(Yc - Yf, 2));
    if (d + Rf <= Rc && std::abs(d - Rf) <= Rc) 
      printf("RICO\n");
    else
      printf("MORTO\n");
  }
  return 0;
}
