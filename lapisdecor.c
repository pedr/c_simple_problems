#include <stdio.h>
#include <stdlib.h>

int main() {

    // pergunta qual a dimensão do mapa, sempre quadrado
    int tamanho;
    scanf("%d", &tamanho);

    // segundo parametro precisa ser +1 porque string precisa de \0 no final
    char mapa[tamanho][tamanho+1];
    int mapaFinal[tamanho][tamanho];

    int i = 0;
    // le as linhas com os simbolos ** e 00, ambos char
    for (i = 0; i < tamanho; i++) {
            scanf("%s", mapa[i]);
    }

    int k = 0;
    for (i = 0; i < tamanho; i++) {
        for (k = 0; k < tamanho; k++) {
            if (mapa[i][k] == '0') {
                mapaFinal[i][k] = 0;
            } else {
                mapaFinal[i][k] = -1;
            }
        }
    }

/*
    // visualização do mapa
    for (int i = 0; i < tamanho; i++) {
        printf("%s", mapa[i]);
        printf("\n");
    }
*/

    // uso char porque é string
    int numeroBase = 0;
    int numeroAdicionado = 1;

    int modificado;

    do {

    // int usado para testar se devo continuar a mudar o mapa
    // é resetado a cada passada, se nada for modificado, o while é falso
    // e o loop termina
    modificado = 0;

        for (i = 0; i < tamanho; i++) {
            for (k = 0; k < tamanho; k++) {
                if (mapaFinal[i][k] == numeroBase) {
                    if (mapaFinal[i+1][k] == -1)  {
                        mapaFinal[i+1][k] = numeroAdicionado;
                        modificado = 1;
                    }
                    if (mapaFinal[i-1][k] == -1) {
                        mapaFinal[i-1][k] = numeroAdicionado;
                        modificado = 1;
                    }
                    if ((mapaFinal[i][k+1] == -1) && (k < tamanho -1)) {
                        mapaFinal[i][k+1] = numeroAdicionado;
                        modificado = 1;
                    }
                    if (mapaFinal[i][k-1] == -1) {
                        mapaFinal[i][k-1] = numeroAdicionado;
                        modificado = 1;
                    }
                }
            }
        }
        numeroBase = numeroAdicionado;
        numeroAdicionado++;
        if (numeroAdicionado == 10) {
            numeroBase = 9;
            numeroAdicionado = 9;
        }
    // visualização do mapa
    printf("\n");
    for (i = 0; i < tamanho; i++) {
        for (k = 0; k < tamanho; k++) {
            printf("%d", mapaFinal[i][k]);
        }
        printf("\n");
    }
    printf("\n");

    } while (modificado);

    // visualização do mapa
    for (i = 0; i < tamanho; i++) {
        for (k = 0; k < tamanho; k++) {
            printf("%d", mapaFinal[i][k]);
        }
        printf("\n");
    }

    return 0;
}
