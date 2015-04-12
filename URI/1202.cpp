#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define BUF_SIZE 102400
char buffer[BUF_SIZE];
size_t contentSize = 1;

char* readSTDIN(){
  char *content = (char*) malloc(sizeof(char) * BUF_SIZE);
  if(content == NULL)
  {
    perror("Failed to allocate content");
    exit(1);
  }

  content[0] = '\0';

  while(fgets(buffer, BUF_SIZE, stdin))
  {
    char *old = content;
    contentSize += strlen(buffer);
    content = (char*) realloc(content, contentSize);
    if(content == NULL)
    {
      perror("Failed to reallocate content");
      free(old);
      exit(2);
    }
    strcat(content, buffer);
  }
  return content;
}

int pow(int a){
  int c =1;
  for(int i=0;i<a;i++){
    if(i==0){
      c = 2;
    }else{
      c *= 2;
    }
    c = c % 1500;
  }
  return c;
}

int convertToBinary(char* bin) {
  int tam = strlen(bin);
  int dec = 0;
  int i;
  for(i=0; i<tam; i++) { 
    dec <<= 1;
    if(*bin == '1')
      dec |= 1;
    dec = dec % 1500;
    bin++;
  }
  return dec;
}

long long fib(int n) {
  n = n % 1500;
  long long n1 = 1, n2 = 1, aux = 0, i;
  for(i=3; i<n+1; i++){
    aux = n1;
    n1 = (n1 + n2) % 1000;
    n2 = aux;
  }
  return n1;
}

int main(){
  char *p = readSTDIN();
  char *punch = strtok(p, "\n");
  int i = 0;
  int size = atoi(punch);
  while(punch != NULL && i != size) {
    if(i == 0)  {
      punch = strtok(NULL, "\n");
    }
    i++;
    printf("%03lld\n", fib(convertToBinary(punch)));

    punch = strtok(NULL, "\n");
  }
  return 0;
}
