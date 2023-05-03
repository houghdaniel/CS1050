/*
 * CMP_SC 1050
 * SP 2023
 * Lab 4
 * By Daniel Hough (dshc3f)
 * February 10, 2023
 */

#include <stdio.h>

int main(void)
{

    for(int i = 11; i <= 99; i++)
    {
        //Switch statement for tens spot, except 11-19. 
        switch(i / 10)
        {
            case 2:
                printf("twenty");
                break;
            case 3:
                printf("thirty");
                break;
            case 4:
                printf("forty");
                break;
            case 5:
                printf("fifty");
                break;
            case 6:
                printf("sixty");
                break;
            case 7:
                printf("seventy");
                break;
            case 8:
                printf("eighty");
                break;
            case 9:
                printf("ninety");
                break;
            default:
                break;
        }

        //Switch statement for ones spot, also deals with 11-19
        switch(i % 10)
        {
            //Check if the tens spot is a one, and if so, print the right
            //teen number. If tens spot is not one, print the number in
            //the ones spot.
            case 1:
                printf("%s", (i / 10 == 1) ? "eleven" : " one");
                break;
            case 2:
                printf("%s", (i / 10 == 1) ? "twelve" : " two");
                break;
            case 3:
                printf("%s", (i / 10 == 1) ? "thirteen" : " three");
                break;
            case 4:
                printf("%s", (i / 10 == 1) ? "fourteen" : " four");
                break;
            case 5:
                printf("%s", (i / 10 == 1) ? "fifteen" : " five");
                break;
            case 6:
                printf("%s", (i / 10 == 1) ? "sixteen" : " six");
                break;
            case 7:
                printf("%s", (i / 10 == 1) ? "seventeen" : " seven");
                break;
            case 8:
                printf("%s", (i / 10 == 1) ? "eighteen" : " eight");
                break;
            case 9:
                printf("%s", (i / 10 == 1) ? "nineteen" : " nine");
                break;
            default:
                break;
        }
        
        //Print a comma if we're not at the last value.
        //If we are at the last value, print a new
        //line character so the output looks pretty.
        switch(i)
        {
            case 99:
                printf("\n");
                break;
            default:
                printf(", ");
                break;
        }

    }

    //Indicate successful completion of program.
    return 0;
}
