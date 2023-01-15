#include <stdio.h>
#include <stdlib.h>

int* createArray(int size)
{
	int* array;
	array = malloc(size * sizeof(int));
	return array;
}

void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n\n");
}

void randArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand()%100;
	}
}

int maxInArray(int* array, int size)
{
	int max = array[0];
	for (int i = 1; i < size; i++)
	{
		max = max < array[i] ? array[i] : max;
	}
	return max;
}

void replaycment(int* array, int x1, int x2)
{
	int bufValue = array[x1];
	array[x1] = array[x2];
	array[x2] = bufValue;
}

void deleteIndex(int* array, int size, int index)
{
	for (int i = index; i < size-1; i++)
	{
		replaycment(array, i, i + 1);
	}
	size -= 1;
	array = realloc(array, size * sizeof(int));
}

void deleteElements(int* array, int* size, int k)
{
	for (int i = k - 1; i < *size; i += k-1)
	{
		deleteIndex(array, *size, i);
		*size = *size - 1;
	}
}