#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n, m, k;

  while (scanf("%d %d %d\n", &n, &m, &k) != EOF) {
    vector<int> amizades(n+1);
    vector<vector<int>* > *amigos = 
      new vector<vector<int>* >(n+1);

    for (int i = 1; i <= n; i++) {
      amizades[i] = 0;
      (*amigos)[i] = new vector<int>;
    }

    for (int j = 0; j < m; j++) {
      int a, b;
      scanf("%d %d\n", &a, &b);
      amizades[a]++;
      amizades[b]++;
      (*amigos)[a]->push_back(b);
      (*amigos)[b]->push_back(a);
    }

    map<int, bool> tabu;
    bool cont = true;
    while(cont) {
      cont = false;
      for (int i = 1; i < n+1; i++) {
        if (tabu.count(i) == 0) {
          int o = 0;
          for (int j = 0; j < (*amigos)[i]->size(); j++) {
            if (tabu.count((*amigos)[i]->at(j)) == 0)
              o += 1;
          }

          if (o < k) {
            cont = true;
            tabu[i] = false;
            for (int j = 0; j < (*amigos)[i]->size(); j++) {
              amizades[(*amigos)[i]->at(j)] -= 1;
            }
          }
        }
      }
    }

    vector<int> s;
    for (int i = 1; i < n+1; i++) {
      if (tabu.count(i) == 0) {
        s.push_back(i);
      }
    }

    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
      if (i == (s.size()-1))  
        printf("%d", s[i]);
      else
        printf("%d ", s[i]);
    }
    if(s.size() == 0) printf("0");
    printf("\n");
  }

  return 0;
}
