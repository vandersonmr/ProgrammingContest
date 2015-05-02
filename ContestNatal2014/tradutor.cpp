#include <cstring>
#include <stdio.h>

int main() {
  char x[1000];
  while(scanf("%s", x) != EOF) {
    if(strcmp(x,"brasil") == 0) printf("%s\n", "Feliz Natal!");
    else if(strcmp(x,"alemanha") == 0) printf("%s\n", "Frohliche Weihnachten!");
    else if(strcmp(x,"austria") == 0) printf("%s\n", "Frohe Weihnacht!");
    else if(strcmp(x,"coreia") == 0) printf("%s\n", "Chuk Sung Tan!");
    else if(strcmp(x,"espanha") == 0) printf("%s\n", "Feliz Navidad!");
    else if(strcmp(x,"grecia") == 0) printf("%s\n", "Kala Christougena!");
    else if(strcmp(x,"estados-unidos") == 0) printf("%s\n", "Merry Christmas!");
    else if(strcmp(x,"inglaterra") == 0) printf("%s\n", "Merry Christmas!");
    else if(strcmp(x,"australia") == 0) printf("%s\n", "Merry Christmas!");
    else if(strcmp(x,"portugal") == 0) printf("%s\n", "Feliz Natal!");
    else if(strcmp(x,"suecia") == 0) printf("%s\n", "God Jul!");
    else if(strcmp(x,"turquia") == 0) printf("%s\n", "Mutlu Noeller");
    else if(strcmp(x,"argentina") == 0) printf("%s\n", "Feliz Navidad!");
    else if(strcmp(x,"chile") == 0) printf("%s\n", "Feliz Navidad!");
    else if(strcmp(x,"mexico") == 0) printf("%s\n", "Feliz Navidad!");
    else if(strcmp(x,"antardida") == 0) printf("%s\n", "Merry Christmas!");
    else if(strcmp(x,"canada") == 0) printf("%s\n", "Merry Christmas!");
    else if(strcmp(x,"irlanda") == 0) printf("%s\n", "Nollaig Shona Dhuit!");
    else if(strcmp(x,"belgica") == 0) printf("%s\n", "Zalig Kerstfeest!");
    else if(strcmp(x,"italia") == 0) printf("%s\n", "Buon Natale!");
    else if(strcmp(x,"libia") == 0) printf("%s\n", "Buon Natale!");
    else if(strcmp(x,"siria") == 0) printf("%s\n", "Milad Mubarak!");
    else if(strcmp(x,"marrocos") == 0) printf("%s\n", "Milad Mubarak!");
    else if(strcmp(x,"japao") == 0) printf("%s\n", "Merii Kurisumasu!");
    else printf("--- NOT FOUND ---\n");
  }
  return 0;
}
