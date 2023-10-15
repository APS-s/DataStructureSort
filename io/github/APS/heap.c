#include "heap.h"

int numPassosHeap = 0; // Variável global para contar os passos no Heap Sort

void PercorreArvore(int* v, int raiz, int folha){
    numPassosHeap+=3; // Incrementa a contagem de passos (inicialização das variáveis)
    int percorreu, maxfolhas, temp;

    numPassosHeap++; // Incrementa a contagem de passos (percorreu = 0)
    percorreu = 0;

    while ((raiz * 2 <= folha) && (!percorreu)) {
        numPassosHeap+=2; // Incrementa a contagem de passos (condição do if)
        if (raiz * 2 == folha || v[raiz * 2] > v[raiz * 2 + 1]) {
            numPassosHeap++; // Incrementa a contagem de passos (maxfolhas = raiz * 2)
            maxfolhas = raiz * 2;
        } else {
            numPassosHeap++; // Incrementa a contagem de passos (maxfolhas = raiz * 2 + 1)
            maxfolhas = raiz * 2 + 1;
        }

        numPassosHeap++; // Incrementa a contagem de passos (condição do if)
        if (v[raiz] < v[maxfolhas]) {
            numPassosHeap++; // Incrementa a contagem de passos (temp = v[raiz])
            temp = v[raiz];
            numPassosHeap++; // Incrementa a contagem de passos (v[raiz] = v[maxfolhas])
            v[raiz] = v[maxfolhas];
            numPassosHeap++; // Incrementa a contagem de passos (v[maxfolhas] = temp)
            v[maxfolhas] = temp;
            numPassosHeap++; // Incrementa a contagem de passos (raiz = maxfolhas)
            raiz = maxfolhas;
        } else {
            numPassosHeap++; // Incrementa a contagem de passos (percorreu = 1)
            percorreu = 1;
        }

        // Incrementa a contagem de passos (raiz * 2 <= folha && !percorreu)
        numPassosHeap+=2;
    }
}

void HeapSort(int* v, int tam){
    int i, temp;

    numPassosHeap++; // Incrementa a contagem de passos (i = tam/2)
    for (i = (tam/2); i >= 0; i--) {
        numPassosHeap++; // Incrementa a contagem de passos (PercorreArvore)
        PercorreArvore(v, i, tam - 1);

        // Incrementa a contagem de passos (i >=0, i--)
        numPassosHeap+=2;
    }

    numPassosHeap++; // Incrementa a contagem de passos (i = tam-1)
    for (i = tam-1; i >= 1; i--) {
        numPassosHeap++; // Incrementa a contagem de passos (temp = v[0])
        temp = v[0];
        numPassosHeap++; // Incrementa a contagem de passos (v[0] = v[i])
        v[0] = v[i];
        numPassosHeap++; // Incrementa a contagem de passos (v[i] = temp)
        v[i] = temp;
        numPassosHeap++; // Incrementa a contagem de passos (PercorreArvore)
        PercorreArvore(v, 0, i-1);

        // Incrementa a contagem de passos (i >= 1, i--)
        numPassosHeap+=2;
    }
}
