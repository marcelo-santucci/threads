/*
* En este programa se crea un thread para ejecutar el procedimiento miTurno
* y luego se llama al procedimiento tuTurno pero la diferencia es que en este
* código luego se hace que la ejecución de ese procedimiento se una al thread
* que se creó para el primero.
* 
* El resultado es ahora si se ejecutan ambos procedimientos. 
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
    pthread_join(nuevothread, NULL);

    printf("\033[0;35m");   //Cyan
    printf("¡Ahora si ambas funciones terminaron!\n");
    printf("Att. Bloque Principal \n");
    printf("\033[0m");      //Normal
}
