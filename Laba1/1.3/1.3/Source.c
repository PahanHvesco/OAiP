#include<stdio.h>

int main(void)
{
	do
	{
		int a, b, c;
		printf("Enter 3 numbers to check them for geometric progression: ");
		if (scanf_s("%d%d%d", &a, &b, &c) != 3)
		{
			printf("Something went wrong!!!\n");
			fgetc(stdin);
		}
		else
		{
			if (b / a == c / b) printf("This sequence is geometric");
			else printf("This sequence is not geometric");
			break;
		}
	} 
	while (1);
	return 0;
}