#include <stdio.h>

int main() {
  while(true) {
    int d;
    scanf("%d", &d);
    if(d == 0) break;
    for(int i=0; i < d;i++) {
      int aws[5] = {0, 0, 0, 0, 0};
      scanf("%d %d %d %d %d", &aws[0], &aws[1], &aws[2], &aws[3], &aws[4]);
      bool good = true;
      int a = -1;
      for(int j=0; j < 5; j++) {
        if(aws[j] <= 127 && aws[j] >= 0) {
          if(a != -1) {
            good = false;
            break;
          }
          a = j;
        } 
      }
      if(!good || a == -1) {
        printf("*\n");
      } else {
        printf("%c\n", 'A'+a);
      }
    }
  }
  return 0;
}
