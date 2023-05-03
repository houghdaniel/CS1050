/*
 * CMP_SC 1050
 * SP 2023
 * Lab 7
 * By Daniel Hough (dshc3f)
 * March 10, 2023
 */

#include <stdio.h>

#define G_ROWS 12
#define C_ROWS 4
#define COLS 3

void print2DArray(char array[][COLS], int rows, int selection);
void calcGrades(char scores[G_ROWS][COLS], char cutoffs[C_ROWS][COLS], char grades[G_ROWS][COLS]);

int main(void)
{
    char scores[G_ROWS][COLS] = 
    {
        {72,68,62},
        {95,88,95},
        {93,97,86},
        {98,77,98},
        {99,92,90},
        {47,32,27},
        {97,99,75},
        {85,95,91},
        {96,91,99},
        {94,90,74},
        {98,98,90},
        {76,82,98},
    };

    char cutoffs[C_ROWS][COLS] = 
    {
        {85,90,90},
        {75,80,75},
        {60,70,55},
        {50,60,40},
    };

    char grades[G_ROWS][COLS] = {0};
    
    printf("Here are the scores:\n");
    print2DArray(scores, G_ROWS, 0);

    printf("Here are the grade cutoffs:\n");
    print2DArray(cutoffs, C_ROWS, 0);

    calcGrades(scores, cutoffs, grades);
    printf("Here are the grades:\n");
    print2DArray(grades, G_ROWS, 1);
    return 0;
}

void print2DArray(char array[][COLS], int rows, int selection)
{
    for(int i = 0; i < rows; i++)
    {
        printf("%s %d:",selection?"Student":"Row",i);
        for(int j = 0; j < COLS; j++)
        {
            switch(selection)
            {
                case 0:
                    printf(" %d",array[i][j]);
                    break;
                case 1:
                    printf(" %c",array[i][j]);
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void calcGrades(char scores[G_ROWS][COLS], char cutoffs[C_ROWS][COLS], char grades[G_ROWS][COLS])
{
    for(int i = 0; i < G_ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(scores[i][j] >= cutoffs[0][j])
                grades[i][j] = 'A';
            else if(scores[i][j] >= cutoffs[1][j])
                grades[i][j] = 'B';
            else if(scores[i][j] >= cutoffs[2][j])
                grades[i][j] = 'C';
            else if(scores[i][j] >= cutoffs[3][j])
                grades[i][j] = 'D';
            else
                grades[i][j] = 'F';
        }
    }
}

