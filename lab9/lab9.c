/*
 * CMP_SC 1050
 * SP 2023
 * Lab 9
 * By Daniel Hough (dshc3f)
 * April 7, 2023
 */

#include <stdio.h>

void getSwapDist(int* n);
void getStrLength(char* str, int* l);
void getString(char* str, int* l);
void swap(char* str, int n, int l);

int main(void)
{
    //declare variables. int n for swap dist, int l for str length, char array with length 128 for string
    int n = 0;
    int l = 0;
    char str[128] = {0};
    
    printf("Welcome to lab 9!\n");

    //Call function to prompt user for swap dist and pass in swap dist var address.
    getSwapDist(&n);

    //Call function to prompt user for string and then print it back to the user.
    getString(str, &l);
    printf("You entered: %s\n", str);

    //Call function to swap characters, and then print the modified string to the user.
    swap(str, n, l);
    printf("The modified string is: %s\n", str);

    printf("Thanks for doing Lab 9\n");

    return 0;
}

void getSwapDist(int* n)
{
    //Range given was 1-5 inclusive so loop while swap dist is outside of that range.
    while(*n > 5 || *n < 1)
    {
        //Prompt user for swap dist. Use scanf and pass in swap dist var address.
        printf("Enter a swap distance: ");
        scanf("%d", n);
    }
}

//Created this function b/c we need to check the length of the string the user enters to make sure it is 20-40 chars inclusive.
void getStrLength(char* str, int* l)
{
    //Declare counter var
    int i = 0;
    //Loop through the characters in the string until we hit null terminator, and increment counter until we hit null terminator.
    while(*(str+i) != 0)
        i++;

    //set length equal to counter
    *l = i;
}

void getString(char* str, int* l)
{
    //Given range was 20-40 chars inclusive, so loop while length of str is outside of that range.
    while(*l > 40 || *l < 20)
    {
        //Prompt user, then use scanf passing str address, then check str length passing address to length var to edit the original.
        printf("Enter a string with a length between 20 and 40 inclusive:\n");
        scanf("%s",str);
        getStrLength(str, l);
    }
}

void swap(char* str, int n, int l)
{
    //create a temp variable to hold a char while we swap
    char temp;
    //loop through each character in the string, incrementing by 1 more than the swap distance.
    for(int i = 0; i < l-1; i+= (n+1))
    {
        //if the swap wont go off the end, 
        if(i+n < l)
        {
            //set the temp var to the char at the current spot
            temp = *(str+i);
            //then set the char at the current spot to the char that is 1 swap dist away
            *(str+i) = *(str+i+n);
            //then set the char at the spot 1 swap dist away to the temp char, which is the original char at the current spot.
            *(str+i+n) = temp;
        }
    }
}

