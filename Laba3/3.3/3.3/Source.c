#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randArray(int* array, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		printf("%i: %i\n", i, array[i] = rand() % 100);
	}
	return;
}

int maxInArray(int array[], int n)
{
	int max = array[0];
	for (int i = 0; i < n; i++)
	{
		max = max < array[i] ? array[i] : max;
	}
	return max;
}

int minInArray(int array[], int n)
{
	int min = array[0];
	for (int i = 0; i < n; i++)
	{
		min = min > array[i] ? array[i] : min;
	}
	return min;
}

int sumArray(int array[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) sum += array[i];
	return sum;
}

int indexArray(int array[], int n, int number)
{
	int Iter = -1;
	for (int i = 0; i < n; i++)
	{
		if (array[i] == number)
		{
			Iter = i;
			break;
		}
	}
	return Iter;
}

void printArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%i: %i\n", i, array[i]);
	}
}

void fillArray(int* array, int n)
{
	int iter = 0;
	do
	{
		printf("Fill in an array of %d elements\n", n);
		for (int i = 0; i < n; i++)
		{
			printf("%i: ", i);
			if (!scanf_s("%i", &array[i]))
			{
				rewind(stdin);
				iter = 0;
				break;
			}
			else iter++;
		}
	} while (iter != n);
}