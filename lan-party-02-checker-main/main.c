// link tema: https://ocw.cs.pub.ro/courses/sda-ab/tema1

#include "functii.h"

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
            getc(input);

        }
        
        FILE *rez;
        if ((rez = fopen(argv[3], "wt")) == NULL)
        {
            printf("Eroare la deschiderea fisierului rez!\n");
            exit(1);
        }
        for (int i = 0; i < nr_teams && head!=NULL; i++)
        {  
            //printf("%s", head->teamName);
            //fprintf(rez, "%s", head->teamName);
            head = head->next;
        }
        fclose(input); //BOO!
        fclose(rez);
        fclose(c);
    }

    return 0;
}
