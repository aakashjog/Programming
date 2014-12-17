#include <stdio.h>

void factor_rec(int);

int main(void)
{
	int num = 0;

	printf("Please enter a number.\t");
	scanf("%d", &num);

	if(num == 1)
	{
		printf("1 is a unique number.\n");
	}
	else
	{
		printf("The prime factors of %d are\n", num);

		factor_rec(num); //Passes the number to the function for factorization.
	}

	printf("\n");

	return 0;
}

void factor_rec(int num)
{
	static int factor = 2; //Initializes the factor as a static integer, to 2, i.e. the smallest prime number.
	
	if(num == 1)
	{
		return;
	}

	if(num % factor == 0) //Prints the factor and divides the number by the factor till it is not divisible.
	{
		printf("%d\n", factor);

		while(num % factor == 0)
		{
			num = num/factor;
		}
	}
	factor++; //Increases the factor by 1.

	factor_rec(num); //Calls the function with the remaining dividend.
}
