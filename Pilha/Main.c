#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ListaDupla.c"

int main()
{
    Lista *li;
    li = alocaMemoriaListaDinamica();

    char equacao[60];

    printf("Informe a equacao: \n");
    scanf("%s", &equacao);

    for (int i = 0; i < strlen(equacao); i++)
    {
        if (equacao[i] == '(' || equacao[i] == '[' || equacao[i] == '{')
        {
            insereElemento(li, equacao[i], li->tail);
        }

        if (equacao[i] == ')' || equacao[i] == ']' || equacao[i] == '}')
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
                insereElemento(li, '(', li->tail);
                break;
            }
        }
    }

    if (li->size == 0)
    {
        printf("A equacao e valida! \n");
    }
    else
    {
        printf("A equacao nao e valida! \n");
    }
    
    

    printf("%s", equacao);

    percorreListaHeadTail(li);
    return 0;
}
