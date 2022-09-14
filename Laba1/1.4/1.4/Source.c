#include<stdio.h>

int main(void)
{
	char countries[4][20][24] =
	{
		{"Eurasia", "Ukraine", "Poland", "Belarus", "Germany", "France", "Spain", "Romania", "Turkey", "Russia", "Sweden", "Norway", "Finland", "Latvia", "Kazakhstan", "Iran", "India", "Saudi Arabia", "Pakistan", "null"},
		{"Africa", "Algeria", "Libya", "Morocco", "Mali", "Nigeria", "Chad", "Angola", "Namibia", "Zambia", "Gabon", "Cameroon", "null"},
		{"South America", "Venezuela", "Colombia", "Ecuador", "Bolivia", "Chile", "Argentina", "Uruguay", "Brazil", "null"},
		{"North America", "Greenland", "United States of America", "Canada", "Mexico", "null"}
	};
	
	//printf("If the program didn't give you \nanything, you entered something \nwrong or the country is not in the\nlist\n");
	printf("**********************************\n* If you want to exit write exit *\n**********************************\n");

	do
	{
		printf("Enter the name of the country: ");
		char country[24];
		fgets(country, 24, stdin);
		
		if (hashCode(country) == hashCode("exit")) return 0;

		for (int column = 0; column < sizeof(countries) / sizeof(countries[0]); column++)
		{
			for (int row = 0; row < sizeof(countries[0]) / sizeof(countries[0][0]); row++)
			{
				if (hashCode(countries[column][row]) != hashCode("null"))
				{
					if (hashCode(country) == hashCode(countries[column][row]))
					{
						printf("This country is located: %s\n", countries[column][0]);
						break;
					}
				}
				else break;
			}
		}
		printf("\n");
		fflush(stdin);
	} 
	while (1);
	
	return 0;
}

int hashCode(char str[24])
{
	int hash = 0;

	for (int i = 0; i < sizeof(str); i++)
	{
		if (str[i] == 10) break;
		hash += str[i];
	}
	return hash;
}