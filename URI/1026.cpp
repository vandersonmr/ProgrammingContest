#include <stdlib.h>
#include <stdio.h>

int main() {
  unsigned A, B;
  while (scanf("%u %u\n", &A, &B) != EOF) {
    printf("%u\n", (~A & B) ^ (~B & A));
  }
  return 0;
}
