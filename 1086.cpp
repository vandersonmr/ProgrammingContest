//http://www.urionlinejudge.com.br/judge/pt/problems/view/1086
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

void merge(int vec[], int vecSize) {
    int mid;
    int i, j, k;
    int* tmp;

    tmp = (int*) malloc(vecSize * sizeof(int));
    if (tmp == NULL) {
        exit(1);
    }

    mid = vecSize / 2;

    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < vecSize) {
        if (vec[i] >= vec[j]) {
            tmp[k] = vec[i++];
        }
        else {
            tmp[k] = vec[j++];
        }
        ++k;
    }

    if (i == mid) {
        while (j < vecSize) {
            tmp[k++] = vec[j++];
        }
    }
    else {
        while (i < mid) {
            tmp[k++] = vec[i++];

        }
    }

    for (i = 0; i < vecSize; ++i) {
        vec[i] = tmp[i];
    }

    free(tmp);
}

void mergeSort(int vec[], int vecSize) {
    int mid;

    if (vecSize > 1) {
        mid = vecSize / 2;
        mergeSort(vec, mid);
        mergeSort(vec + mid, vecSize - mid);
        merge(vec, vecSize);
    }
}

int recursou(int t, int tm, int s, int v[], int l){
    if (t > tm) return -1;
    if (s == l) return 0;
    if (s > l) return -1;
    if (v[t] == -1) return recursou(t+1,tm,s,v,l);
    int recur = recursou(t+1,tm,s+v[t],v,l);
    if (recur == -1){
        return recursou(t+1,tm,s,v,l);
    } else{
        v[t] = -1;
        return 1+recur;
    }
}

char *end_punch;
int main() {
    char *p = readSTDIN();
    char *punch = strtok_r(p,"\n",&end_punch);
    int m,n,linha,coluna;
    sscanf(punch, "%d %d", &m, &n);
    while ((n*m) != 0) {
        punch = strtok_r(NULL, "\n",&end_punch);
        if (punch == NULL) break;
        int largura = atoi(punch);
        punch = strtok_r(NULL, "\n",&end_punch);
        int quantidade = atoi(punch);
        punch = strtok_r(NULL, "\n",&end_punch);
        char *end_punch3;
        char *punch3 = strtok_r(punch, " ", &end_punch3);
        int alturas[quantidade];
        int i = 0;
        while (punch3 != NULL){
            alturas[i] = atoi(punch3);
            punch3 = strtok_r(NULL, " ",&end_punch3);
            i++;
        }
        int soma = 0;
        merge(alturas,quantidade);
        if (((m*100) % largura == 0)){
            coluna = (m*100)/largura;
            linha = n;
        } else if((n*100) % largura == 0){
            coluna = (n*100)/largura;
            linha = m;
        } else {
            printf("impossivel\n");
            goto fim;
        }
        for (int i = 0; i < coluna; i++){
            int aux = recursou(0,quantidade,0,alturas,linha);
            //printf("%d\n",aux);
            if (aux == -1){
                printf("impossivel\n");
                goto fim;
            }
            soma += aux;
        }
        printf("%d\n", soma);
fim:
        punch = strtok_r(NULL,"\n",&end_punch);
        sscanf(punch, "%d %d", &m, &n);
    }
    return 0;
}
