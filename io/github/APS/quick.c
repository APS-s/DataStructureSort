#include "quick.h"

int numPassosQuick = 0; // Variável global para contar os passos

void QuickSort(int* v, int tam){
    numPassosQuick++; // Incrementa a contagem de passos (tam <= 1)
    if (tam <= 1) {
        return;
    } else {
        numPassosQuick++; // Incrementa a contagem de passos (x = v[0])
        int x = v[0];
        numPassosQuick++; // Incrementa a contagem de passos (a = 1)
        int a = 1;
        numPassosQuick++; // Incrementa a contagem de passos (b = tam - 1)
        int b = tam - 1;
        do {
            while ((a < tam) && (v[a] <= x)) {
                numPassosQuick++; // Incrementa a contagem de passos (a++)
                a++;

                numPassosQuick+=2; // Incrementa a contagem de passos (a < tam && v[a] <= x)
            }
            while (v[b] > x) {
                numPassosQuick++; // Incrementa a contagem de passos (b--)
                b--;

                numPassosQuick++; // Incrementa a contagem de passos (v[b] > x)
            }

            numPassosQuick++; // Incrementa a contagem de passos (a <= b)
            if (a < b) {
                numPassosQuick++; // Incrementa a contagem de passos (auxiliar = v[a])
                int auxiliar = v[a];
                numPassosQuick++; // Incrementa a contagem de passos (v[a] = v[b])
                v[a] = v[b];
                numPassosQuick++; // Incrementa a contagem de passos (v[b] = auxiliar)
                v[b] = auxiliar;
                numPassosQuick++; // Incrementa a contagem de passos (a++)
                a++;
                numPassosQuick++; // Incrementa a contagem de passos (b--)
                b--;
            }

            numPassosQuick++; // Incrementa a contagem de passos (while a <= b)
        } while (a <= b);

        numPassosQuick++; // Incrementa a contagem de passos (v[0] = v[b])
        v[0] = v[b];
        numPassosQuick++; // Incrementa a contagem de passos (v[b] = x)
        v[b] = x;
        numPassosQuick++; // Incrementa a contagem de passos (QuickSort)
        QuickSort(v, b);
        numPassosQuick++; // Incrementa a contagem de passos (QuickSort)
        QuickSort(&v[a], tam - a);
    }
}
