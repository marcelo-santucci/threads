# Threads

Repositorio con programas sencillos de uso de Threads.

Los programas se compilan con la siguiente instrucción:

```c

gcc -g ArchivoCodigo.c -o ArchivoCodigo

```

El programa alternancia.c requiere un parámetro extra para compilar

```c

gcc -g alternancia.c -o alternancia -pthread

```


Los programas memsicomp.c y memnocomp.c, son para ver el uso de memoria compartida entre procesos que se crean con fork.
