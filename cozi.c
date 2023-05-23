#include "header.h"

// creare coada
Queue *createQueue()
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL)
		return NULL;
	q->front = NULL;
	q->rear = NULL;
	return q;
}

// adaugare element in coada
void enQueue1(Queue *q, TEAM *team)
{	
	// adauga in coada numele si punctajele echipelor
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->qName = (char*)malloc((strlen(team->teamName) + 1) * sizeof(char));
	strcpy(newnode->qName, team->teamName);
	//newnode->qName[strlen(newnode->qName) - 1] = '\0';
	newnode->qPoints = team->teamPoints;
	// nodurile noi se adauga la finalul cozii
	if (q->rear == NULL)
		q->rear = newnode;
	// daca nu exista nici un nod in coada
	else
	{
		(q->rear)->next = newnode;
		(q->rear) = newnode;
	}
	// daca exista un singur element in coada
	if (q->front == NULL)
		q->front = q->rear;
}

void enQueue2(Queue *q, Stack *team)
{
	// adauga in coada numele si punctajele echipelor
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->qName = (char*)malloc((strlen(team->sName) + 1) * sizeof(char));
	newnode->next = NULL;
	strcpy(newnode->qName, team->sName);
	//newnode->qName[strlen(newnode->qName) - 1] = '\0';
	newnode->qPoints = team->sPoints;
	// nodurile noi se adauga la finalul cozii
	if (q->rear == NULL)
	{
		q->rear = newnode;
	}
	// daca nu exista nici un nod in coada
	else
	{
		(q->rear)->next = newnode;
		(q->rear) = newnode;
	}
	// daca exista un singur element in coada
	if (q->front == NULL)
		q->front = q->rear;	
}

// stergere coada
int isEmpty_q(Queue *q)
{
	return (q->front == NULL);
}

void deleteQueue(Queue *q)
{
	Node *aux;
	while (!isEmpty_q(q))
	{
		aux = q->front;
		q->front = q->front->next;
		free(aux->qName);
		free(aux);
	}
	free(q);
}