#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "LIB.h"

int* initArray(int size)
{
	int* array;
	array = malloc(size * sizeof(int));
	return array;
}

void deleteIndexInArray(int* array, int size, int index)
{
	for (int i = index; i < size-1; i++)
		array[i] = array[i + 1];
}

void deleteKElementInArray(int* array, int* size, int K)
{
	int newSize = *size;
	for (int i = K - 1; i < *size; i += K)
	{
		array[i] = NULL;
		newSize--;
	}
		
	for (int i = 0; i < *size; i++)
	{
		if (array[i] == NULL)
		{
			deleteIndexInArray(array, *size, i);
		}
	}
	*size = newSize;
}

void fillArray(int* array, int size)
{
	printf("1.Random array\n2.Fill array\nYour choice: ");
	int value = inputRestrictedInteger(1, 2);
	if (value == 1)
		randArray(array, size);
	else if (value == 2)
		inputArray(array, size);
}

int randArray(int* array, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		array[i] = rand() % 200 - 100;
}

int inputArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
		array[i] = inputInteger();
}

void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n\n");
}