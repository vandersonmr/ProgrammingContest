#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int T = 0;
  scanf("%d\n", &T);
  for (int t = 0; t < T; t++) {
    vector<long long int> plates;
    int D;
    scanf("%d\n", &D);
    for (int i = 0; i < D; i++) {
      long long int k = 0;
      scanf("%lld", &k);
      plates.push_back(k);
    }
    sort(plates.rbegin(), plates.rend());
    long long int maxRound = plates[0];
    long long int minTime = 9999999999999999;
    for (int r = 1; r <= maxRound + 1; r++) {
      long long int moveRound = 0;
      for (auto plate : plates) {
        if (plate <= r)
          break;
        moveRound += ceil(plate/r) - 1;
        printf("%r = %d | plate: %lld - moveRound: %lld\n", r,plate, moveRound);
      }
      if (moveRound + r < minTime)
        minTime = moveRound + r;
    } 
    printf("Case #%d: %lld\n", t+1, minTime);
  }
  return 0;
}
