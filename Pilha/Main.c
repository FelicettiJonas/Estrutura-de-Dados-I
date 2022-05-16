#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ListaDupla.c"

char equacao[60];

void interface(int);
int verificaEquacao(Lista *);

int main()
{
    Lista *li;
    li = alocaMemoriaListaDinamica();

    interface(1);

    interface(verificaEquacao(li));

    return 0;
}

void interface(int num)
{
    switch (num)
    {
    case 0:
        printf("A equacao e valida! \n");
        break;
    case 1:
        printf("Informe a equacao: \n");
        scanf("%s", &equacao);
        break;
    case 2:
        printf("A equacao nao e valida! \n");
        break;

    default:
        break;
    }
}

int verificaEquacao(Lista *li)
{
    for (int i = 0; i < strlen(equacao); i++)
    {
        if (equacao[i] == '(' || equacao[i] == '[' || equacao[i] == '{')
        {
            insereElemento(li, equacao[i], li->tail);
        }

        if (equacao[i] == ')' || equacao[i] == ']' || equacao[i] == '}')
        {
            if (li->tail != NULL)
            {
                if (equacao[i] == ')' && li->tail->data == '(' && li->size > 0)
                {
                    removeElemento(li, li->tail);
                }
                else if (equacao[i] == ']' && li->tail->data == '[' && li->size > 0)
                {
                    removeElemento(li, li->tail);
                }
                else if (equacao[i] == '}' && li->tail->data == '{' && li->size > 0)
                {
                    removeElemento(li, li->tail);
                }
                else
                {
                    return 2;
                }
            }
            else
            {
                return 2;
            }
        }
    }

    if (li->size == 0)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}