#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"
#include "quick.h"
#include "heap.h"

int main() {
    FILE *arquivo;
    int tamanho = 0;

    // Abre o arquivo para leitura
    arquivo = fopen("txtToSort/dtaleat1kdup1.txt", "r");

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

    // Aloca espaço para armazenar os números para o Bubble Sort
    int *dadosBubble = (int*)malloc(tamanho * sizeof(int));

    // Aloca espaço para armazenar os números para o Quick Sort
    int *dadosQuick = (int*)malloc(tamanho * sizeof(int));

    // Aloca espaço para armazenar os números para o Heap Sort
    int *dadosHeap = (int*)malloc(tamanho * sizeof(int));

    // Lê os números do arquivo e armazena nos arrays correspondentes
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &numero);
        dadosBubble[i] = numero;
        dadosQuick[i] = numero;
        dadosHeap[i] = numero;
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Chama a função BubbleSort para ordenar os números
    BubbleSort(dadosBubble, tamanho);

    // Abre o arquivo para escrita do Bubble Sort (sobrescrevendo o original)
    arquivo = fopen("txtSorted/bubbleSorted.txt", "w");

    // Escreve os números ordenados pelo Bubble Sort no arquivo
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", dadosBubble[i]);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Os dados foram ordenados com o Bubble Sort e escritos no arquivo bubbleSorted.txt.\n");

    // Chama a função QuickSort para ordenar os números
    QuickSort(dadosQuick, tamanho);

    // Abre o arquivo para escrita do Quick Sort (sobrescrevendo o original)
    arquivo = fopen("txtSorted/quickSorted.txt", "w");

    // Escreve os números ordenados pelo Quick Sort no arquivo
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", dadosQuick[i]);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Os dados foram ordenados com o Quick Sort e escritos no arquivo quickSorted.txt.\n");

    // Chama a função HeapSort para ordenar os números
    HeapSort(dadosHeap, tamanho);

    // Abre o arquivo para escrita do Heap Sort (sobrescrevendo o original)
    arquivo = fopen("txtSorted/heapSorted.txt", "w");

    // Escreve os números ordenados pelo Heap Sort no arquivo
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", dadosHeap[i]);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Os dados foram ordenados com o Heap Sort e escritos no arquivo heapSorted.txt.\n");

    // Libera a memória alocada
    free(dadosBubble);
    free(dadosQuick);
    free(dadosHeap);

    return 0;
}