#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define BUF_SIZE 1024
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

int main(){
  char* entrada = readSTDIN();
  int num = atoi(entrada);
  int ano = num/365;
  int meses = (num - ano*365) / 30;
  int dias = (num - ano*365 - meses*30) / 1; 
  printf("%d ano(s)\n",ano);
  printf("%d mes(es)\n",meses);
  printf("%d dia(s)\n",dias);
  return 0;
}
