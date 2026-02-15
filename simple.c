#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void miTurno() {
    while(1) {
        sleep(1);
        printf("¡Es mi Turno!\n");
    }
}

void tuTurno() {
    while(1) {
        sleep(2);
        printf("¡Es tu Turno!\n");
    }
}

int main() {
    miTurno();
    tuTurno();
}