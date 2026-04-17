#include <stdio.h>

int ans = 0;

void percorre(int n, int m[n][n], int i, int j){    // avanca nas direcoes e se for local inacessivel ele volta, se nao for ele continua

    if(i < 0 || i >= n || j < 0 || j >= n){         // define os limites da matriz
        return;
    }

    if(m[i][j] != 1){                               // define os acessos diferente de 1
        return;
    }

    if(i == n-1 && j == n-1){                       // define a resposta se chegar no final
        ans = 1;
        return;
    }

    m[i][j] = -1;                                   // define os caminhos que ja foram passados

    percorre(n, m, i+1, j);                         // prioriza descer
    percorre(n, m, i-1, j);
    percorre(n, m, i, j+1);                         // prioriza ir para a direita
    percorre(n, m, i, j-1);
}                                                   // por conta de otimizacao a ordem de chamada importa


int main(){
    int n;

    scanf("%i", &n);

    int m[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%i", &m[i][j]);
        }
    }

    /*(for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }*/

    percorre(n, m, 0, 0);

    printf("%i", ans);
}
