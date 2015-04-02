#include <iostream>
#include <ostream>
#include <cstdio>

using namespace std;

int doOperation(int a, int b, int d1, int d2, char op){
  if      (op == '+') return (a*d2) + (b*d1);
  else if (op == '-') return (a*d2) - (b*d1);
  else if (op == '*') return a * b;
  else if (op == '/') return (a*d2);
}

int doBase(int a, int b, int d1, int d2, char op){
  if      (op == '+') return d1*d2;
  else if (op == '-') return d1*d2;
  else if (op == '*') return d1*d2;
  else if (op == '/') return (b*d1);
}

int abs(int a){
  if (a < 0) return -a;
  else return a;
}

int mmc(int a, int b){
  int min = a < b? a : b;
  int mmc = 1;
  for(int i =1; i <= abs(min); i++) {
    if(((a%i) == 0) && ((b%i) == 0))
      mmc = i;
  }
  return mmc;
}

int n = 0;
int a,b,c,d;
char o1,o2,o3;
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d %c %d %s %d %s %d", &a, &o1, &b, &o2, &c, &o3, &d);
    int top = doOperation(a,c,b,d, o2);
    int base = doBase(a,c,b,d, o2);
    cout << top<<"/"<<base<<" = "
      << top/mmc(top,base) << "/" << base/mmc(top,base)<< endl;
  }
  return 0;
}
