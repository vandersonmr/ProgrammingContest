#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int size;
  scanf("%d", &size); 
  vector<int> numbers;
  for(int i=0; i < size; i++) {
    int n;
    scanf("%d", &n);
    numbers.push_back(n);
  }
  sort(numbers.begin(), numbers.end());
  int ant = numbers[0];
  int t = 0;
  for(int i=0; i < size; i++) {
    if(numbers[i] != ant) {
      printf("%d aparece %d vez(es)\n", ant, t);
      t = 1;
      ant = numbers[i];
    } else {
      t++;
    }
  }
  printf("%d aparece %d vez(es)\n", ant, t);
  return 0;
}
