#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

class carro {
  public:
    int placa;
    int comprimento;
};

class vaga {
  public:
    carro a;
    bool ocp;
    int tamanho;
};

int main(){
  int c, n;
  while (scanf("%d %d\n", &c, &n) != EOF){
    char evento;
    int placa, comprimento_carro;
    list<vaga> garagem;
    vaga v;
    v.ocp = false;
    v.tamanho = c;
    int t = c;
    garagem.push_back(v);
    int resultado = 0;
    for (int i = 0; i < n; i++){
      list<vaga>::iterator it;
      scanf("%c\n", &evento);
      if (evento == 'C'){
        scanf("%d %d\n", &placa, &comprimento_carro);
        list<vaga>::iterator it;
        for(it = garagem.begin(); it != garagem.end(); it++){
          if(!(*it).ocp) {
            if((*it).tamanho == comprimento_carro) {
              (*it).ocp = true;
              carro a;
              a.placa = placa;
              a.comprimento = comprimento_carro;
              (*it).a = a;
              resultado+=10;
              it = garagem.end();
              break;
            } else if((*it).tamanho > comprimento_carro) {
              carro a;
              a.placa = placa;
              a.comprimento = comprimento_carro;
              vaga v1;
              v1.a = a;
              v1.tamanho = comprimento_carro;
              v1.ocp = true;
              garagem.insert(it, v1);
              (*it).tamanho = (*it).tamanho - comprimento_carro;
              resultado +=  10;
              it = garagem.end();
              break;
            }
          }
        }

      } else {
        scanf("%d\n", &placa);
        list<vaga>::iterator it;
        list<vaga>::iterator prev;
        list<vaga>::iterator next;

        for(it = garagem.begin(); it != garagem.end(); it++){
          if(it != garagem.begin()) {
            prev = it;
            prev--;
          }
          if(++it != garagem.end()) {
            next = it;
            next++;
          }
          --it;

          if((*it).ocp) {
            if((*it).a.placa == placa) {
              (*it).ocp = false;
              if(it != garagem.begin()) {
                if(!(*prev).ocp) {
                  int z = (*(prev)).tamanho;
                  (*(it)).tamanho += z;
                  it = garagem.erase((prev));
                }
              }
              if(it != garagem.end()) {
                if(++it != garagem.end()) {
                  if(!(*it).ocp) {
                    int z = (*it).tamanho;
                    (*(--it)).tamanho += z;
                    it = garagem.erase((++it));
                  }
                }
              }
              break;
            }
          }
        }
      }
    }
    cout << resultado << endl;
  }
}


