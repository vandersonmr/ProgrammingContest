#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rena {
  int peso, idade;
  float altura;
  char nome[101];

  bool operator< (const &Rena a) const {
    if (a.peso < peso) return true;
    else if (a.peso == peso) {
      if (idade < a.idade) return true;
      else if (idade == a.idade) {
        if (altura < a.altura) return true;
        else if (altura == a.altura) {
          int i = 0;
          char a = nome[i];
          char b = a.nome[i];
          while (i < 100 && a != '\0' && b != '\0') {
            if (a <= 90) a += 32;
            if (b <= 90) b += 32;
            if (a < b) return true;
            i++;
            a = nome[i];
            b = a.nome[i];
          }
        }
      }
    }
    return false;
  }
};

int main() {
  int i;
  scanf("%d\n", i);
  for () {
  return 0;
}
