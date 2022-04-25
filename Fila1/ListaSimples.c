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

int interface(int message, int placa, char *fila, int cont)
{
    switch (message)
    {
    case 101:
        printf("\n Lista vazia. Impossivel remover elemento.");
        break;
    case 102:
        printf("\n Ultimo elemento da lista passado como Pivo. Impossivel remover elemento.");
        break;
        case 103:
        printf("\n Elemento não encontrado");
        break;
    case 201:
        printf("\nCarro %i inserido com sucesso", placa);
        if (fila == "P")
        {
            printf(" no estacionamento!");
        }
        else if (fila == "W")
        {
            printf(" na fila de espera!");
        }
        else
        {
            printf("!");
        }
        
        break;
    case 202:
        printf("\nCarro %i removido com sucesso", placa);
        if (fila == "P")
        {
            printf(" do estacionamento! Sendo movido %i vezes.", cont);
        }
        else if (fila == "W")
        {
            printf(" da fila de espera! Sendo movido %i vezes.", cont);
        }
        else
        {
            printf("!");
        }

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
    el->data = 0;
    el->next = NULL;

    return el;
}

int insereElemento(Lista *li, int data, Elemento *pivo)
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
    return 201;
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

int removeElemento(Lista *li, Elemento *pivo)
{
    Elemento *el;

    if (li->size == 0)
    {
        return 101;
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
            return 102;
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

    return 202;
}

Elemento *buscarElemento(Lista *li, int data)
{
    Elemento *aux;
    aux = li->head;

    while (aux->next != NULL)
    {
        if (aux->next->data == data)
        {
            return aux;
        }

        aux = aux->next;
    }

    return NULL;
}


void limpaLista(Lista *li)
{
    while (li->head != NULL)
    {
        removeElemento(li, NULL);
    }

    free(li);
}