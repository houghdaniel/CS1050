/*
 * CS 1050
 * Spring 2023
 * Lab 12
 * By Daniel Hough (dshc3f)
 * April 28, 2023
 */

// Include files - do you need others?
// Included string.h to make my life easier.
#include <stdio.h>
#include <string.h>
#include "fight.h"

// Main
int main(int argc, char* argv[])
{
	// Uncomment the following line if you want random (different every time) fights
	//SetSeed(0);
    
    //variables for file and combatant names.
    FILE* fp;
    char c1Name[256], c2Name[256];

    //Check to make sure we have 3 arguments before proceeding
    if(argc == 4)
    {
        //Open the file, using the first argument for the file name.
        fp = fopen(argv[1],"r");
        if(NULL != fp)
        {
            //throw away the first line which is the header.
            fgets(c1Name,255,fp);
            c1Name[255] = '\0';

            //Copy the args which should be the combatant names into our variables for them.
            strcpy(c1Name, argv[2]);
            strcpy(c2Name, argv[3]);
            
            //vars to store name, attack damages, hp, ac, hit bonus
            char name[256], a1[256], a2[256];
            int ac,hp,thb;

            //Create combatants
            Combatant c1,c2;

            //scan the first line and store in variables.
            int i = fscanf(fp," %[^,], %d, %d, %d, %[^,], %s",name,&ac,&hp,&thb,a1,a2);
            //combatant counter
            int j = 0;
            while(6 == i)
            {
                if(strcmp(name, c1Name) == 0)
                {
                    //If name of the first combatant matches the one of the current line, then copy all of its stats into combatant 1. 
                    strcpy(c1.name, c1Name);
                    c1.ac = ac;
                    c1.hp = hp;
                    c1.hitbonus = thb;
                    strcpy(c1.attack1damage, a1);
                    strcpy(c1.attack2damage, a2);
                    //Increment combatant counter
                    j++;
                }
                else if(strcmp(name, c2Name) == 0)
                {
                    //If name of the second combatant matches the one of the current line, then copy all of its stats into combatant 2.
                    strcpy(c2.name, c2Name);
                    c2.ac = ac;
                    c2.hp = hp;
                    c2.hitbonus = thb;
                    strcpy(c2.attack1damage, a1);
                    strcpy(c2.attack2damage, a2);
                    //Increment combatant counter.
                    j++;
                }

                //Scan next line.
                i = fscanf(fp," %[^,], %d, %d, %d, %[^,], %s",name,&ac,&hp,&thb,a1,a2);

                //Once we have 2 combatants, set the loop variable to -1 so we stop looping.
                if(2==j)
                    i = -1;
            }
            
            //If the combatant counter is not 2, tell the user that the program could not find combatants, close the file, and end the program.
            if(2!=j)
            {
                printf("Could not find one or more combatants.\n");
                fclose(fp);
                return -1;
            }


            //Call fight with the 2 combatants.
            Fight(c1,c2);



        }
        else
        {
            //If the file can't be opened, tell the user.
            printf("The file could not be opened.\n");
        }
        
        //Clean up
        fclose(fp);
    }
    else
    {
        //If user doesnt put 3 arguments, tell the user the syntax.
        printf("Syntax: ./a.out combatant_file combatant1_name combatant2_name\n");
    }

}
