// link tema: https://ocw.cs.pub.ro/courses/sda-ab/tema1

#include "header.h"

int main(int argc, char *argv[])
{
    // deschide fisierele
    FILE *c = fopen(argv[1], "rt");
    openFile(c);
    FILE *d = fopen(argv[2], "rt");
    openFile(d);
    FILE *r = fopen(argv[3], "wt");
    openFile(r);

    // citeste continutul fisierului c.in
    int tasks[6];
    for (int i = 0; i < 5; i++)
    {
        fscanf(c, "%d", &tasks[i]);
    }

    // citeste cate echipe sunt in fisierul d.in si creeaza lista cu acestea
    TEAM *head = (TEAM *)malloc(sizeof(TEAM));
    head = NULL;
    int nr_teams;
    fscanf(d, "%d", &nr_teams);
    for (int i = 0; i < nr_teams; i++)
    {
        createLIST(&head, d);
        fgetc(d);
    }

    // rezolva task-ul 1, afisand numele echipelor in fisierul r.out
    if (tasks[0] == 1 && tasks[1] == 0)
    {
        TEAM *listHead = head;
        for (int i = 0; i < nr_teams && listHead != NULL; i++)
        {
            fprintf(r, "%s\n", listHead->teamName);
            listHead = listHead->next;
        }
    }

    // rezolva task-ul 2
    // calculeaza n maxim
    int n = 1;
    int rounds = 0;
    while (n * 2 <= nr_teams)
    {
        n = n * 2;
        rounds++;
    }
    if (tasks[1] == 1)
    {
        // calculeaza punctajul pentru fiecare echipa
        TEAM *aux = (TEAM *)malloc(sizeof(TEAM));
        aux = head;
        for (int i = 0; i < nr_teams && aux != NULL; i++)
        {
            aux->teamPoints = 0;
            for (int j = 0; j < aux->nr_players; j++)
                aux->teamPoints = aux->teamPoints + aux->p[j].points;
            aux->teamPoints = aux->teamPoints / (aux->nr_players * (1.0));
            aux = aux->next;
        }
        // elimina echipa cu punctajul minim pana ajung sa fie n echipe
        while (nr_teams > n && head != NULL)
        {
            TEAM *head_copy = (TEAM *)malloc(sizeof(TEAM));
            head_copy = head;
            float mini = head_copy->teamPoints;
            head_copy = head_copy->next;
            for (int i = 0; i < nr_teams && head_copy != NULL; i++)
            {
                if (head_copy->teamPoints < mini)
                    mini = head_copy->teamPoints;
                head_copy = head_copy->next;
            }
            delete (&head, mini);
            nr_teams--;
            // free(head_copy);
        }
        // afiseaza numele echipelor dupa eliminare, in fisierul r.out
        TEAM *listHead = (TEAM *)malloc(sizeof(TEAM));
        listHead = head;
        for (int i = 0; i < nr_teams && listHead != NULL; i++)
        {
            fprintf(r, "%s\n", listHead->teamName);
            listHead = listHead->next;
        }
        free(listHead);
    }

    if (tasks[2] == 1)
    {
        Queue *q = createQueue();
        TEAM *head_queue = (TEAM *)malloc(sizeof(TEAM));
        head_queue = head;
        for (int i = 0; i < nr_teams && head_queue != NULL; i++)
        {
            enQueue1(q, head_queue);
            head_queue = head_queue->next;
        }
        Stack* top_losers = (Stack*)malloc(sizeof(Stack));
        Stack* top_winners = (Stack*)malloc(sizeof(Stack));
        int nr_rounds = 1;
        int nr_char = 33;
        while (nr_rounds <= rounds)
        {
            fprintf(r, "--- ROUND NO:%d", nr_rounds);
            while(q->front != NULL && q->front->next != NULL && (q->front->next)->next != NULL)
            {
                //afiseaza meciurile 
                fprintf(r, "%s", q->front->qName);
                for(int i=0; i<(nr_char - strlen(q->front->qName)); i++)
                    fprintf(r, "%c", ' ');
                fprintf(r, "%c", '-');
                for(int i=0; i<(nr_char - strlen((q->front->next)->qName)); i++)
                    fprintf(r, "%c", ' ');
                fprintf(r, "%s\n", (q->front->next)->qName);
            //compara echipele 2 cate 2 si creeaza stivele de castigatori/invinsi
                if((q->front->qPoints) < ((q->front->next)->qPoints))
                {
                    push(&top_losers, q);
                    q->front = q->front->next;
                    q->front->qPoints++;
                    push(&top_winners, q);
                }
                else 
                {
                    q->front->qPoints++;
                    push(&top_winners, q);
                    q->front = q->front->next;
                    push(&top_losers, q);                                   
                }
                q->front = q->front->next;
            }
            //goleste coada
            //deleteQueue(q);
            //afiseaza stiva de castigatori
            fprintf(r, "\n");
            int nr_spaces = 34;
            fprintf(r, "WINNERS OF ROUND NO:%d", nr_rounds);
            while(top_winners != NULL)
            {
                fprintf(r, "%s", top_winners->sName);
                for(int i=0; i<(nr_spaces - strlen(top_winners->sName)); i++)
                    fprintf(r, "%c", ' ');
                fprintf(r, "%s", "-  ");
                fprintf(r, "%f\n", top_winners->sPoints);
                enQueue2(q,top_winners);
                top_winners = top_winners->next;
            }
            //deleteStack(&top_winners);
            nr_rounds++;
        }
    }

    // inchide fisierele
    fclose(d);
    fclose(r);
    fclose(c);

    return 0;
}
