#include <stdio.h>
#include <string.h>

#define SIZE 100

void applyCensorship(char[], const char[][SIZE]);

int main(void)
{
	const char forbidden_strings[][SIZE] = {"abc", "xyz"};
	char text[] = {"abckdm abc xyz jdgwi ngennabcwi egwnegixyz"};

	applyCensorship(text, forbidden_strings);

	printf("%s\n", text);

	return 0;
}

void applyCensorship(char text[], const char forbidden_strings[][SIZE])
{
	int i, j, string_length;
	char *pointer;
	int number_of_forbidden_strings;

	number_of_forbidden_strings = 2;

	//Finds every occurrence of every forbidden string, and replaces it with *...*
	for(i = 0; i < number_of_forbidden_strings; i++)
	{
		pointer = strcasestr(text, forbidden_strings[i]);

		string_length = strlen(forbidden_strings[i]);
		
		for(j = 0; j < string_length; j++)
		{
			*pointer = '*';
			pointer++;
		}
	}

}
