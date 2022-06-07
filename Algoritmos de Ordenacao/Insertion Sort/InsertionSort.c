#include <stdio.h>
#include <stdlib.h>

void printArray(int[],int);

int main(int argc, char const *argv[]){
   int vet[] = {2,4,8,1,7,3,0};
   // int vet[] = {1,2,4,8,5,3,9};
    int tam = sizeof(vet)/sizeof(vet[0]);
    int aux;
 
    for (int j = 1; j < tam; j++){
        int aux= vet[j];
        int i = j-1;

        while (aux<vet[i]&&i>=0){
            vet[i+1] = vet[i];
            i--;
             printArray(vet,tam);
        }
        vet[i+1] = aux;
        
    }
    //printArray(vet,tam);
    return 0;
}

void printArray(int v[],int tam){
    for (int i = 0; i < tam; i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}