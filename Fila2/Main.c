#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaDupla.c"

Elemento *searchSmaller(Lista*);
void pqMinDelete(Lista *);
void pqInsert(Lista *, int);
bool isEmpty(Lista *);

int main(int argc, char const *argv[])
{
    Lista *pq;
    pq = alocaMemoriaListaDinamica();

    pqInsert(pq, 20);
    pqInsert(pq, 40);
    pqInsert(pq, 30);
    pqInsert(pq, 10);
    pqInsert(pq, 50);
    pqInsert(pq, 80);
    pqInsert(pq, 70);
    pqInsert(pq, 60);

    percorreListaHeadTail(pq);

    pqMinDelete(pq);
    percorreListaHeadTail(pq);
    pqMinDelete(pq);
    percorreListaHeadTail(pq);
    pqMinDelete(pq);
    percorreListaHeadTail(pq);
    return 0;
}

bool isEmpty(Lista *li)
{
    if (li->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pqInsert(Lista *li, int data)
{
    insereElemento(li, data, li->tail);
}

void pqMinDelete(Lista *li)
{
    Elemento *smaller;
    smaller = searchSmaller(li);

    removeElemento(li, smaller); 
}

Elemento *searchSmaller(Lista* li)
{
    int min = 999999999;
    Elemento *smaller;
    Elemento *aux;
    aux = li->head;
    while (aux != NULL)
    {
       if (aux->data < min)
       {
           smaller = aux;
           min = smaller->data;
       }
       aux = aux->next;
    }
    return smaller;
}