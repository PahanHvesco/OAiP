#include<stdio.h>

int main(void)
{
	for (int i = 10; i < 100; i++)
	{
		if (((i/10) * (i/10)) + ((i%10)*(i%10)) == 3*(i/10)*(i%10)+1)
		{
			if (i / (i / 10 + i % 10) == 7 && i % (i / 10 + i % 10) == 6)
			{
				printf("%d", i);
				break;
			}
		}
	}
	return 0;
}