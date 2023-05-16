// link tema: https://ocw.cs.pub.ro/courses/sda-ab/tema1

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
    strcpy(newnode->teamName, teamName);
    newnode->p = (PLAY *)malloc((newnode->nr_players) * sizeof(PLAY));
    for (int j = 0; j < newnode->nr_players; j++)
    {
        fscanf(input, "%s", firstName);
        fgetc(input);
        newnode->p[j].firstName = (char *)malloc((strlen(firstName)+1) * sizeof(char));
        strcpy(newnode->p[j].firstName, firstName);
        fscanf(input, "%s", secondName);
        newnode->p[j].secondName = (char *)malloc((strlen(secondName)+1) * sizeof(char));
        strcpy(newnode->p[j].secondName, secondName);
        fscanf(input, "%d", &points);
        newnode->p[j].points = points;
        fgetc(input);
    }
    newnode->next = *head;
    *head = newnode;
}

int main(int argc, char *argv[])
{   
    FILE *c;
    if ((c = fopen(argv[1], "rt")) == NULL)
    {
        printf("Eroare la deschiderea fisierului c!\n");
        exit(1);
    }
    int tasks[5];
    for (int i = 0; i < 5; i++)
    {
        fscanf(c, "%d", &tasks[i]);
    }
    
    if (tasks[0] == 1)
    {
        FILE *input;
        if ((input = fopen(argv[2], "rt")) == NULL)
        {
            printf("Eroare la deschiderea fisierului d!\n");
            exit(1);
        }
        TEAM *head = (TEAM*)malloc(sizeof(TEAM));
        head = NULL;
        int nr_teams;
        fscanf(input, "%d", &nr_teams);
        for (int i = 0; i < nr_teams; i++)
        {
            createLIST(&head, input);
            fgetc(input);

        }
        
        FILE *rez;
        if ((rez = fopen(argv[3], "wt")) == NULL)
        {
            printf("Eroare la deschiderea fisierului rez!\n");
            exit(1);
        }
        TEAM* listHead = head;
        for (int i = 0; i < nr_teams && listHead!=NULL; i++)
        {  
            fprintf(rez, "%s\n", listHead->teamName);
            listHead = listHead->next;
        }
        fclose(input); 
        fclose(rez);
        fclose(c);
    }

    return 0;
}
