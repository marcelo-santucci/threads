/*
* En este programa se crea un thread para ejecutar el procedimiento miTurno
* pero no se crea ninguno para ejeuctar el procedimiento tuTurno
* 
* El resultado es que únicamente se ejecuta el procedimiento miTurno 
*/
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void* miTurno(void * arg) {
    for(int i=0; i < 8; i++) {
        sleep(1);
        printf("¡Es mi Turno! %d\n",i);
    }
    return NULL;
}

void tuTurno() {
    for(int i=0; i < 3; i++) {
        sleep(2);
        printf("\033[0;31m");   //Rojo
        printf("¡Es tu Turno! %d\n",i);
        printf("\033[0m");      //Normal
    }
}

int main() {
    pthread_t nuevothread;

    pthread_create(&nuevothread, NULL, miTurno, NULL);

    tuTurno();

    printf("\033[0;36m");   //Cyan
    printf("¡Ya me canse Jefe! tuTurno ya terminó\n");
    printf("Att. Bloque Principal \n");
    printf("\033[0m");      //Normal
}
