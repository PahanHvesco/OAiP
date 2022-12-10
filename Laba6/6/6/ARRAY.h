#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* initArray(int size)
{
	int* array;
	array = malloc(size * sizeof(int));
	return array;
}

int* initZeroArray(int size)
{
	int* array;
	array = calloc(size, sizeof(int));
	return array;
}

void deleteIndexInArray(int* array, int size, int index)
{
	for (int i = index; i < size-1; i++)
		array[i] = array[i + 1];
}

void deleteNullElements(int* array, int size)
{
	int newSize = size;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == NULL)
		{
			deleteIndexInArray(array, newSize, i);
			newSize--;
		}
	}
}

void deleteKElementInArray(int* array, int* size, int K)
{
	int newSize = *size;
	for (int i = K-1; i < *size; i+=K)
		array[i] = NULL;
	for (int i = 0; i < *size; i++)
	{
		if (array[i] == NULL)
		{
			deleteIndexInArray(array, newSize, i);
			newSize--;
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

int maxInArray(int* array, int size)
{
	int max = array[0];
	for (int i = 1; i < size; i++)
	{
		max = max < array[i] ? array[i] : max;
	}
	return max;
}

void MargeSort(int* array, int size)
{
	int element = 2;
	int newSize = hgh(size);
	int* newArray = initArray(newSize);
	int* bufArray = initArray(newSize);

	for (int i = 0; i < newSize; i++)
	{
		if (i < size) newArray[i] = array[i];
		else newArray[i] = maxInArray(array, size);
	}
	
	while (element <= newSize)
	{
		for (int i = 0; i < newSize; i++)
			if (i % element == 0)
			{
				int x1 = i, x2 = x1 + element / 2;
				for (int x = i; x < i + element; x++)
				{
					if (newArray[x1] > newArray[x2] && x2<i+element && x2<newSize) bufArray[x] = newArray[x2++];
					else if(x1<i+element/2 && x1<newSize) bufArray[x] = newArray[x1++];
					else bufArray[x] = newArray[x];
				}
			}
		for (int i = 0; i < newSize; i++) newArray[i] = bufArray[i];
		element *= 2;
	}
	for (int i = 0; i < size; i++) array[i] = newArray[i];
	free(newArray);
	free(bufArray);
}

int* QuickSort(int* array, int start, int final)
{
	int rightElement = final - 1;
	for (int x1 = 0; x1 < final; x1++)
	{
		if (array[final-1] <= array[x1])
		{
			if (x1 == final - 1 && start < final - 1) QuickSort(array, start, final-1);
			else if (rightElement != NULL)
			{
				int bufValue = array[x1];
				for (int x2 = rightElement; x2 >= x1; x2--)
				{
					if (x1 == x2 && array[final-1]!=array[x2])
					{
						array[x1] = array[final - 1];
						array[final - 1] = bufValue;
						QuickSort(array, start, rightElement);
						QuickSort(array, rightElement+1, final);
						rightElement = NULL;
					}
					else if (array[final - 1] > array[x2])
					{
						array[x1] = array[x2];
						array[x2] = bufValue;
						rightElement = x2;
						break;
					}
				}
			}
			else break;
		}
	}
}