#include<sys/time.h>
#include <stdio.h>
#include <malloc.h>

long long getMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

/**
 * Returns the current time in microseconds.
 */
long getMicrotime(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

char *formatMilisseconds(long milissegundos) {
    char *formatado = (char *)malloc(20); // Tamanho suficiente para a formatação
    snprintf(formatado, 20, "%ld.%03ld.%03ld.%03ld",
             milissegundos / 1000000,
             (milissegundos / 1000) % 1000,
             milissegundos % 1000,
             milissegundos % 1000);
    return formatado;
}
