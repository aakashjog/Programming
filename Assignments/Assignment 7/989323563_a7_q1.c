#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int validateData(int *, char *[], int);
int findFaiures(int[], char *[], int, char *[], double *, int *);
void removeEntry(int[], char *[], int, int);
void deleteEntries(int[], char *[], int, int);

int main(void)
{
	int i, size = 6, number_of_failed_students = 0;
	char *names[size], *failed[size];
	int grades[size];
	double avg;
	double *average = &avg;
	int max;
	int *maximal = &max;

	//Allocates memory for each student's name.
	for(i = 0; i < size; i++)
	{
		names[i] = (char*) malloc (100 * sizeof(char));
		if(names[i] == NULL)
		{
			printf("Memory allocation failed.\n");
			return 1;
		}
	}
	
	//Allocates memory for each failed student's name.
	for(i = 0; i < size; i++)
	{
		failed[i] = (char*) malloc (100 * sizeof(char));
		if(failed[i] == NULL)
		{
			printf("Memory allocation failed.\n");
			return 1;
		}
	}

	printf("Please enter the names and grades of 6 students.\n");
	scanf("%s %d %s %d %s %d %s %d %s %d %s %d", names[0], &grades[0], names[1], &grades[1], names[2], &grades[2], names[3], &grades[3], names[4], &grades[4], names[5], &grades[5]);

	size = validateData(grades, names, size);

	number_of_failed_students = findFaiures(grades, names, size, failed, average, maximal);

	//Prints the average grade, maximal grade and the names of students who failed.
	printf("\nAverage grade : %lf\n", avg);

	printf("\nMaximal grade : %d\n", max);

	printf("\n%d students failed:\n", number_of_failed_students);
	for(i = 0; i < number_of_failed_students; i++)
	{
		printf("%s\n", failed[i]);
	}

	return 0;
}

int validateData(int grades[], char *names[], int size)
{
	int i = 0, j = 0, deletions = 0, name_length = 0;
	char *temporary_names[size];//Creates temporary pointers which can be changed without affecting the locations of the original pointers.

	for(i = 0; i < size; i++)
	{
		temporary_names[i] = names[i];
	}

	//Checks for invalid grades and removes entries with invalid grades.
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
	
	//Deletes duplicate entries created due to removing invalid entries.
	deleteEntries(grades, names, deletions, size);

	//Redifines size after deletion of entries.
	size = size - deletions;
	deletions = 0;

	//Checks for invalid names and removes entries with invalid names.
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

	//Deletes duplicate entries created due to removing invalid entries.
	deleteEntries(grades, names, deletions, size);

	//Redifines size after deletion of entries.
	size = size - deletions;

	return size;
}

int findFaiures(int grades[], char *names[], int number_of_students, char *failed[], double *average, int *maximal)
{
	int i = 0, j = 0, number_of_failed_students = 0, sum = 0;

	//Checks for students who scored below 60, and adds their names to the list of failed students.
	for(i = 0; i < number_of_students; i++)
	{
		if(grades[i] < 60)
		{
			strcpy(failed[j], names[i]);
			j++;
		}
	}

	number_of_failed_students = j;

	//Calculates the sum of the grades of all students.
	for(i = 0; i < number_of_students; i++)
	{
		sum = sum + grades[i];
	}

	//Calculates the average grades.
	*average = (float) sum / (float) number_of_students;

	//Finds the maximal grade.
	*maximal = grades[0];
	for(i = 0; i < number_of_students; i++)
	{
		if(grades[i] > *maximal)
		{
			*maximal = grades[i];
		}
	}

	return number_of_failed_students;
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
