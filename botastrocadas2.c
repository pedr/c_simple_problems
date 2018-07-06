#include <stdio.h>
#include <stdlib.h>

int main()
{
    // quantidade de sapatos, sempre par; tamanho/numero do sapato
    int quantidade, tamanho;
    // quantos membros cada array possui no momento
    int qntLadoE, qntLadoD;
    // lado do sapato, D ou E
    char lado;
    int tmp;
    int resposta = 0;

    // quantos sapatos são, sempre par
    scanf("%d", &quantidade);

    // arrays para guardar os sapato D e E separados
    int ladoE[quantidade];
    int ladoD[quantidade];

    // qnt de sapatos em cada array
    qntLadoE = qntLadoD = 0;

    for (int i = 0; i < quantidade; i++) {
        // le as entradas;
        scanf("%d %c", &tamanho, &lado);

        if (lado == 'E') {
            ladoE[qntLadoE] = tamanho;
            qntLadoE++;
        }
        if (lado == 'D') {
            ladoD[qntLadoD] = tamanho;
            qntLadoD++;
        }
    }

    // os dois próximos fors ordenam os arrays

    for (int i = 0; i < qntLadoE; i++) {
        for (int k = 0; k < qntLadoE - 1; k++) {
            if (ladoE[k] > ladoE[k+1]) {
                tmp = ladoE[k];
                ladoE[k] = ladoE[k+1];
                ladoE[k+1] = tmp;
            }
        }
    }

    for (int i = 0; i < qntLadoD; i++) {
        for (int k = 0; k < qntLadoD - 1; k++) {
            if (ladoD[k] > ladoD[k+1]) {
                tmp = ladoD[k];
                ladoD[k] = ladoD[k+1];
                ladoD[k+1] = tmp;
            }
        }
    }

    /*
    // descobre qual dos dois vetores é menor e usa ele de base

    // como os dois vetores estão ordenados se o valor de ladoE[k]
    // for diferente do

    valor de ladoE[i]
    // valor de ladoE[i] só continua a aumentar k se
    // o valor de ladoE[i] for > que o valor de ladoD[k]
    */

    int k = 0;
    if (qntLadoD > qntLadoE) {
	for (int i = 0; i < qntLadoE; i++) {
	    if (ladoE[i] != ladoD[k]) {
		while (ladoE[i] > ladoD[k]) {
		    k++;
		    if (k > qntLadoD) {
			break;
		    }
		}
		if (ladoE[i] == ladoD[k]) {
		    resposta++;
		}
	    } else {
		resposta++;
	    }
	}

    } else {
	for (int i = 0; i < qntLadoD; i++) {
	    if (ladoD[i] != ladoE[k]) {
		while (ladoD[i] > ladoE[k]) {
		    k++;
		    if (k > qntLadoE) {
			break;
		    }
		}
		if (ladoD[i] == ladoE[k]) {
		    resposta++;
		}
	    } else {
		resposta++;
	    }
	}
    }

    printf("%d\n", resposta);


    return 0;
}
