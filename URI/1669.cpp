#include <stdio.h>
#include <stdlib.h>

#include <list>
#include <vector>

using namespace std;

int main() {
  while (true) {
    int n1, n2, d;
    scanf("%d %d %d", &n1, &n2, &d);
    if (n1 == 0 && n2 == 0 && d == 0) break;
    vector<vector<int> > Dep(n1+n2+2);

    bool Instalado[n1+n2+2];

    for (int i = 0; i < d; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      Dep[x].push_back(y);
    }

    int min = 99999999;
    for (int t = 1; t <= 2; t++) {
      for (int i = 0; i < n1+n2+2; i++) 
        Instalado[i] = false;
      int CD1 = t;
      int r = 2;
      int in1 = 0;
      int in2 = n1;
      while (in1 < n1 || in2 < n1+n2+1) {
        int j;

        if (in1 == n1 && CD1 == 1)      { CD1 = 2; r++; };
        if (in2 == n1+n2+1 && CD1 == 2) { CD1 = 1; r++; };

        if (CD1 == 1) j = ++in1;
        if (CD1 == 2) j = ++in2;

        if (!Instalado[j]) {
          list<int> Queue;
          Queue.push_back(j);

          while (Queue.size() > 0) {
            int x = Queue.front();
            Instalado[x] = true;

            if (x <= n1) {
              if (CD1 != 1) r++;
              CD1 = 1;
            } else {
              if (CD1 != 2) r++;
              CD1 = 2;
            }

            Queue.pop_front();
            for (int i = 0; i < Dep[x].size(); i++) { 
              if (!Instalado[Dep[x].at(i)]) 
                Queue.push_back(Dep[x].at(i));
            } 
          }
        }
      }
      if (r < min) {
        min = r;
      }
    }
    printf("%d\n", min);
  }
  return 0;
}
