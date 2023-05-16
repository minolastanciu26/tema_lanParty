#include "functii.h"

void createLIST(TEAM **head, FILE *input)
{   
    TEAM *newnode = (TEAM *)malloc(sizeof(TEAM));
    int nr_players, points;
    char teamName[50], firstName[50], secondName[50];
    fscanf(input, "%d", &nr_players);
    newnode->nr_players = nr_players;
    fgetc(input);
    fscanf(input, "%[^\n]", teamName);
    fgetc(input);
    newnode->teamName = (char *)malloc((strlen(teamName)+1) * sizeof(char));
    newnode->teamName = teamName;
    newnode->p = (PLAY *)malloc((newnode->nr_players) * sizeof(PLAY));
    for (int j = 0; j < newnode->nr_players; j++)
    {
        fscanf(input, "%s", firstName);
        fgetc(input);
        newnode->p[j].firstName = (char *)malloc((strlen(firstName)+1) * sizeof(char));
        newnode->p[j].firstName = firstName;
        fscanf(input, "%s", secondName);
        newnode->p[j].secondName = (char *)malloc((strlen(secondName)+1) * sizeof(char));
        newnode->p[j].secondName = secondName;
        fscanf(input, "%d", &points);
        newnode->p[j].points = points;
        fgetc(input);
    }
    newnode->next = *head;
    *head = newnode;
}