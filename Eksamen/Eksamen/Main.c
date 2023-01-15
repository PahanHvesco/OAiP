#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
#include "Sort.h"
#include "Matrix.h"
#include "String.h"

void funk1();
void funk2();
void funk3();
void funk4();

void main()
{
	srand(time(NULL));
	funk2();
}

void funk1()
{
	char* str = malloc(128 * sizeof(char));
	inputString(str);
	printf("\nSum: %d\n", sumIntInString(str));
}

void funk2()
{
	int size = 18;
	int* array = createArray(size);
	randArray(array, size);
	printArray(array, size);
	insertionSort(array, size);
	printArray(array, size);
}

void funk3()
{
	int* size = 10;
	int* array = createArray(size);
	randArray(array, size);
	printArray(array, size);
	deleteElements(array, &size, 1);
	printArray(array, size);
}

void funk4()
{
	int* row = 6;
	int* col = 4;
	int** matrix = createMatrix(row, col);
	randMatrix(matrix, row, col);
	printMatrix(matrix, row, col);
	deleteIndexCol(matrix, &row, col, 2);
	printMatrix(matrix, row, col);
}