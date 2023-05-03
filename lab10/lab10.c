/*
 * CS1050
 * Spring 2023
 * Lab 10 
 * by Daniel Hough (dshc3f)
 * April 14, 2023
 */

// includes
#include <stdio.h>
#include <ctype.h>

// Symbolic Constants
#define S1 "1, 2, 3, 4 tell me that you love me more.  Sleepless long nights, that is what my youth was for."
#define S2 "\t99 dreams I have had.  In every 1 a red balloon."
#define S3 "And you'll start cryin' 96 tears."
#define S4 "I demand the sum of.....$1,000,000.00!"
#define STRINGCOUNT 4

////////////////
// Prototypes //
////////////////
char * Filter(char *s);

// Main
int main(void)
{
    char s[STRINGCOUNT][256]=
    {
        S1,S2,S3,S4,
    };

    printf("**** Original Strings ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,s[i]);
    }

    printf("\n\n**** Strings after filtering ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,Filter(s[i]));
    }
}

char* Filter(char* s)
{
    char notAllowed[16] = {'.','?','!',',',':',';','-','[',']','{','}','(',')','\'','"','$'};

    //Original string cursor
    int i = 0;
    //Temp string cursor
    int j = 0;

    //Boolean variable
    int b = 0;
    
    //Temporary string
    char temp[256] = {0};

    //While the current character is not the null terminator,
    while(s[i] != '\0')
    {
        //Reset boolean variable
        b = 0;
        //Loop through every character in the array of not allowed characters, and if the current character in the string is equal to any character in this array, b will equal 1. 
        for(int k = 0; k < 16; k++)
        {
            if(s[i] == notAllowed[k])
                b = 1;
        }

        //If boolean variable is zero, meaning the character is allowed,
        if(!b)
        {
            //Set the character at the temp string cursor to the character at the original string cursor and increment the temp string cursor
            temp[j] = s[i];
            j++;
        }
        //Increment original string cursor
        i++;
    }

    //Loop through the whole possible length of the string
    for(i = 0; i < 256; i++)
    {
        //In ASCII, 'A' = 65 and 'a' = 97, so in order to go from uppercase to lowercase, we can add 32 to the character. To go from lowercase to uppercase, we subtract 32 from the character.
        if(temp[i] >= 'A' && temp[i] <= 'Z')
            temp[i] += 32;
        else if(temp[i] >= 'a' && temp[i] <= 'z')
            temp[i] -= 32;
    }

    //Copy temp string back to original string location.
    for(i = 0; i < 256; i++)
    {
        s[i] = temp[i];
    }

    //Return pointer to original string.
    return s;
}



