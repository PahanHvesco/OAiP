#include <stdio.h>
#define N 10

void main(void)
{
	int array[N], minIndex;

	//fillArray(array, N);
	randArray(array, N);

	minIndex = indexArray(array, N, minInArray(array, N));
	for (int i1 = 0; i1 < minIndex; i1++)
	{
		for (int i2 = 0; i2<N; i2++)
		{
			if (i2 + 1 == N) array[i2] = 0;
			else array[i2] = array[i2 + 1];
		}
	}
	printf("Removing elements\n");
	printArray(array, N);
	return 0;
}