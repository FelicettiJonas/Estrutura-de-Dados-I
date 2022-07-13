// Quick sort in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include "ListaDupla.c"

// function to swap elements
void swap(Elemento *a, Elemento *b)
{
  Elemento *t;
  t = alocaMemoriaElemento();
  t->data = a->data;
  a->data = b->data;
  b->data = t->data;
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