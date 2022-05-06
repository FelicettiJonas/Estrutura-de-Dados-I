#include <stdio.h>
#include <stdlib.h>


typedef struct sElemento
{
    struct sElemento *next;
    struct sElemento *prev;
    char data;
} Elemento;

typedef struct sLista
{
    Elemento *head, *tail;
    int size;
} Lista;

int validador(int erro)
{
    switch (erro)
    {
    case 1:
        printf("\nSo e aceito pivo NULL na insercao do primeiro elemento.");
        break;
    case 2:
        printf("\nElemento ou lista invalidos.");
        break;
    default:
        break;
    }

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
    el->data = '\0';
    el->next = NULL;
    el->prev = NULL;

    return el;
}

int insereElemento(Lista *li, char data, Elemento *pivo)
{
    Elemento *el;
    el = alocaMemoriaElemento();
    el->data = data;

    if ((pivo == NULL) && (li->size > 0))
    {
        return 1;
    }

    if (li->size == 0)
    {
        li->head = el;
        li->tail = el;
    }

    else
    {
        el->next = pivo->next;
        el->prev = pivo;

        if (pivo->next == NULL)
        {
            li->tail = el;
        }
        else
        {
            pivo->next->prev = el;
        }

        pivo->next = el;
    }

    li->size++;
    return 0;
}

int removeElemento(Lista *li, Elemento *el)
{
    if ((el != NULL) && (li->size > 0))
    {
        if (el == li->head) // Se for o primeiro elemento da lista
        {
            li->head = el->next;
            if (li->head == NULL) // verifica se a lista ficou vazia
            {
                li->tail = NULL;
            }
            else
            {
                el->next->prev = NULL;
            }
        }
        else
        {
            el->prev->next = el->next;
            if (el->next == NULL) // Verifica se é o ultimo elemento da lista
            {
                li->tail = el->prev;
            }
            else
            {
                el->next->prev = el->prev;
            }
        }

        free(el);
        li->size--;
        return 0;
    }
    else
    {
        return 2;
    }
}

void percorreListaHeadTail(Lista *li)
{
    Elemento *aux;
    aux = li->head;

    printf("\n");
    while (aux != NULL)
    {
        printf("%c  ", aux->data);
        aux = aux->next;
    }
}

void percorreListaTailHead(Lista *li)
{
    Elemento *aux;
    aux = li->tail;

    printf("\n");
    while (aux != NULL)
    {
        printf("%c  ", aux->data);
        aux = aux->prev;
    }
}

Elemento *buscarElementoHeadTail(Lista *li, char data)
{
    Elemento *aux;
    aux = li->head;
    int cont = 0;

    while (aux != NULL)
    {
        if (aux->data == data)
        {
            return aux;
        }
        cont++;
        aux = aux->next;
    }
}

Elemento *buscarElementoTailHead(Lista *li, char data)
{
    Elemento *aux;
    aux = li->tail;
    int cont = 0;

    while (aux != NULL)
    {
        if (aux->data == data)
        {
            return aux;
        }
        cont++;
        aux = aux->prev;
    }
}

void limpaLista(Lista *li)
{
    while (li->head != NULL)
    {
        removeElemento(li, li->head);
    }

    free(li);
}