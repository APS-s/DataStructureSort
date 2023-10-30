#include "quick.h"

int numPassosQuick;

void QuickSort(int* v, int tam) {
    if (tam <= 1)
        return;
    else {
        int x = v[0];
        int a = 1;
        int b = tam - 1;
        do {
            while ((a < tam) && (v[a] <= x))
                a++;
            while (v[b] > x)
                b--;
            if (a < b) {
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++;
                b--;
            }
            numPassosQuick++;
        } while (a <= b);
        v[0] = v[b];
        v[b] = x;
        QuickSort(v, b);
        QuickSort(&v[a], tam - a);
    }
}
