#include "heap.h"

int numPassosHeap = 0; // Variável global para contar os passos no Heap Sort

void PercorreArvore(int* v, int raiz, int folha){
    int percorreu, maxfolhas, temp;
    percorreu = 0;
    while ((raiz * 2 <= folha) && (!percorreu)) {
        if (raiz * 2 == folha)
            maxfolhas = raiz * 2;
        else if (v[raiz * 2] > v[raiz * 2 + 1])
            maxfolhas = raiz * 2;
        else
            maxfolhas = raiz * 2 + 1;
        if (v[raiz] < v[maxfolhas]) {
            temp = v[raiz];
            v[raiz] = v[maxfolhas];
            v[maxfolhas] = temp;
            raiz = maxfolhas;
            numPassosHeap++; // Incrementa a contagem de passos aqui
        } else
            percorreu = 1;
    }
}

void HeapSort(int* v, int tam){
    int i, temp;
    for (i = (tam/2); i >= 0; i--)
        PercorreArvore(v, i, tam-1);
    for (i = tam-1; i >= 1; i--) {
        temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        PercorreArvore(v, 0, i-1);
    }
}
