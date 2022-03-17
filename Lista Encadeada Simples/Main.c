#include <stdio.h>
#include <stdlib.h>

typedef struct sElemento
{
    struct sElemento *next;
    int data;
} Elemento;

typedef struct sLista
{
    Elemento *head, *tail;
    int size;
} Lista;

Lista *alocaMemoriaListaDinamica();
Elemento *alocaMemoriaElemento();
void insereElemento(Lista *, int, Elemento *);
void percorreLista(Lista *);
void removeElemento(Lista *, Elemento *);
Elemento *buscarElemento(Lista *, int);
void excluiLista(Lista *);

int main()
{
    Lista *li;
    Elemento *el;

    li = alocaMemoriaListaDinamica();

    insereElemento(li, 10, li->head);
    insereElemento(li, 5, li->tail);
    insereElemento(li, 15, NULL);

    percorreLista(li);

    removeElemento(li, li->tail);
    removeElemento(li, li->head);

    percorreLista(li);

    buscarElemento(li, 15);

    excluiLista(li);


    return 0;
}

Lista *alocaMemoriaListaDinamica()
{
    // Procedimento para alocar memoria
    Lista *li;
    li = (Lista *)malloc(sizeof(Lista));
    li->head = NULL;
    li->tail = NULL;
    li->size = 0;

    return li;
}

Elemento *alocaMemoriaElemento()
{
    // Procedimento para alocar memoria
    Elemento *el;
    el = (Elemento *)malloc(sizeof(Elemento));
    el->data = 0;
    el->next = NULL;

    return el;
}

void insereElemento(Lista *li, int data, Elemento *pivo)
{
    Elemento *el;
    el = alocaMemoriaElemento();
    el->data = data;
    if (pivo == NULL)
    {
        if (li->size == 0)
        {
            li->tail = el;
        }
        el->next = li->head;
        li->head = el;
    }
    else
    {
        if (pivo->next == NULL)
        {
            li->tail = el;
        }
        el->next = pivo->next;
        pivo->next = el;
    }
    li->size++;
}

void percorreLista(Lista *li)
{
    Elemento *aux;
    aux = li->head;

    printf("\n");
    while (aux != NULL)
    {
        printf("%i  ", aux->data);
        aux = aux->next;
    }
}

void removeElemento(Lista *li, Elemento *pivo)
{
    Elemento *el;
    // el = pivo->next;

    if (li->size == 0)
    {
        printf("\n Lista vazia. Impossivel remover elemento.");
        return;
    }
    if (pivo == NULL)
    {
        el = li->head;
        li->head = li->head->next;

        if (li->head == NULL)
        {
            li->tail = NULL;
        }
    }
    else
    {
        if (pivo->next == NULL)
        {
            printf("\n Ultimo elemento da lista passado como Pivo. Impossivel remover elemento.");
            return;
        }

        el = pivo->next;
        pivo->next = pivo->next->next;

        if (pivo->next == NULL)
        {
            li->tail = pivo;
        }
    }

    free(el);

    li->size--;
}

Elemento *buscarElemento(Lista *li, int data)
{
    Elemento *aux;
    aux = li->head;
    int cont = 0;

    while (aux != NULL)
    {
        if (aux->data == data)
        {
            printf("\n O dado %i esta na lista na posicao %i", data, cont);
            return aux;
        }

        cont++;
        aux = aux->next;
    }
}

void excluiLista(Lista *li)
{
    Elemento *aux;
    Elemento *excluir;
    aux = li->head;

    while (aux != NULL)
    {
        excluir = aux;
        aux = aux->next;
        free(excluir);
    }

    free(li);
}