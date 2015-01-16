#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 256

void applyCensorship(char[], const char[][SIZE]);
double string_to_double(char[]);

int main(void)
{
	const char forbidden_strings[][SIZE] = {"abc", "123"};
	char text[] = "bc abcwiw23 123 hf abc1 sfoj21oabc23";

	char number_as_string[] = "-2348.231";
	double number = string_to_double(number_as_string);

	applyCensorship(text, forbidden_strings);
	printf("Censored text:\n%s\n\n", text);

	printf("Number as double:\n%lf\n\n", number); 

	return 0;
}

void applyCensorship(char text[], const char forbidden_strings[][SIZE])
{
	int i = 0, j = 0, string_length = 0;
	char *pointer;
	int number_of_forbidden_strings = 0;

	number_of_forbidden_strings = 2;

	//Finds every occurrence of every forbidden string, and replaces it with *...*
	for(i = 0; i < number_of_forbidden_strings; i++)
	{
		while(1)
		{
			if(strcasestr(text, forbidden_strings[i]) == NULL)
			{
				break;
			}
			pointer = strcasestr(text, forbidden_strings[i]);

			string_length = strlen(forbidden_strings[i]);
	
			for(j = 0; j < string_length; j++)
			{
				*pointer = '*';
				pointer++;
			}
		}
	}
}

//Converts a number written as a string into a double.
double string_to_double (char number_as_string[])
{
	double number = 0;
	int i = 0, j = 0, k = 0, p = -1, sign = 1, is_int = 1;

	//Checks if the number entered is negative. If it is negative, the variable 'sign' is set to -1.
	if (number_as_string[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	for(j = 0; j < strlen(number_as_string); j++)
	{
		if(number_as_string[j] == '.')
		{
			while (number_as_string[i] != '.') 
			{
				number = number * 10 + (number_as_string[i] - '0');
				i++;
			}
			i++;
			while (number_as_string[i] != '\0')
			{
				number = number + ((number_as_string[i]-'0') * pow(10,p));
				p--;
				i++;
			}
			is_int = 0;
			break;
		}
	}
	if(is_int == 1)
	{
		while (number_as_string[i] != '\0') 
		{
			number = number * 10 + (number_as_string[i] - '0');
			i++;
		}
	}

	//Assigns the number its appropriate sign.
	number = number*sign;

	return number;
}
