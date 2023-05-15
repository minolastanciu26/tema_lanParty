#include "functii.h"

void createLIST(TEAM** head, char* argv[])
{
    FILE* input;
    if((input=fopen("argv[1]","rt"))==NULL)
    {
        printf("Eroare la deschiderea fisierului de intrare!\n");
        exit(1);
    }
    int nr_teams;
    fscanf(input,"%d",&nr_teams);
    printf("%d",nr_teams);
    TEAM* newnode=(TEAM*)malloc(sizeof(TEAM));
    char c;
    for(int i=0; i < nr_teams; i++)
    {
        int nr_players, points;
        char teamName[50], firstName[50], secondName[50];
        while ((c = getc(input)) != EOF && c != '\n') continue;
            fscanf(input,"%d",&nr_players);
            newnode->nr_players=nr_players;
            fscanf(input,"%s ", teamName);
            newnode->teamName=(char*)malloc(strlen(teamName)*sizeof(char));
            newnode->teamName=teamName;
            newnode->p=(PLAY*)malloc((newnode->nr_players)*sizeof(PLAY));
            for(int j=0; j < newnode->nr_players; j++)
            {
                fscanf(input,"%s", firstName);
                newnode->p[j].firstName=(char*)malloc(strlen(firstName)*sizeof(char));
                newnode->p[j].firstName=firstName;
                fscanf(input,"%s", secondName);
                newnode->p[j].secondName=(char*)malloc(strlen(secondName)*sizeof(char));
                newnode->p[j].secondName=secondName;
                fscanf(input,"%d", &points);
                newnode->p[j].points=points;
                getc(input);
            }
            newnode->next=*head;
            *head=newnode;
            getc(input);
    }
    fclose(input);
}