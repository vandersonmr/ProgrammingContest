#include <cstdio>

int main() {
  while(true){
    int n;
    scanf("%d\n", &n);
    if (n == 0) return 0;
    int alunos[n];
    char rest[10000];
    scanf("%[^\n]", rest);
    for(int i=0; i < n; i++) {
      int who;
      sscanf(rest, "%d %[^\n]", &who, rest);
      alunos[i] = who;
    }
    int start;
    scanf("%d", &start);

    int i = start-1;
    int next = alunos[i]-1;
    while(next != i) {
      i = next;
      next = alunos[i]-1;
    }
    printf("%d\n", i+1);
  }
  return 0;
}
