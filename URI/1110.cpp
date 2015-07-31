#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main() {
  int n;
  while(scanf("%d\n", &n)) {
    if (n == 0) break;
    queue<int> deck;
    printf("Discarded cards:");
    bool first = true;
    for (int i = 1; i <= n; i++) 
      deck.push(i);

    while (deck.size() > 1) {
      if (first) {
        first = false;
        printf(" %d", deck.front());
      } else {
        printf(", %d", deck.front());
      }
      deck.pop();
      deck.push(deck.front());
      deck.pop();
    }
    printf("\nRemaining card: %d\n", deck.front());
  }
  return 0;
}
