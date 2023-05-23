#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structuri de date
//jucatori
struct Player
{
    char *firstName;
    char *secondName;
    int points;
};

typedef struct Player PLAY;

//echipe
struct Team
{
    int nr_players;
    char* teamName;
    PLAY *p;
    struct Team *next;
    float teamPoints;
};

typedef struct Team TEAM;

//stiva castigatori/pierzatori
struct S
{
    char* sName;
    float sPoints;
    struct S* next;
};

typedef struct S Stack;

//elemente coada
struct Elem
{
	char* qName;
	float qPoints; 
	struct Elem* next;
};

typedef struct Elem Node;

//coada
struct Q
{
	Node *front, *rear;
};

typedef struct Q Queue;	

//BST struct
struct BSTnode{
    char* teamName;
    float teamPoints;
    struct BSTnode *left, *right;
};

typedef struct BSTnode BST;

//AVL struct
struct AVLnode{
    char* teamName;
    int height;
    struct AVLnode *left, *right;
};

typedef struct AVLnode AVL;

//functii
void openFile(FILE *fisier);
//task1
void createLIST(TEAM **head, FILE *input);
//task2
void delete(TEAM **head, float val);
//task3
//functii coada
Queue* createQueue();
void enQueue1(Queue *q, TEAM *team);
void enQueue2(Queue *q, Stack *team);
int isEmpty_q(Queue *q);
void deleteQueue(Queue *q);
//functii stiva
void push(Stack**top, Queue* head);
void pop(Stack**top) ;
int isEmpty_s(Stack*top);
void deleteStack(Stack**top);
void delete_lista(TEAM **head);
//task4
//functii arbore
BST* createNode(char *name, float points);
BST* insert(BST* node,  char *name, float points);
void freeTree(BST* root);
void displayDRS(BST* root, FILE* input);
void printLevel2(AVL* root, FILE* input) ;
AVL* newNode(AVL* node, char* nume);
void create_tree(AVL**tree, BST* binTree, int height);
AVL* createNodeT(char *name, int height);
