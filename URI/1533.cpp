//http://www.urionlinejudge.com.br/judge/pt/problems/view/1533
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
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

int main() {
    char *p = readSTDIN();
    char *end_punch;
    char *punch = strtok_r(p,"\n",&end_punch);
    int n = atoi(punch);
    while (n != 0) {
        punch = strtok_r(NULL, "\n",&end_punch);
        char *end_punch2;
        int maior=0; 
        int quase_maior=0;
        char *punch2 = strtok_r(punch, " ", &end_punch2);
        int i = 0;
        int quase_maiori = 0;
        int maiori = 0;
        while (punch2 != NULL){
            i++;
            int magia = atoi(punch2);
            if (magia > maior){
                quase_maior = maior;
                maior = magia;
                quase_maiori = maiori;
                maiori = i;
            }else if(magia > quase_maior){
                quase_maior = magia;
                quase_maiori = i;
            }
            punch2 = strtok_r(NULL, " ",&end_punch2);
        }
        punch = strtok_r(NULL, "\n",&end_punch);
        // COMEÇA AQUI O POG
        if (punch == NULL) break;
        //
        //
        printf("%d\n", quase_maiori);
        int n = atoi(punch);
    }
    

    return 0;
}
