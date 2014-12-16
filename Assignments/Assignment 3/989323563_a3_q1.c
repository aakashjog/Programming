#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isValidNum(int); //Checks the validity of the guess.
int getNumBulls(int, int); //Counts the number of bulls in the guess.
int getNumCows(int, int); //Counts the number of cows in the guess.
void printBullsAndCows(int, int); //Prints the number of bulls and cows in the guess.

int main(void)
{
	int target=0, guess=0, bulls=0, cows=0;
	
	//Generates a random number between 1000 and 9999, without repeated digits.
	do
	{
		srand(time(NULL));
		target=rand()%(9999-1000);
	}	
	while(isValidNum(target)==0);

	//Accepts guess till the correct number is entered.
	while(bulls != 4)
	{
		//Accepts guess from user.
		printf("Enter your guess.\n");
		scanf("%d", &guess);
		
		//Scans the guess until a valid value is entered.
		while(isValidNum(guess) == 0)
		{
			printf("\nInvalid guess! Please enter a number between 1000 and 9999, with four different digits.\n\n");
			scanf("%d", &guess);
		}

		bulls = getNumBulls(target, guess);
		cows = getNumCows(target, guess);

		printBullsAndCows(bulls, cows);
	}

	//Prints output if guess is correct.
	if(bulls == 4)
	{
		printf("Congratulations! Your guess is correct.\n\n");
	}

	return 0;
}

//Checks the validity of a number. If the number is valid, the function returns 1.
int isValidNum(int num)
{
	int digit_1=0, digit_2=0, digit_3=0, digit_4=0;
	int i=0;

	//Checks the range of the number.
	if((num < 1000) || (num > 9999))
		return 0;

	//Splits the number into digits.
	digit_4=num%10;
	num=num/10;

	digit_3=num%10;
	num=num/10;

	digit_2=num%10;
	num=num/10;

	digit_1=num%10;
	num=num/10;

	//Checks for repetitive digits.
	if((digit_1 == digit_2) || (digit_1 == digit_3) || (digit_1 == digit_4) || (digit_2 == digit_3) || (digit_2 == digit_4) || (digit_3 == digit_4))
		return 0;
	else
	{
		return 1;
	}
}

//Splits the target and guess into digits, compares them and calculates number of bulls.
int getNumBulls(int target, int guess)
{
	int target_digit_1=0, target_digit_2=0, target_digit_3=0, target_digit_4=0;
	int guess_digit_1=0, guess_digit_2=0, guess_digit_3=0, guess_digit_4=0;
	int num_bulls=0;

	//Splits the target into digits.
	target_digit_4=target%10;
	target=target/10;

	target_digit_3=target%10;
	target=target/10;

	target_digit_2=target%10;
	target=target/10;

	target_digit_1=target%10;
	target=target/10;

	//Splits the guess into digits.
	guess_digit_4=guess%10;
	guess=guess/10;

	guess_digit_3=guess%10;
	guess=guess/10;

	guess_digit_2=guess%10;
	guess=guess/10;

	guess_digit_1=guess%10;
	guess=guess/10;

	//Compare the target and the guess for bulls.
	if(target_digit_1 == guess_digit_1)
		num_bulls++;

	if(target_digit_2 == guess_digit_2)
		num_bulls++;

	if(target_digit_3 == guess_digit_3)
		num_bulls++;

	if(target_digit_4 == guess_digit_4)
		num_bulls++;

	return num_bulls;
}

//Splits the target and guess into digits, compares them and calculates number of cows.
int getNumCows(int target, int guess)
{
	int target_digit_1=0, target_digit_2=0, target_digit_3=0, target_digit_4=0;
	int guess_digit_1=0, guess_digit_2=0, guess_digit_3=0, guess_digit_4=0;
	int num_cows=0;

	//Splits the target into digits.
	target_digit_4=target%10;
	target=target/10;

	target_digit_3=target%10;
	target=target/10;

	target_digit_2=target%10;
	target=target/10;

	target_digit_1=target%10;
	target=target/10;

	//Splits the guess into digits.
	guess_digit_4=guess%10;
	guess=guess/10;

	guess_digit_3=guess%10;
	guess=guess/10;

	guess_digit_2=guess%10;
	guess=guess/10;

	guess_digit_1=guess%10;
	guess=guess/10;

	//Compare the target and the guess for cows.
	if((target_digit_1 == guess_digit_2) || (target_digit_1 == guess_digit_3) || (target_digit_1 == guess_digit_4))
		num_cows++;

	if((target_digit_2 == guess_digit_1) || (target_digit_2 == guess_digit_3) || (target_digit_2 == guess_digit_4))
		num_cows++;

	if((target_digit_3 == guess_digit_1) || (target_digit_3 == guess_digit_2) || (target_digit_3 == guess_digit_4))
		num_cows++;

	if((target_digit_4 == guess_digit_1) || (target_digit_4 == guess_digit_2) || (target_digit_4 == guess_digit_3))
		num_cows++;

	return num_cows;
}

//Prints the outpout depending on the number of bulls and cows.
void printBullsAndCows(int bulls, int cows)
{
	if((bulls == 1) && (cows == 1))
	{
		printf("\nYou have 1 bull and 1 cow.\n\n");
	}
	else 
	{
		if(bulls == 1)
			{
				printf("\nYou have 1 bull and %d cows.\n\n", cows);
			}
		else
		{
			if(cows == 1)
			{
				printf("\nYou have %d bulls and 1 cow.\n\n", bulls);
			}
			else
			{
				printf("\nYou have %d bulls and %d cows.\n\n", bulls, cows);
			}
		}
	}
}
