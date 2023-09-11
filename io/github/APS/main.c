#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"
#include "quick.h"
#include "heap.h"

int main() {
    FILE *arquivo;
    int tamanho = 0;
    extern int numPassosBubble;
    extern int numPassosQuick;
    extern int numPassosHeap;

    const char* nomeArquivo = "./txtToSort/toSort7.txt";
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
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &numero);
        dadosBubble[i] = numero;
        dadosQuick[i] = numero;
        dadosHeap[i] = numero;
    }

    fclose(arquivo);

    // BubbleSort
    BubbleSort(dadosBubble, tamanho);
    arquivo = fopen("txtSorted/bubbleSorted.txt", "w");

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", dadosBubble[i]);
    }

    fclose(arquivo);

    printf("Os dados foram ordenados com o Bubble Sort e escritos no arquivo bubbleSorted.txt.\n");
    printf("O Bubble Sort realizou %d passos.\n\n", numPassosBubble);

    // QuickSort
    QuickSort(dadosQuick, tamanho);
    arquivo = fopen("txtSorted/quickSorted.txt", "w");

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", dadosQuick[i]);
    }

    fclose(arquivo);

    printf("Os dados foram ordenados com o Quick Sort e escritos no arquivo quickSorted.txt.\n");
    printf("O Quick Sort realizou %d passos.\n\n", numPassosQuick);

    // HeapSort
    HeapSort(dadosHeap, tamanho);
    arquivo = fopen("txtSorted/heapSorted.txt", "w");

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", dadosHeap[i]);
    }

    fclose(arquivo);

    printf("Os dados foram ordenados com o Heap Sort e escritos no arquivo heapSorted.txt.\n");
    printf("O Heap Sort realizou %d passos.\n\n", numPassosHeap);

    // Libera a memória alocada
    free(dadosBubble);
    free(dadosQuick);
    free(dadosHeap);

    // Abre os arquivos ordenados
    #ifdef _WIN32
        char comando[100];
        snprintf(comando, sizeof(comando), "notepad %s", nomeArquivo);
        system(comando);
        system("open_files.bat");
    #endif

    return 0;
}
