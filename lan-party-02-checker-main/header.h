#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structuri de date
struct Player
{
    char *firstName;
    char *secondName;
    int points;
};

typedef struct Player PLAY;

struct Team
{
    int nr_players;
    char *teamName;
    PLAY *p;
    struct Team *next;
    float teamPoints;
};

typedef struct Team TEAM;



//functii
void openFile(FILE *fisier);
//task1
void createLIST(TEAM **head, FILE *input);
//task2
void delete(TEAM **head, float val);
//task3
