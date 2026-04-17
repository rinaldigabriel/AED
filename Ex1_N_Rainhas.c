#include<stdio.h>
#include<string.h>

int cont = 0;

void desfaz(int n, int tab[n][n],int lin, int col){

    tab[lin][col] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(lin == i && col == j){
                continue;
            }
            else if(i == lin){
                tab[i][j] -= 1;
            }
            else if(j == col){
                tab[i][j] -= 1;
            }
            else if(lin - i == col - j){
                tab[i][j] -= 1;
            }
            else if(lin - i == j - col){
                tab[i][j] -= 1;
            }
        }
    }

}

void preenche(int n, int tab[n][n], int lin, int col){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == lin && j == col){
                continue;
            }

            if(i == lin){
                tab[i][j] += 1;
            }
            else if(j == col){
                tab[i][j] += 1;
            }
            else if(lin - i == col - j){
                tab[i][j] += 1;
            }
            else if(lin - i == j - col){
                tab[i][j] += 1;
            }
        }
    }
}

void posiciona(int n, int tab[n][n], int lin){

    if(lin == n){
        cont+=1;
        return;
    }

    for(int col = 0; col < n; col++){
        if(tab[lin][col] == 0){
            tab[lin][col] = -1;
            preenche(n, tab, lin, col);

            posiciona(n, tab, lin + 1);

            desfaz(n, tab, lin, col);
            tab[lin][col] = 0;
        }
    }


}

int main(){
    int n;

    scanf("%i", &n);

    int tab[n][n];

    memset(tab, 0, sizeof(tab));


    posiciona(n, tab, 0);

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%i ", tab[i][j]);
        }
        printf("\n");
    }*/
    

    printf("%i", cont);
}

 