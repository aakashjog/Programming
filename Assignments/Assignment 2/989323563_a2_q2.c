#include <stdio.h>
/*
	This program accepts 3 real numbers from the user. The user selects one operation, average, and median. According to the choice, the result is computed and the value is returned to the user.
*/
int main(void)
{
	char operation = 0;
	float number_1 = 0, number_2 = 0, number_3 = 0, result = 0;

	printf("Please enter 3 real numbers.\n");
	scanf("%f %f %f", &number_1, & number_2, &number_3);

	//This block validates the input received.
	while((operation != 'a') && (operation != 'A') && (operation != 'm') && (operation != 'M'))
	{
		printf("Please enter the requested operation.\n");
		printf("\tm/M : Median \n\ta/A : Average\n");
		scanf(" %c", &operation);
		if((operation != 'a') && (operation != 'A') && (operation != 'm') && (operation != 'M'))
		{
			printf("Invalid option.\n");
		}
	}
	
	//Depending on the operation selected, the average or median is computed and returned to the user.
	switch(operation)
	{
		case 'a':
		case 'A':
			result = (number_1 + number_2 + number_3)/3;
			printf("The average is %f\n", result);
			break;

		case 'm':
		case 'M':
			if(((number_1 <= number_2) && (number_1 >= number_3)) || ((number_1 <= number_3) && (number_1 >= number_2)))
				result = number_1;

			else if(((number_2 <= number_1) && (number_2 >= number_3)) || ((number_2 <= number_3) && (number_2 >= number_1)))
					result = number_2;

				else if(((number_3 <= number_1) && (number_3 >= number_2)) || ((number_3 <= number_2) && (number_3 >= number_1)))
						result = number_3;
			printf("The median is %f\n", result);
			break;
	}

	return 0;
}
