#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <stdint.h>

#define TAMANIOPAGINA 4096

int num = 200;

int main   (int argc, char ** argv)
{
    if (fork() == 0) {
        num = 100;
    }
    else {
        wait(NULL);
    }
    printf("Memoria no compartida %i\n", num);
}
