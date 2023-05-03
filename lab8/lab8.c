/*
 * CMP_SC 1050
 * SP 2023
 * Lab 8
 * By Daniel Hough (dshc3f)
 * March 17, 2023
 */

#include <stdio.h>
#include <limits.h>

void getIntArray(int* outputArray, int* count);
void printArray(int* array, int count);
int sumArray(int* array, int count);
int maxArray(int* array, int count);
int minArray(int* array, int count);

int main(void)
{
    printf("Welcome to Lab 8\n");

    //declare variable for the number of elements, and an array of big size
    int n;
    int array[256];

    getIntArray(array, &n);

    printArray(array, n);

    printf("Total of all array elements = %d\n", sumArray(array, n));

    printf("The largest element = %d\n", maxArray(array, n));

    printf("The smallest element = %d\n", minArray(array, n));

    return 0;
}


void getIntArray(int* outputArray, int* count)
{
    //Prompt the user for the number of elements, then scan and store at count, which when called in this program is the variable n in main
    printf("Enter the number of elements in the array: ");
    scanf("%d", count);
    
    //Loop through the number of elements the user specified and take input for each element.
    for(int i = 0; i < *count; i++)
    {
        printf("\tEnter element #%d: ", i);
        //The outputArray pointer passed in is the address of the 0 element of the array in main, so the pointer to each element is (outputArray+i) starting with i=0.
        scanf("%d", (outputArray+i));
    }
}

void printArray(int* array, int count)
{
    printf("Here are the %d elements of your array:\n", count);
    //Loop through the number of elements the user specified
    for(int i = 0; i < count; i++)
        //This pointer has the same reasoning as in getIntArray only here we are dereferencing it to get the value at that address.
        printf("\tElement %d = %d\n", i, *(array+i));
}

int sumArray(int* array, int count)
{
    int sum = 0;
    //Loop through the number of elements the user specified
    for(int i = 0; i < count; i++)
        //Add the value at the address of each element of the array to our sum
        sum += *(array+i);

    //Return the sum after done looping
    return sum;
}

int maxArray(int* array, int count)
{
    //Start with the max value being the lowest the int type can go. 
    int max = INT_MIN;

    //For each element in the array, if the value of the element is greater than the max value, set the max value to the value of the current element.
    for(int i = 0; i < count; i++)
    {
        if(*(array+i) > max)
            max = *(array+i);
    }
    //Return the highest element after done looping
    return max;
}

int minArray(int* array, int count)
{
    //Start with the min value being the highest the int type can go.
    int min = INT_MAX;

    //For each element in the array, if the value of the element is less than the min value, set the min value to the value of the current element.
    for(int i = 0; i < count; i++)
    {
        if(*(array+i) < min)
            min = *(array+i);
    }
    //Return the lowest element after done looping.
    return min;
}

