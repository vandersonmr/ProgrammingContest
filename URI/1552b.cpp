#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>

#define MAX 505

using namespace std;

typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef pair<double,ii> dii;

int pai[MAX], ranking[MAX];
set<dii> adj;

void unir(int a, int b){
  if(ranking[a] >= ranking[b]){
    pai[b] = a;
    if(ranking[a] == ranking[b])
      ranking[a]++;
  }else
    pai[a] = b;
}

int encontrar(int n){
  if(pai[n]==n)
    return n;
  else
    return pai[n] = encontrar(pai[n]);
}

double kruskal(){
  int a, b;
  double res = 0;
  dii v;
  while(!adj.empty()){
    v = *adj.begin();
    adj.erase(adj.begin());
    a = encontrar(v.second.first);
    b = encontrar(v.second.second);
    if(a != b){
      unir(a,b);
      res += v.first;
    }
  }
  return res;
}

int main(){
  long int c;
  int n;
  double x, y, dist;
  dd v[MAX];

  scanf("%ld", &c);
  for(long int i = 0; i < c; i++){
    scanf("%d", &n);
    for(int j = 1; j <= n; j++){
      pai[j] = j;
      ranking[j] = 0;
      scanf("%lf %lf", &x, &y);
      v[j] = dd(x,y);
      for(int k = j-1; k >= 1; k--){
        dist = sqrt(pow(v[j].first - v[k].first,2) + pow(v[j].second - v[k].second,2));
        adj.insert(dii(dist/100,ii(j,k)));
      }
    }
    printf("%.4lf\n", kruskal());
  }

  return 0;
}
