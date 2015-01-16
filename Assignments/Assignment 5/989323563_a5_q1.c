#include <stdio.h>

#define SIZE  5

void readMatrix(int[SIZE][SIZE]);
void printMatrix(int[SIZE][SIZE]);
void initializeMatrix(int[SIZE][SIZE]);
void logicalMultiplication(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result_matrix[SIZE][SIZE]);
void convertToBooleanMatrix(int matrix[SIZE][SIZE], int boolean_matrix[SIZE][SIZE]);

int main(void)
{
	int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE];
	int boolean_matrix1[SIZE][SIZE], boolean_matrix2[SIZE][SIZE];
	int result_matrix[SIZE][SIZE];

	//Initializes and reads the first matrix.
	initializeMatrix(matrix1);
	printf("Please enter the values of the first 5x5 matrix, in a single line.\n");
	readMatrix(matrix1);

	//Initializes and reads the second matrix.
	initializeMatrix(matrix2);
	printf("Please enter the values of the second 5x5 matrix, in a single line.\n");
	readMatrix(matrix2);
	
	//Converts both matrices to boolean.
	convertToBooleanMatrix(matrix1, boolean_matrix1);
	convertToBooleanMatrix(matrix2, boolean_matrix2);

	//Prints the boolean matrices.
	printf("The boolean form of the matrices entered are:\n");
	printMatrix(boolean_matrix1);
	printf("\n");
	printMatrix(boolean_matrix2);

	//Computes the result matrix.
	logicalMultiplication(matrix1, matrix2, result_matrix);	
	
	//Prints the result matrix.
	printf("The logical multiplication of the matrices is\n");
	printMatrix(result_matrix);

	return 0;
}

void readMatrix(int matrix[SIZE][SIZE])
{
	int row, column;
	char space_character;

	for(row = 0; row < SIZE; row++)
	{
		for(column = 0; column < SIZE; column++)
		{
			//Accepts an integer and a character from the user. Stops accepting integers when the character is '\n'.
			scanf("%d%c", &matrix[row][column], &space_character);

			if(space_character == '\n')
			{
				return;
			}
		}
	}
}

void printMatrix(int matrix[SIZE][SIZE])
{
	int row, column;

	for(row = 0; row < SIZE; row++)
	{
		for(column = 0; column < SIZE; column++)
		{
			printf("%d ", matrix[row][column]);
		}

		printf("\n");
	}
}

void convertToBooleanMatrix(int matrix[SIZE][SIZE], int boolean_matrix[SIZE][SIZE])
{
	int row, column;

	for(row = 0; row < SIZE; row++)
	{
		for(column = 0; column < SIZE; column++)
		{
			//Converts all non-zero entries to 1.
			if(matrix[row][column] == 0)
			{
				boolean_matrix[row][column] = 0;
			}
			else
			{
				boolean_matrix[row][column] = 1;
			}
		}
	}
}

void logicalMultiplication(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result_matrix[SIZE][SIZE])
{
	int i, j, k;

	initializeMatrix(result_matrix);

	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			for(k = 0; k < SIZE; k++)
			{
				result_matrix[i][j] = result_matrix[i][j] || (matrix1[i][k] && matrix2[k][j]);
			}
		}
	}
}

void initializeMatrix(int matrix[SIZE][SIZE])
{
	int row, column;

	for(row = 0; row < SIZE; row++)
	{
		for(column = 0; column < SIZE; column++)
		{
			matrix[row][column] = 0;
		}
	}
}
