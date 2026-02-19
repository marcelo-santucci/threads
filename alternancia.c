#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ITERACIONES 5

// Variable compartida que indica de quién es el turno
volatile int turno = 0;  // 0 para hilo 0, 1 para hilo 1

void *proceso0(void *arg) {
    for (int i = 0; i < ITERACIONES; i++) {

        // Sección de entrada
        while (turno != 0);  // Espera activa

        // Sección crítica
        printf("Hilo 0 en sección crítica (iteración %d)\n", i);
        sleep(1);

        // Sección de salida
        turno = 1;

        // Sección restante
        printf("Hilo 0 en sección no crítica\n");
    }
    pthread_exit(NULL);
}

void *proceso1(void *arg) {
    for (int i = 0; i < ITERACIONES; i++) {

        // Sección de entrada
        while (turno != 1);  // Espera activa

        // Sección crítica
        printf("Hilo 1 en sección crítica (iteración %d)\n", i);
        sleep(1);

        // Sección de salida
        turno = 0;

        // Sección restante
        printf("Hilo 1 en sección no crítica\n");
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo0, hilo1;

    pthread_create(&hilo0, NULL, proceso0, NULL);
    pthread_create(&hilo1, NULL, proceso1, NULL);

    pthread_join(hilo0, NULL);
    pthread_join(hilo1, NULL);

    return 0;
}

