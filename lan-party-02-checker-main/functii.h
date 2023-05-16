#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char* firstName;
    char* secondName;
    int points;
};

typedef struct Player PLAY;

struct Team
{
    int nr_players;
    char* teamName;
    PLAY *p;
    struct Team *next;
};

typedef struct Team TEAM;

void createLIST(TEAM **head,FILE* input);

