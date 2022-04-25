#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaSimples.c"

#define MAX 3


bool isEmpty(Lista *);
void comando(char *, int);
int retirarCarro(Lista *, int, Lista *);
void inserirCarro(Lista *, int, Lista *);

int Cont;
Lista *Estacionamento;
Lista *Espera;

int main()
{
    // Lista *estacionamento;
    Estacionamento = alocaMemoriaListaDinamica();
    // Lista *espera;
    Espera = alocaMemoriaListaDinamica();
    comando("C", 10);
    comando("C", 20);
    comando("C", 30);
    comando("C", 40);
    comando("C", 50);
    comando("C", 60);
    comando("C", 70);
    comando("C", 80);
    comando("C", 90);


    percorreLista(Estacionamento);
    percorreLista(Espera);

    comando("P", 30);
    comando("P", 70);

    percorreLista(Estacionamento);
    percorreLista(Espera);

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

void comando(char *letra, int placa)
{
    if (letra == "C")
    {
        inserirCarro(Estacionamento, placa, Espera);
    }
    else if (letra == "P")
    {
        retirarCarro(Estacionamento, placa, Espera);
    }
    
}

void inserirCarro(Lista *li, int placa, Lista *espera)
{
    if (li->size < MAX)
    {
        interface(insereElemento(li, placa, li->tail), placa, "P", 0);
    }
    else
    {
        interface(insereElemento(espera, placa, espera->tail), placa, "W", 0);
    }
}

int retirarCarro(Lista *li, int placa, Lista *espera)
{
    Cont = 0;

    Elemento *aux;

    aux = buscarElemento(espera, placa);

    if (aux != NULL)
    {
        interface(removeElemento(espera, aux), placa, "W", Cont);

        return 0;
    }
    

    if (li->head->data == placa)
    {
        interface(removeElemento(li, NULL), placa, "P", Cont);
    }
    else
    {
        int aux;
        aux = li->head->data;
        do
        {
            if (li->head->data != placa)
            {
                insereElemento(li, li->head->data, li->tail);
                Cont ++;
            }
            if (li->head->data == placa)
            {
                interface(removeElemento(li, NULL), placa, "P", Cont);
            }
            else
            {
                removeElemento(li, NULL);
            }
        } while (li->head->data != aux);
    }

    if (!isEmpty(espera) && li->size < MAX)
    {
        interface(insereElemento(li, espera->head->data, li->tail), espera->head->data, "P", 0);
        removeElemento(espera, NULL);
    }

    return 0;
}