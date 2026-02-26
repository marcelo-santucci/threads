#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <stdint.h>
#include <sys/mman.h>
#include <inttypes.h>

#define TAMANIOPAGINA 4096

int num = 25;

int main   (int argc, char ** argv)
{
    uint8_t *num_compartido = mmap(NULL, TAMANIOPAGINA,
                                    PROT_READ | PROT_WRITE,
                                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    *num_compartido = 22;
    
    if (fork() == 0) {
        *num_compartido = 44;
        num = 50;
    }
    else {
        wait(NULL);
    }
    printf("Num en memoria no compartida:   %i    PID: %d\n", num, getpid());
    
    printf("Num en memoria compartida:      %" PRIu8   "    PID: %d\n", *num_compartido,getpid());
}
