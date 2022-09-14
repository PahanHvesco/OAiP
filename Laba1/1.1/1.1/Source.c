#include<stdio.h>
#include<math.h>

int main(void)
{
	float side1, side2, side3;
	do
	{
		int x1, y1, x2, y2, x3, y3;
		printf("Enter 3 X and 3 Y(x1 y1 x2 y2 x3 y3): ");
		if (scanf_s("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3) != 6)
		{
			printf("Something went wrong!!!\n");
			fgetc(stdin);
		}
		else
		{
			printf("Side 1: %f; Side 2: %f; Side 3: %f;\n", side1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)), side2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2)), side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)));
			if (side1 + side2 > side3 && side1 + side3 > side2 && side3 + side2 > side1) break;
			else printf("It's not a triangle!!!!\n");
		}
	}
	while (1);
	printf("Perimeter triangle: %f", side1 + side2 + side3);
	return 0;
}