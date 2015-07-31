#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;

void flipV(int* dado) {
  int aux;
  aux = dado[5];
  dado[5] = dado[3];
  dado[3] = dado[0];
  dado[0] = dado[1];
  dado[1] = aux;
}

void flipH(int* dado) {
  int aux;
  aux = dado[4];
  dado[4] = dado[3];
  dado[3] = dado[2];
  dado[2] = dado[1];
  dado[1] = aux;
}

string getString(int* dado) {
  char s[10];
  sprintf(s, "%d%d%d%d%d%d", dado[0], dado[1], dado[2], dado[3], dado[4], dado[5]);
  return string(s);
}

int justDoIt(int dados[][6], int tam) {
  map<string, int> maluco;
  int n = 0;
  for (int q = 0; q < tam; q++) {
    int* dado = dados[q];
    if (maluco.count(getString(dado)) == 0) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          flipH(dado);
          maluco[getString(dado)] = n;
        }
        flipV(dado);
      }

      flipH(dado);
      flipV(dado);
      for (int j = 0; j < 4; j++) {
        maluco[getString(dado)] = n;
        flipH(dado);
      }

      flipV(dado);
      flipV(dado);
      for (int j = 0; j < 4; j++) {
        maluco[getString(dado)] = n;
        flipH(dado);
      }
      n++;
    } 
  }
  return n;
} 

int main() {
  int n;
  while (true) {
    scanf("%d", &n);
    if (n == 0) break;
    int dados[n][6];
    for (int i = 0; i < n; i++) {
      scanf("%d\n", &dados[i][0]);
      scanf("%d %d %d %d\n", &dados[i][1], &dados[i][2], &dados[i][3], &dados[i][4]);
      scanf("%d\n", &dados[i][5]);
    }
    int res = justDoIt(dados, n);
    printf("%d\n", res);
  }
  return 0;
}
