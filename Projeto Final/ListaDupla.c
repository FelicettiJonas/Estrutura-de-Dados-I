#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sElemento
{
    struct sElemento *next;
    struct sElemento *prev;
    char *data;
} Elemento;

typedef struct sLista
{
    Elemento *head, *tail;
    int size;
} Lista;

typedef struct sElementoHash
{
    struct sElementoHash *next;
    struct sElementoHash *prev;
    int chave;
    Elemento *head, *tail;
    int size;
} ElementoHash;

typedef struct sListaHash
{
    ElementoHash *head, *tail;
    int size;
} ListaHash;

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

ListaHash *alocaMemoriaListaHash()
{
    // Procedimento para alocar memoria
    ListaHash *li;
    li = (ListaHash *)malloc(sizeof(ListaHash));
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
    el->data = NULL;
    el->next = NULL;
    el->prev = NULL;

    return el;
}

ElementoHash *alocaMemoriaElementoHash()
{
    // Procedimento para alocar memoria
    ElementoHash *el;
    el = (ElementoHash *)malloc(sizeof(ElementoHash));
    el->chave = 0;
    el->next = NULL;
    el->prev = NULL;
    el->head = NULL;
    el->tail = NULL;
    el->size = 0;

    return el;
}

int insereElemento(ElementoHash *li, char *data, Elemento *pivo)
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

int insereElementoHash(ListaHash *li, int chave, ElementoHash *pivo)
{
    ElementoHash *el;
    el = alocaMemoriaElementoHash();
    el->chave = chave;

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

int removeElemento(ElementoHash *li, Elemento *el)
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

int removeElementoHash(ListaHash *li, ElementoHash *el)
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

void percorreListaHash(ListaHash *li)
{
    ElementoHash *aux;
    aux = li->head;

    printf("\n");
    while (aux != NULL)
    {
        printf("chave: %i  /  tamanho: %i \n", aux->chave, aux->size);
        aux = aux->next;
    }
}

void percorreElementoHash(ElementoHash *li)
{
    Elemento *aux;
    aux = li->head;

    printf("\n");
    while (aux != NULL)
    {
        printf("%s  \n", aux->data);
        aux = aux->next;
    }
}

Elemento *buscarElemento(ElementoHash *li, char *data)
{
    Elemento *aux;
    aux = li->head;

    while (aux != NULL)
    {
        if (strcmp(aux->data, data) == 0)
        {
            return aux;
        }
        aux = aux->next;
    }
}

ElementoHash *buscarElementoHash(ListaHash *li, int chave)
{
    ElementoHash *aux;
    aux = li->head;
    int cont = 0;

    while (aux != NULL)
    {
        if (aux->chave == chave)
        {
            return aux;
        }
        cont++;
        aux = aux->next;
    }
}

void limpaLista(ListaHash *li)
{
    ElementoHash *aux;
    while (li->head != NULL)
    {   
        aux = li->head;
        limpaElementoHash(li, li->head);
    }

    free(li);
}
void limpaElementoHash(ListaHash *li, ElementoHash *el){
    while (el->head != NULL)
    {
        removeElemento(el, el->head);
    }

    removeElementoHash(li, el);
}