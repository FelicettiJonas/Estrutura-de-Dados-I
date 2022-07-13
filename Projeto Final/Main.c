#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ListaDupla.c"
#include <sys/stat.h>

const char *filename = "nomes.txt";

#define TAM 53;

int menu(ListaHash *);
int calcularHash(char *);
void funcaoHash(ListaHash *, char *);
void ordenar(ListaHash *);
void swap(Elemento *, Elemento *);
Elemento *partition(Elemento *, Elemento *);
void quickSort(ElementoHash *, Elemento *, Elemento *);

int main()
{
    ListaHash *hash;
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
    } while (aux != 0);


    menu(hash);
    fclose(in_file);
    exit(EXIT_SUCCESS);
}


int menu(ListaHash *hash){
    Elemento *el;
    char *var = malloc(sizeof(char) * 25); 
    int chave;
    while (1>0)
    {
        printf("\n+++++++++++++++++++++++++++++++\n");
        printf("+1 - Percorrer lista hash     +\n");
        printf("+2 - ordenar listas           +\n");
        printf("+3 - Percorrer elementos      +\n");
        printf("+4 - Inserir nome             +\n");
        printf("+5 - Buscar nome              +\n");
        printf("+6 - limpar lista             +\n");
        printf("+++++++++++++++++++++++++++++++\n");
        int data;
        scanf("\n %i", &data);

        switch (data)
        {
        case 1:
            percorreListaHash(hash);
            break;
        case 2:
            ordenar(hash);
            break;
        case 3:
            printf("\ninforme o index a ser exibido:\n");
            scanf("\n %i", &data);
            percorreElementoHash(buscarElementoHash(hash, data));
            break;
        case 4:
            printf("\ninforme o nome a ser inserido:\n");
            scanf("\n %s", var);
            funcaoHash(hash, var);
            break;
        case 5:
            printf("informe o nome a ser buscado:\n");
            scanf("\n %s", var);

            chave = calcularHash(var);

            el = buscarElemento(buscarElementoHash(hash, chave), var);
            
            if (el != NULL)
            {
                printf("\n%s se encontra no index %i", var, chave);
            }else
            {
                printf("\n%s se encontra no index %i", var, chave);
                printf("\n %s nao encontrado", var);
            }
            
            
            break;
        case 6:
            limpaLista(hash);
            return 0;
            break;
        
        default:
            break;
        }
    }
    
}

int calcularHash(char *nome){
    int valor = 0;
    for (int i = 0; i < strlen(nome); i++)
    {

        valor += nome[i] * 91;

    }

    return valor % TAM;
}

void funcaoHash(ListaHash *hash, char *nome)
{
    
    int chave = calcularHash(nome);
    ElementoHash *elementoHash;
    elementoHash = buscarElementoHash(hash, chave);
    if (elementoHash == NULL)
    {
        insereElementoHash(hash, chave, hash->tail);
        elementoHash = hash->tail;
    }
  
    insereElemento(elementoHash, nome, elementoHash->tail);
}

void ordenar(ListaHash *hash)
{
    ElementoHash *ordenar;
    for(int i = 0; i<53; i++){
        ordenar = buscarElementoHash(hash, i);
        if (ordenar != NULL)
        {
            // printf("\n %i \n", i);
            quickSort(ordenar, ordenar->head, ordenar->tail);
            // percorreElementoHash(ordenar);
        }
        
    }
}



// function to swap elements
void swap(Elemento *a, Elemento *b)
{
  Elemento *t;
  t = alocaMemoriaElemento();
  t->data = a->data;
  a->data = b->data;
  b->data = t->data;

  free(t);
}

// function to find the partition position
Elemento *partition(Elemento *inicio, Elemento *final)
{

  // select the rightmost element as pivot
  Elemento *pivot = final;

  // pointer for greater element
  Elemento *i = inicio;
  Elemento *j = inicio;

  // traverse each element of the array
  // compare them with the pivot
  while (j != pivot)
  {
    if(strcmp(j->data, pivot->data) < 0){
      swap(i, j);
      i = i->next;
    }
    j = j->next;
  }

  // swap the pivot element with the greater element at i
  swap(i, pivot);


  // return the partition point
  return (i);
}

void quickSort(ElementoHash *li, Elemento *inicio, Elemento *fim)
{
  if (inicio != fim && inicio != NULL && fim != NULL && inicio != fim->next)
  {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    Elemento *pi = partition(inicio, fim);

    // recursive call on the left of pivot
    quickSort(li, inicio, pi->prev);

    // recursive call on the right of pivot
    quickSort(li, pi->next, fim);
  }
}