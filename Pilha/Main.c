#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaDupla.c"


int main(int argc, char const *argv[])
{
    Lista *li;
    li = alocaMemoriaListaDinamica;

    insereElemento(li, "(", li->tail);
    insereElemento(li, "[", li->tail);
    insereElemento(li, "{", li->tail);

    percorreListaHeadTail(li);
    return 0;
}
