/*
 * CMP_SC 1050
 * SP 2023
 * Lab 3
 * By Daniel Hough (dshc3f)
 * February 3, 2023
 */

//Include stdio.h to be able to use printf
#include <stdio.h>

int main(void)
{
    //Set our number as the initial number
    int i = 100;
    //Loop while our number is greater than or equal to 1
    while(i >= 1)
    {
        //Check if our number is odd
        if(i % 2 != 0)
        {
            //If the number is odd and divisible by 3, print T
            if(i % 3 == 0)
                printf("T");
            //If the number is odd and divisible by 7, print S
            if(i % 7 == 0)
                printf("S");
            //Print our number followed by a space
            printf("%d ", i);
        }
        //Decrement our number
        i--;
    }

    //Indicate successful completion of the program
    return 0;
}
