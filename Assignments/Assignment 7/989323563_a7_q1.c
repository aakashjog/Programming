#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 6

int validateData(int *, char *[], int);
int findFaiures(int[], char *[], int, char *[], double *, int *);
void removeEntry(int[], char *[], int, int);
void deleteEntries(int[], char *[], int, int);

int main(void)
{
	char *names[SIZE];
	int grades[SIZE];
	int i, size = SIZE;

	for(i = 0; i < SIZE; i++)
	{
		names[i] = (char*) malloc (100 * sizeof(char));
	}

	printf("Please enter the names and grades of 6 students.\n");
	scanf("%s %d %s %d %s %d %s %d %s %d %s %d", names[0], &grades[0], names[1], &grades[1], names[2], &grades[2], names[3], &grades[3], names[4], &grades[4], names[5], &grades[5]);

	printf("\n---Original names---\n");
	for(i = 0; i < size; i++)
	{
		printf("\n%s : %d\n", names[i], grades[i]);
	}

	size = validateData(grades, names, size);

	printf("\n---Valid names---\n");
	for(i = 0; i < size; i++)
	{
		printf("\n%s : %d\n", names[i], grades[i]);
	}

	return 0;
}

int validateData(int grades[], char *names[], int size)
{
	int i = 0, j = 0, deletions = 0, name_length = 0;
	char *temporary_names[size];

	for(i = 0; i < size; i++)
	{
		temporary_names[i] = names[i];
	}

	for(i = 0; i < size; i++)
	{
		if((grades[i] > 100) || (grades[i] < 0))
		{
			if(i != size - 1)
			{
				removeEntry(grades, names, i, size);
			}

			deletions++;
		}
	}
	
	deleteEntries(grades, names, deletions, size);

	size = size - deletions;
	deletions = 0;

	for(i = 0; i < size; i++)
	{
		name_length = strlen(names[i]);

		for(j = 0; j < name_length ; j++)
		{
			if(isalpha(*temporary_names[i]) == 0)
			{
				if(i != size - 1)
				{
					removeEntry(grades, names, i, size);
				}

				deletions++;
			}

			temporary_names[i]++;
		}
	}

	deleteEntries(grades, names, deletions, size);

	size = size - deletions;

	return size;
}

int findFaiures(int grades[], char *names[], int number_of_students, char *failed[], double *average, int *maximal)
{
	return 0;
}

void removeEntry(int grades[], char *names[], int i, int size)
{
	do
	{
		strcpy(names[i], names[i + 1]);	
		grades[i] = grades[i + 1];

		i++;
	}
	while(i + 1 < size);
}

void deleteEntries(int grades[], char *names[], int deletions, int size)
{
	int i = 0;

	for(i = 0; i < deletions; i++)
	{
		strcpy(names[(size - 1) - i], "\0");
		grades[(size - 1)- i] = -1;
	}
}
