#include "bubble.h"

int numPassosBubble = 0; // Variável global para contar os passos no Bubble Sort

void BubbleSort(int* v, int tam) {
    int i, j = tam, k;
    int trocou;

    do {
        tam--;
        trocou = 0;
        for (i = 0; i < tam; ++i) {
            if (v[i] > v[i+1]) {
                int auxiliar = v[i];
                v[i] = v[i+1];
                v[i+1] = auxiliar;
                trocou = 1;
                numPassosBubble++; // Incrementa a contagem de passos aqui
            }
        }
    } while (trocou);
}
