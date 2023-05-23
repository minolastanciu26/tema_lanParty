#include "header.h"

//functie pentru deschiderea fisierului
void openFile(FILE *fisier)
{
    if(fisier == NULL)
    {
        printf("Eroare la deschiderea fisierului!");
        exit(1);
    }
}

//functie pentru crearea listei
void createLIST(TEAM **head, FILE *input)
{
    TEAM *newnode = (TEAM *)malloc(sizeof(TEAM));
    int nr_players, points;
    char teamName[50], firstName[50], secondName[50];
    fscanf(input, "%d", &nr_players);
    newnode->nr_players = nr_players;
    fgetc(input);
    fgets(teamName, 50, input);
    teamName[strlen(teamName) - 2] = '\0';
    fgetc(input);
    newnode->teamName = (char *)malloc((strlen(teamName) + 1) * sizeof(char));
    strcpy(newnode->teamName, teamName);
    newnode->p = (PLAY *)malloc((newnode->nr_players) * sizeof(PLAY));
    for (int j = 0; j < newnode->nr_players; j++)
    {
        fscanf(input, "%s", firstName);
        fgetc(input);
        newnode->p[j].firstName = (char *)malloc((strlen(firstName) + 1) * sizeof(char));
        strcpy(newnode->p[j].firstName, firstName);
        fscanf(input, "%s", secondName);
        newnode->p[j].secondName = (char *)malloc((strlen(secondName) + 1) * sizeof(char));
        strcpy(newnode->p[j].secondName, secondName);
        fscanf(input, "%d", &points);
        newnode->p[j].points = points;
        fgetc(input);
    }
    newnode->next = *head;
    *head = newnode;
}

//functie pentru stergerea echipei cu punctajul minim din lista
void delete(TEAM **head, float val)
{
    if(*head == NULL) return;
    TEAM* copy = (TEAM*)malloc(sizeof(TEAM));
    copy = *head;
    if(copy->teamPoints == val)
    {
    	*head=(*head)->next;
    	free(copy);
    	return;
    }
    TEAM* prev = (TEAM*)malloc(sizeof(TEAM));
    prev = *head;
    copy = copy->next;
    while(copy != NULL)
    {
	    if(copy->teamPoints == val)
	    {
	    	prev->next = copy->next;
	    	
            free(copy);
            return;
	    }
	    else
	    {
		    prev = copy;
            copy = copy->next;
		    
	    }
    }
}

void delete_lista(TEAM **head) {
    TEAM *aux;
    aux = *head;
    while(*head) {
        aux = *head;
        *head = (*head)->next;
       // free(aux->p);
       // free(aux->teamName);
        free(aux);
    }
    free(head);
}
