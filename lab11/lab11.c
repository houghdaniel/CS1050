/*
 * CMP_SC 1050
 * Spring 2023
 * Lab 11
 * By Daniel Hough (dshc3f)
 * April 21, 2023
 */

#include <stdio.h>
#include <string.h>

struct _Team
{
    char city[256];
    char name[256];
};
typedef struct _Team Team;

struct _Player
{
	char firstName[256];
    char lastName[256];
    long salary;
    Team team;
};
typedef struct _Player Player;


void printArray(Player* players, int n);
void sortLName(Player* players, int n);
void sortFName(Player* players, int n);
void sortSalary(Player* players, int n);

int main(void)
{
	Player players[] = 
    {
		{"Corey","Seager",32500000,{"Texas","Rangers"}},
		{"Stephen","Strasburg",35000000,{"Washington","Nationals"}},
		{"Gerrit","Cole",36000000, {"New York","Yankees"}},
		{"Mike","Trout",35500000, {"Los Angeles","Angels"}},
		{"Carlos","Correa",35100000,{"Minnesota","Twins"}},
		{"Anthony","Rendon",35000000,{"Los Angeles","Angels"}},
		{"Francisco","Lindor",34100000,{"New York","Mets"}},
		{"Trevor","Bauer",34000000,{"Los Angeles","Dodgers"}},
		{"Nolan","Arenado",32500000,{"St. Louis","Cardinals"}},
		{"Max","Scherzer",43300000,{"New York","Mets"}},
    };
    
    printf("Players:\n");
    //Print out all the players names, salaries, and teams
    printArray(players, sizeof(players)/sizeof(Player));

    printf("\nPlayers by last name:\n");
    //Sort players by last name and then print the array again.
    sortLName(players, sizeof(players)/sizeof(Player));
    printArray(players, sizeof(players)/sizeof(Player));

    printf("\nPlayers by first name:\n");
    //Sort players by first name and then print array
    sortFName(players, sizeof(players)/sizeof(Player));
    printArray(players, sizeof(players)/sizeof(Player));

    printf("\nPlayers by salary:\n");
    //Sort players by salary then print array.
    sortSalary(players, sizeof(players)/sizeof(Player));
    printArray(players, sizeof(players)/sizeof(Player));

    printf("\n");
    return 0;
}

void sortLName(Player* players, int n)
{
    //Create temporary player variable
    Player temp;

    //Bubble sort
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            //If the current player's last name is lower in the alphabet than the next player's last name, swap the two players.
            if(strcmp(players[j].lastName, players[j+1].lastName) > 0)
            {
                temp = players[j];
                players[j] = players[j+1];
                players[j+1] = temp;
            }
        }
    }
}

void sortFName(Player* players, int n)
{
    //Create temporary player.
    Player temp;

    //Bubble sort
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            //If the current player's first name is lower in the alphabet than the next player's first name, swap the two players.
            if(strcmp(players[j].firstName, players[j+1].firstName) > 0)
            {
                temp = players[j];
                players[j] = players[j+1];
                players[j+1] = temp;
            }
        }
    }
}

void sortSalary(Player* players, int n)
{
    //Create temporary player.
    Player temp;

    //Bubble sort
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            //If the current player's salary is greater than the next player's salary, swap the two players.
            if(players[j].salary > players[j+1].salary)
            {
                temp = players[j];
                players[j] = players[j+1];
                players[j+1] = temp;
            }
        }
    }
}

void printArray(Player* players, int n)
{
    //Print column headers, putting 10 characters for each field b/c that is how long the longest field is.
    printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "First Name", "Last Name", "Salary", "Team City", "Team Name");
    //Loop through elements of players array, and print the first name, last name, salary, team city and team name for each player with the same spacing as the column headers.
    for(int i = 0; i < n; i++)
        printf("%-10s\t%-10s\t%ld\t%-10s\t%-10s\n", players[i].firstName, players[i].lastName, players[i].salary, players[i].team.city, players[i].team.name);
}
