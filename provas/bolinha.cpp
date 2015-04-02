#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
class ponto {
  public:
    float x,y;
};

class reta {
  public:
    ponto p1,p2;
    float a,b;
    void eqReta() {
      a = (p1.y - p2.y)/(p1.x - p2.x);
      b = (p1.y - a*p1.x);
//      printf("aeb %f %f %f %f %f %f\n", a,b, p1.x, p1.y, p2.x, p2.y);
    }
};

int main() {
  int n;
  int l,h;
  while(scanf("%d", &n) != EOF) {
    vector<reta> v;
    scanf("%d %d", &l, &h);
    int par = 0;
    for(int i =0; i <n; i++) {
      int a,b,c;
      reta t;
      ponto p1,p2;
      scanf("%d %d %d",&a,&b,&c);
      if(par == 0){
        p1.x = 0;
        p1.y = a;
        p2.x = b;
        p2.y = c;
        par = 1;
      } else {
        p1.x = l;
        p1.y = a;
        p2.x = b;
        p2.y = c;
        par = 0;
      }
      t.p1 = p1;
      t.p2 = p2;
      t.eqReta();
      v.push_back(t);
    }
    double menor = h;
    for(int i =0; i<v.size(); i++) {
      if(v[i].p1.x == 0) {
        if(menor > (l - v[i].p2.x)) {
          menor = l-v[i].p2.x;
        }
      }else if(menor > (v[i].p2.x)) {
        menor = v[i].p2.x; 
      }

      if(i+1 < v.size()) {
        
        if(maisMenor < menor) {
          menor = maisMenor;
        }
      }
    }

    printf("%.2f\n", menor);
  }
  return 0;
}
