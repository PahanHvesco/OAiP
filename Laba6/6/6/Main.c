#include <stdio.h>
#include <stdlib.h>
#include "ARRAY.h"
#include "MATRIX.h"
#include "LIB.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	printf("==============\n|1. program 1|\n|2. program 2|\n|3.   exit   |\n==============\nYour choice: ");
	switch (inputRestrictedInteger(1, 4))
	{
	case 1:
		prog1();
		break;
	case 2:
		prog2();
		break;
	case 3:
		break;
	}
	return 0;
}

int prog1()
{
	printf("Input size array: ");
	int* array, size = inputMoreZeroInteger(), *newArray, newSize = size/2;
	array = initArray(size);
	newArray = initZeroArray(size);
	fillArray(array, size);
	for (int i = 0; i < size; i++)
		newArray[i] = i % 2 == 0 ? maxInArray(array, size) : array[i];
	printArray(array, size);
	clock_t start = clock();
	MargeSort(newArray, size);
	clock_t end = clock();
	float second = (float)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < size; i++)
		if (i % 2 != 0) array[i] = newArray[i/2];
	printArray(array, size);
	printf("Time: %f\n", second);
	free(array);
	free(newArray);
	main();
}

int prog2()
{
	int** matrix, width, height;
	printf("Input width:  ");
	width = inputMoreZeroInteger();
	printf("Input height: ");
	height = inputMoreZeroInteger();
	matrix = initMatrix(width, height);
	fillMatrix(matrix, width, height);
	printf("Your matrix: \n");
	printMatrix(matrix, width, height);
	//clock_t start = clock();
	//sortMatrix(matrix, width, height);
	//clock_t end = clock();
	//double second = (double)(end - start) / CLOCKS_PER_SEC;
	printf("New matrix: \n");
	QuickSortForMatrix(matrix, width, 0, height - 1);
	printMatrix(matrix, width, height);
	//printf("Time: %lf\n", second);
	for (int i = 0; i < width; i++)
		free(matrix[i]);
	free(matrix);
	main();
}

int sortMatrix(int** matrix, int width, int height)
{
	int size = height/2;
	int* array = initArray(size);
	for (int x = 1; x < height; x+=2)
	{
		int sum = 0;
		for (int y = 0; y < width; y++)
		{
			sum += matrix[y][x];
		}
		array[x / 2] = sum;
	}
	QuickSort(array, 0, size);
	for (int x = 1; x < height; x += 2)
	{
		int sum = 0;
		for (int y = 0; y < width; y++)
		{
			sum += matrix[y][x];
		}
		int iter = 0;
		for (int i = 0; i < size; i++)
		{
			iter++;
			if (array[i] == sum && i + iter < height)
			{
				for (int y = 0; y < width; y++)
				{
					int bufValue = matrix[y][x];
					matrix[y][x] = matrix[y][i + iter];
					matrix[y][i + iter] = bufValue;
				}
				
			}
		}
		
	}
}