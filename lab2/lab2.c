/***************************************
 * CMP_SC 1050
 * SP 2023
 * Lab 2
 * By Daniel Hough (dshc3f)
 * January 27, 2023
 ***************************************/

#include <stdio.h>

int main(void)
{
	//Create integer variables for X and Y.
	int x, y;

	//Tell the user what we want them to do.
	printf("Please input two numbers: ");
	//Use scanf with parameters "%d%d" to indicate we want to input 2 decimal numbers, and pointers to our x and y variables, where we want to store the input.
	scanf("%d%d", &x, &y);
	
	//Print X and Y variables back to the user.
	printf("X = %d, Y = %d\n", x, y);
	//Print the product of X and Y.
	printf("X times Y = %d\n", x*y);
	//Print the integer quotient of X divided by Y.
	printf("X divided by Y = %d\n", x/y);
	//Print the product of (x+1) and y.
	printf("X plus 1 quantity times Y = %d\n", (x+1)*y);
	//Print X and Y variables again to show they have not changed.
	printf("X = %d, Y = %d\n", x, y);

	return 0;
}
