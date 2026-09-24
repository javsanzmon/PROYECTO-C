#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *line = NULL;
    size_t len = 0;
    ssize_t leidos;

    for (int i = 0; i < 3; i++) {
        printf("Antes de getline, puntero vale: %p\n", (void *)line);
        leidos = getline(&line, &len, stdin);
        printf("Caracteres leidos: %zd\n", leidos);
        printf("Contenido: %s", line);
        printf("Direccion despues: %p, tamano buffer: %zu\n\n", (void *)line, len);
    }

    free(line);
    return 0;
}