#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef struct curso {
  bool basic;
  string name;
  int weight;
  vector<string> edges;

  curso(string n, bool b, int w) {
    basic = b;
    name = n;
    weight = w;
  }

  curso() {};
} curso;

struct Comp {
  bool operator()(curso& a, curso& b) {
    return a.weight < b.weight;
  }
};

bool blah(const curso& a, const curso& b) {
  return a.name < b.name;
}

int main() {
  while (true) {
    int n, m;
    scanf("%d %d\n", &n, &m);
    if (n == 0 && m == 0) break;
    map<string, curso> G;  
    map<string, int> inc;  
    int maxV = n;
    int geral = 9999999;
    for (int i = 0; i < n; i++) {
      geral--;
      char name[8]; 
      int s;
      scanf("%s %d", name, &s);
      string sName(name);
      if (G.count(sName) == 0)
        G.insert(pair<string, curso>(sName, curso(sName, false, geral)));
      else
        G[sName].basic = false;

      for (int j = 0; j < s; j++) {
        geral--;
        char depName[8];
        scanf("%s", depName);
        string sDepName(depName);
        if (G.count(sDepName) == 0) 
          G.insert(pair<string, curso>(sDepName, curso(sDepName, true, geral)));
        G[sDepName].edges.push_back(sName);
        if (inc.count(sName) == 0)
          inc[sName] = 1;
        else
          inc[sName] += 1;
      } 
      scanf("\n");
    }

    map<string, curso>::iterator it;
    priority_queue<curso, vector<curso>, Comp> cut;

    for (it = G.begin(); it != G.end(); ++it) {
      curso e = (*it).second;
      if (inc.count(e.name) == 0) 
        cut.push(e);
    }

    int k = 0;
    vector<vector<curso> > semestres;
    while (!cut.empty()) {
      semestres.push_back(vector<curso>());
      while (semestres[k].size() < m && !cut.empty()) {
        curso c = cut.top();
        cut.pop();
        semestres[k].push_back(c);
      }
      for (int j = 0; j < semestres[k].size(); j++) {
        for(int h = 0; h < semestres[k][j].edges.size(); h++) {
          inc[semestres[k][j].edges[h]] -= 1;
          if (inc[semestres[k][j].edges[h]] == 0)
            cut.push(G[semestres[k][j].edges[h]]);
        }
      }
      k++;
    }   
    printf("Formatura em %lu semestres\n", semestres.size());
    for (int j = 0; j < semestres.size(); j++) {
      printf("Semestre %d :", j+1);
      sort(semestres[j].begin(), semestres[j].end(), blah);
      for (int h = 0; h < semestres[j].size(); h++) {
        printf(" %s", semestres[j][h].name.c_str());
      }
      printf("\n");
    }
  }
  return 0;
}
