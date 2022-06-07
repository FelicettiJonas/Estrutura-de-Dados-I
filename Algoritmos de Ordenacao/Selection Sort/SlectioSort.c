#include <stdio.h>

void swap(int *, int *);
void selectionSort(int [], int);
void printArray(int [], int);

int main()
{
	// int array[] = {64, 34, 25, 12, 22, 11, 90, 52, 35, 69, 58, 17, 99};
    int array[] = {2,4,8, 8,1,7,3,0};
	int n = sizeof(array)/sizeof(array[0]);
	selectionSort(array, n);
	printf("Sorted array: \n");
	printArray(array, n);
	return 0;
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int array[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++){
		    if (array[j] < array[min_idx])
			min_idx = j;
        }
		swap(&array[min_idx], &array[i]);
	}
}

//Função para exibir o Array
void printArray(int array[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}