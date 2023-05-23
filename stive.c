#include "header.h"

//adaugare element in stiva
void push(Stack**top, Queue* team)
{
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->sName = (char*)malloc((strlen(team->front->qName) + 1) * sizeof(char));
	strcpy(newnode->sName , team->front->qName);
	newnode->sPoints = team->front->qPoints;
	newnode->next = *top;
	*top = newnode;
}


//stergere element din stiva
void pop(Stack**top) 
{	
	*top = (*top)->next;      		
	//free(temp);
}


//stergere stiva
int isEmpty_s(Stack*top)
{
	return top==NULL;
}
	
void deleteStack(Stack**top)
{
	Stack  *temp;
	while (!isEmpty_s(*top)) {
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
	free(top);
}
