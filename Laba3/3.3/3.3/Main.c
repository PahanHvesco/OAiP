#include <stdio.h>
#define N 10

void main()
{
	int array[N], Iter = 0, value;

	fillArray(array, N);
	//randArray(array, N);

	for (int i1 = 0; i1 < N; i1++)
	{
		int Iter1 = 0;
		if (array[i1] % 2 != 0)
		{
			for (int i2 = 0; i2 < N; i2++)
			{
				if (array[i1] == array[i2])
				{
					Iter1++;
					if (Iter < Iter1)
					{
						Iter = Iter1;
						value = array[i1];
					}
				}
			}
		}
	}
	
	printf("Most common odd number: %d", value);
	return 0;
}