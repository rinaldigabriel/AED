#include<stdio.h>

int cont = 0;

void particoes(int n, int max, int atual[], int tam){
    if(n == 0){
        cont +=1;
        return;
    }

    for(int i = max; i >= 1; i--){
        if(i <= n){
            atual[tam] = i;
            particoes(n - i, i, atual, tam + 1);
        }
    }
}

int main(){
    int n;

    scanf("%i", &n);

    int part[n];

    particoes(n, n, part, 0);

    printf("%i", cont);
}