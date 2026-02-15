#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void* miTurno(void * arg) {
    while(1) {
        sleep(1);
        printf("¡Es mi Turno!\n");
    }
    return NULL;
}

void tuTurno() {
    while(1) {
        sleep(2);
        printf("\033[0;31m");   //Rojo
        printf("¡Es tu Turno!\n");
        printf("\033[0m");      //Normal
    }
}

int main() {
    pthread_t nuevothread;

    pthread_create(&nuevothread, NULL, miTurno, NULL);

    tuTurno();
}