#include <stdio.h>

void swap(int*, int*);
void bubbleSort(int [], int);
void printArray(int [], int);

int main()
{
	int array[] = {64, 34, 25, 12, 22, 11, 90, 52, 35, 69, 58, 17, 99};
    // int array[] = {2,4,8,1,7,3,0};
	int n = sizeof(array) / sizeof(array[0]);
	bubbleSort(array, n);
	printf("Array ordenado: \n");
	printArray(array, n);
	return 0;
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int array[], int n)
{
	int i, j, verificador;
	for (i = 0; i < n - 1; i++){
            verificador = 0;
		for (j = 0; j < n - i - 1; j++){
            printArray(array, n);
			if (array[j] > array[j + 1]){
				swap(&array[j], &array[j + 1]);
                verificador = 1;
                printArray(array, n);
            }
        }
        if (!verificador){
        break;
        }
    }
}

//Função para exibir o Array
void printArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}