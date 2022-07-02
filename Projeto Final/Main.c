#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ListaDupla.c"
#include <sys/stat.h>

const char* filename = "nomesTeste.txt";

int main(int argc, char *argv[])
{
    Lista *li;
    li = alocaMemoriaListaDinamica();

    FILE *in_file = fopen(filename, "r");

    struct stat sb;
    stat(filename, &sb);

    char *file_contents = malloc(sb.st_size);

    while (fscanf(in_file, "%[^\n] ", file_contents) != EOF) {
        printf("> %s\n", file_contents);
        insereElemento(li, file_contents, li->tail);
    }

    printf("%i", li->size);
    fclose(in_file);
    exit(EXIT_SUCCESS);
}