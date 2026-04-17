#include <stdio.h>
#include <stdbool.h>

void gerar(int atual[], bool usado[], int n, int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", atual[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!usado[i]) {
            usado[i] = true;
            atual[pos] = i;

            gerar(atual, usado, n, pos + 1);

            // backtracking
            usado[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int atual[n];           // guarda a sequência atual
    bool usado[n + 1];      // marca quais números já foram usados

    for (int i = 0; i <= n; i++) {
        usado[i] = false;
    }

    gerar(atual, usado, n, 0);

    return 0;
}