#include "bubble.h"

int numPassosBubble;

void BubbleSort(int* v, int tam) {
    int i, j = tam, k;
    int trocou;
    numPassosBubble = 0;
    do {
        tam--;
        trocou = 0;
        for (i = 0; i < tam; i++) {
            if (v[i] > v[i + 1]) {
                int aux = 0;
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                trocou = 1;
                numPassosBubble++;
            }
        }
    } while (trocou);
}
