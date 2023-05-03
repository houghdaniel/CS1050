/*
 * CMP_SC 1050
 * SP 2023
 * Lab 6
 * By Daniel Hough (dshc3f)
 * March 3, 2023
 */

#include <stdio.h>

#define SIZE 50

void printArray(int array[], int size);
void calcArrays(int array[], int size, int start);

int main(void)
{
    //declare, intialize, and print array
    int array[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        //We only want the even numbers 0-98 so multiply the index by 2 for the value at a given index.
        array[i] = 2*i;
    }

    //Print out the array to show it contains the correct numbers.
    printArray(array, SIZE);

    //Call function to calculate total and average of elements. Set 0 as start for the even-indexed elements.
    calcArrays(array, SIZE, 0);

    //Call function again but with start as 1 for the odd-indexed elements.
    calcArrays(array, SIZE, 1);

    //Indicate successful completion of program.
    return 0;
}

//This function loops through each element of an array of a given size and prints the value of each element.
void printArray(int array[], int size) 
{
    printf("Array elements:\n");
    for(int i = 0; i < size; i++)
        printf("array[%d]=%d, ",i,array[i]);
    printf("\n");
}


void calcArrays(int array[], int size, int start)
{
    int total = 0;
    int count = 0;
    //Loop through and add up every other element given a start value. The start should be zero for even-indexed elements and one for odd-indexed elements. We also keep a count of how many elements we are adding up in order to find the average later.
    for(int i = start; i < size; i+=2)
    {
        total += array[i];
        count++;
    }

    //For %s, we know that for our odd-indexed elements, start will be 1 so if we use the conditional expression, start will be true so %s will be "odd".
    //Since start will be 0 for even-indexed elements, start will be false so %s will be "even".
    //For %d we just print the total of the even- or odd-indexed elements
    //For %.2f we cast the total to a float and then divide by the count to find the average. We cast to a float so that we aren't doing integer division so in the case that it doesn't divide evenly, we have decimals.
    printf("Total of array %s-indexed elements = %d, average = %.2f\n", start?"odd":"even", total, (float)total / count);
}


