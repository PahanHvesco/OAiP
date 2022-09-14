#include <stdio.h>

int main(void)
{
	do
	{
		int side1, side2, side3;
		printf("Enter 3 side: ");
		if (scanf_s("%d%d%d", &side1, &side2, &side3)!=3 || side1<0 || side2<0 || side3<0)
		{
			printf("Something went wrong!!!\n");
			fgetc(stdin);
		}
		else if (side1 + side2 > side3 && side1 + side3 > side2 && side3 + side2 > side1)
		{
			
			if (side1 == side2 && side2 == side3)printf("This equilateral triangle");
			else printf("It's not an equilateral triangle");
			break;
		}
		else printf("It's not triangle!!!\n");
	}
	while (1);
	return 0;
}