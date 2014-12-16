#include <stdio.h>
#include <math.h>
/*
	This program accepts the coefficients of a quadratic equation, calculates the discriminant, and return the roots of the quadratic equation.
*/
int main(void)
{
	float a, b, c;
	float discriminant,first_root,second_root;

	/*	This block accepts a, b, c, the coefficients of x^2, x^1, and x^0 respectively.	*/
	printf("Enter a, b and c of quadratic equation: ");
	scanf("%f %f %f", &a, &b, &c);

	/*	The discriminant is calculated according to the standard quadratic formula, with the values of a, b, c, specified by the user.	*/
	discriminant = (b * b) - (4 * a * c);

	/*	According to the standard quadratic formula, if the discriminant is negative, the roots of the equation are complex, and are as mentioned.	*/
	if(discriminant < 0)
	{
		printf("Roots are complex number.\n");
		printf("Roots of quadratic equation are: ");
		printf("%.3f + %.3fi",-b/(2*a),sqrt(-discriminant)/(2*a));
		printf(", %.3f + %.3fi \n",-b/(2*a),-sqrt(-discriminant)/(2*a));
	}

	/*	According to the standard quadratic formula, if the discriminant is zero, the roots of the equation are real and repeated, and are as mentioned.	*/
	else if(discriminant == 0)
	{
		printf("Both roots are equal.\n");
		first_root = -b /(2*a);
		printf("Root of quadratic equation is: %.3f \n",first_root);
	}

	/*	According to the standard quadratic formula, if the discriminant is positive, the roots of the equation are real and distinct, and are as mentioned.	*/
	else
	{	
		printf("Roots are real numbers.\n");
		first_root = ( -b + sqrt(discriminant)) / (2*a);
		second_root = ( -b - sqrt(discriminant)) / (2*a);
		printf("Roots of quadratic equation are: %.3f , %.3f \n", first_root, second_root);
	}

	return 0;
}
