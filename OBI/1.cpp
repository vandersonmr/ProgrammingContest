#include <vector>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  for(int i=0;i < n;i++) {
    int d;
    scanf("%d", &d);
    for(int j=0; j < d; j++) {
      int f;
      scanf("%d", &f);
      if(f == 1) {
        cout << "Rolien" << endl;
      }else if(f == 2){
        cout << "Naej" << endl;
      }else if(f == 3) {
        cout << "Elehcim" << endl;
      }else if(f == 4) {
        cout << "Odranoel" << endl;
      }
    }
  }
  return 0;
}
