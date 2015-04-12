#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
using namespace std;

map<string, int> pd;

int rec(int a, int max_coin) {
	int i, aux, knuth;
    knuth = 0;
    char buffer[1000];
    sprintf(buffer,"%d|%d",max_coin, a);
    if(pd.count(string(buffer)) > 0){
        return pd[string(buffer)];
    }
	if(max_coin >= 50 && a >= 50) {
        aux = a%50;
        knuth += rec(aux, 25);
        for(i=1;i<(a/50);i++){
            aux += 50;
            knuth += rec(aux, 25);
        }
    }
    if(max_coin >= 25 && a >= 25) {
        aux = a%25;
        knuth += rec(aux, 10);
        for(i=1;i<(a/25);i++){
            aux += 25;
            knuth += rec(aux, 10);
        }
    }
	if(max_coin >= 10 && a >= 10){
        aux = a%10;
        knuth += rec(aux, 5);
        for(i=1;i<(a/10);i++){
            aux += 10;
            knuth += rec(aux, 5);
        }
	
    }
    if(max_coin >= 5 && a >= 5){
        aux = a%5;
        knuth += rec(aux, 1);
        for(i=1;i<(a/5);i++){
            aux += 5;
            knuth += rec(aux, 1);
        }
    }
	if(a >= 1){ 
		knuth += 1;
    }
   pd[string(buffer)] = knuth;
	return knuth;
}

int main(){
	int n;
	while (scanf("%d", &n) != EOF){
		printf("%d\n", rec(n, 50));	
	}
}
