#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
  int s = 0;
  scanf("%d\n", &s);
  for (int i = 0; i < s; i++) {
    int t = 0;
    scanf("%d ", &t);
    vector<char> row;
    long long int res = 0;
    long long int total = 0;
    for (int j = 0; j < t+1; j++) {
      char h = 0;
      scanf("%c", &h);
      h -= '0';
      long long int aux = 0;
      if (h != 0) {
        if (total < j) {
          aux += abs(j - total);
        }
      }
      
      total += h + aux; 
      res += aux;
    }
    scanf("\n");
    printf("Case #%d: %lld\n", i+1, res);
  }
}
