#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ListaDupla.c"
#include "QuickSort.c"
#include <sys/stat.h>

const char *filename = "nomes.txt";

void funcaoHash(ListaHash *, char *);

int main(int argc, char *argv[])
{
    Lista *li;
    ListaHash *hash;
    li = alocaMemoriaListaDinamica();
    hash = alocaMemoriaListaHash();

    FILE *in_file = fopen(filename, "r");

    struct stat sb;
    stat(filename, &sb);
    int aux;
    do
    {
        char *file_contents = malloc(sizeof(char) * 25);
        fscanf(in_file, "%[^\n] ", file_contents);
        funcaoHash(hash, file_contents);
        aux = file_contents[0];
        insereElemento(li, file_contents, li->tail);
    } while (aux != 0);

    percorreElementoHash(buscarElementoHash(hash, 44));
    percorreListaHash(hash);
    fclose(in_file);
    exit(EXIT_SUCCESS);
}

void funcaoHash(ListaHash *hash, char *nome)
{
    int chave = ((nome[0] - nome[1] + nome[2]) * 1151) % 53;
    ElementoHash *elementoHash;
    elementoHash = buscarElementoHash(hash, chave);
    if (elementoHash == NULL)
    {
        insereElementoHash(hash, chave, hash->tail);
        elementoHash = hash->tail;
    }

    insereElemento(elementoHash, nome, elementoHash->tail);
}