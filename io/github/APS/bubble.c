#include "bubble.h"

int numPassosBubble = 0; // Variável global para contar os passos no Bubble Sort

void BubbleSort(int* v, int tam) {
    numPassosBubble++; // Incrementa a contagem de passos (int i)
    int i;
    numPassosBubble++; // Incrementa a contagem de passos (int trocou)
    int trocou;

    do {
        numPassosBubble++; // Incrementa a contagem de passos (tamanho --)
        tam--;
        numPassosBubble++; // Incrementa a contagem de passos (inicialização do trocou)
        trocou = 0;

        // Incrementa a contagem de passos (i = 0)
        numPassosBubble++;
        for (i = 0; i < tam; ++i) {
            numPassosBubble++; // Incrementa a contagem de passos (v[i] > v[i+1])
            if (v[i] > v[i+1]) {
                numPassosBubble++; // Incrementa a contagem de passos (auxiliar = v[i])
                int auxiliar = v[i];
                numPassosBubble++; // Incrementa a contagem de passos (v[i] = v[i+1])
                v[i] = v[i+1];
                numPassosBubble++; // Incrementa a contagem de passos (v[i+1] = auxiliar)
                v[i+1] = auxiliar;
                numPassosBubble++; // Incrementa a contagem de passos (trocou = 1)
                trocou = 1;
            }
            // Incrementa a contagem de passos (i++, i < tam)
            numPassosBubble+=2;
        }

        // Incrementa a contagem de passos (while trocou)
        numPassosBubble++;
    } while (trocou);
}
