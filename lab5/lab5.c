/*
 * CMP_SC 1050
 * SP 2023
 * Lab 5
 * By Daniel Hough (dshc3f)
 * February 24, 2023
 */

#include <stdio.h>

int isPrime(int n);

int main(void)
{
    //Loop through numbers 1 to 100 and check if the number is prime.
    for(int i = 1; i <= 100; i++)
        if(isPrime(i))
            //If it is prime, print the number followed by a space.
            printf("%d ", i);

    //Indicate successful completion of program
    return 0;
}

int isPrime(int n)
{
    //Since prime numbers are only divisible by two numbers, begin with a counter at 2.
    int count = 2;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            //If n is divisible by a number, decrement the count var
            count--;
    }

    //Return 1 when count is zero indicating a prime number, and 0 when count is any other number.
    return !count;
}

