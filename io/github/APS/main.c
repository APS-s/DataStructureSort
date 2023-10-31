#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"
#include "quick.h"
#include "heap.h"

int main() {
    FILE *arquivo;
    extern int numPassosBubble;
    extern int numPassosQuick;
    extern int numPassosHeap;

    for(int i = 1; i <= 10; i++) { // Substitua por: for(int i = 1; i <= 8; i++) { quando for finalizar os testes
        int tamanho = 0;
        char nomeArquivo[50];
        sprintf(nomeArquivo, "./txtToSort/toSort%d.txt", i); // Substitua por: sprintf(nomeArquivo, "./txtToSort/toSort%d.txt", i); quando for finalizar os testes
        arquivo = fopen(nomeArquivo, "r");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        // Conta o número de elementos no arquivo
        int numero;
        while (fscanf(arquivo, "%d", &numero) != EOF) {
            tamanho++;
        }

        // Volta ao início do arquivo
        fseek(arquivo, 0, SEEK_SET);

        // Aloca espaço para armazenar os números para as ordenações
        int *dadosBubble = (int*)malloc(tamanho * sizeof(int));
        int *dadosQuick = (int*)malloc(tamanho * sizeof(int));
        int *dadosHeap = (int*)malloc(tamanho * sizeof(int));

        // Lê os números do arquivo e armazena nos arrays correspondentes
        for (int j = 0; j < tamanho; j++) {
            fscanf(arquivo, "%d", &numero);
            dadosBubble[j] = numero;
            dadosQuick[j] = numero;
            dadosHeap[j] = numero;
        }

        fclose(arquivo);


        // BubbleSort
        BubbleSort(dadosBubble, tamanho);
        sprintf(nomeArquivo, "txtSorted/bubbleSorted%d-%dpassos.txt", i, numPassosBubble);
        arquivo = fopen(nomeArquivo, "w");

        for (int j = 0; j < tamanho; j++) {
            fprintf(arquivo, "%d\n", dadosBubble[j]);
        }

        fclose(arquivo);

        printf("Os dados foram ordenados com o Bubble Sort e escritos no arquivo bubbleSorted%d.txt.\n", i);
        printf("O Bubble Sort realizou %d passos\n\n", numPassosBubble);


        // QuickSort
        numPassosQuick = 0;
        QuickSort(dadosQuick, tamanho);
        sprintf(nomeArquivo, "txtSorted/quickSorted%d-%dpassos.txt", i, numPassosQuick);
        arquivo = fopen(nomeArquivo, "w");

        for (int j = 0; j < tamanho; j++) {
            fprintf(arquivo, "%d\n", dadosQuick[j]);
        }

        fclose(arquivo);

        printf("Os dados foram ordenados com o Quick Sort e escritos no arquivo quickSorted%d.txt.\n", i);
        printf("O Quick Sort realizou %d passos.\n\n", numPassosQuick);


        // HeapSort
        numPassosHeap = 0;
        HeapSort(dadosHeap, tamanho);
        sprintf(nomeArquivo, "txtSorted/heapSorted%d-%dpassos.txt", i, numPassosHeap);
        arquivo = fopen(nomeArquivo, "w");

        for (int j = 0; j < tamanho; j++) {
            fprintf(arquivo, "%d\n", dadosHeap[j]);
        }

        fclose(arquivo);

        printf("Os dados foram ordenados com o Heap Sort e escritos no arquivo heapSorted%d.txt.\n", i);
        printf("O Heap Sort realizou %d passos\n\n", numPassosHeap);


        // Libera a memória alocada
        free(dadosBubble);
        free(dadosQuick);
        free(dadosHeap);
    }

    return 0;
}
