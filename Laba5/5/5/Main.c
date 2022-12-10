#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MATRIX.h"
#include "ARRAY.h"
#include "LIB.h"

void main()
{
	srand(time(NULL));
	printf("==============\n|1. program 1|\n|2. program 2|\n|3. program 3|\n|4.   exit   |\n==============\nYour choice: ");
	switch (inputRestrictedInteger(1, 4))
	{
		case 1:
			prog1();
			break;
		case 2:
			prog2();
			break;
		case 3:
			prog3();
			break;
		case 4:
			break;
	}
	return 0;
}

int prog1()
{
	printf("Input array size: ");
	int size = inputMoreZeroInteger();
	int* array = initArray(size);
	fillArray(array, size);
	printf("Your array: \n");
	printArray(array, size);
	printf("Element K = ");
	deleteKElementInArray(array, &size, inputMoreZeroInteger());
	array = realloc(array, size * sizeof(int));
	printf("New array: \n");
	printArray(array, size);
	free(array);
	main();
}

int prog2()
{
	printf("Input row: ");
	int row = inputMoreZeroInteger();
	int** matrix = spesialMatrix(row);
	printf("Your matrix: \n");
	printSpesialMatrix(matrix, row);
	printf("Input K: ");
	int K = inputMoreZeroInteger();
	deleteSpesialRowK(matrix, &row, K);
	matrix = (int*)realloc(matrix, row * sizeof(int*));
	printf("New matrix: \n");
	printSpesialMatrix(matrix, row);
	freeMatrix(matrix, row);
	main();
}

int prog3()
{
	printf("Input row: ");
	int row = inputMoreZeroInteger();
	printf("Input col: ");
	int col = inputMoreZeroInteger();
	int** matrix = initMatrix(row, col);
	if (row == col)
	{
		randMatrix(matrix, row, col);
		printf("Your matrix: \n");
		printMatrix(matrix, row, col);
		deleteMainDiagonal(matrix, &row, &col);
		printf("New matrix without main diagonal: \n");
		printMatrix(matrix, row, col);
	}
	else
	{
		printf("This matrix has no diagonal.\n\n");
	}
	for(int y = 0; y<row; y++)
		matrix[y] = realloc(matrix[y], col * sizeof(int));
	freeMatrix(matrix, row);
	main();
}