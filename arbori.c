#include "header.h"

//functie de creare a unui nod BST
BST* createNode(char *name, float points)
{
    BST* node = (BST*)malloc(sizeof(BST));
    node->teamName = malloc((strlen(name) + 1)*sizeof(char));
    strcpy(node->teamName, name);
    node->teamPoints = points;
    node->left = node->right = NULL;
    return node;
}

//functie de inserare in BST
BST* insert(BST* node,  char *name, float points)
{
    //daca (sub)arborele este gol, creeaza nod
    if(node == NULL) return createNode(name, points);
    //altfel,
    //sortare echipe descrescator dupa punctaj si nume
    //coboara la stanga daca scorul echipei < scorul nodului
    if(points < node->teamPoints)
        node->left = insert(node->left, name, points);
    //coboara la dreapta daca scorul echipei > scorul nodului
    else 
        if(points > node->teamPoints)
            node->right = insert(node->right, name, points);
        else 
        {
            if(strcmp(name, node->teamName) < 0)
                node->left = insert(node->left, name, points);
            else 
                node->right = insert(node->right, name, points);
        }
    return node;    
}

// Functie pentru a elibera memoria ocupata de arbore
void freeTree(BST* root) 
{
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

//functie afisare arbore binar de cautare (DRS)
void displayDRS(BST* root, FILE* input) {
    if (root == NULL) {
        return;
    }
    // Parcurgere în ordine descrescătoare și afișare noduri
    displayDRS(root->right, input);
    int nr_spaces = 34;
    fprintf(input, "%s", root->teamName);
    for (int i = 0; i < (nr_spaces - strlen(root->teamName)); i++)
        fprintf(input, "%c", ' ');
    fprintf(input, "%s", "-  ");
    fprintf(input, "%.2f\n", root->teamPoints);
    displayDRS(root->left, input);
}

AVL* createNodeT(char *name, int height)
{
    AVL* node = (AVL*)malloc(sizeof(AVL));
    node->teamName = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(node->teamName, name);
    node->left = NULL;
    node->right = NULL;
    node->height = height; // Noul nod este adaugat la nivelul curent
    return node;
}

//creare nod intr-un arbore de tip AVL
void create_tree(AVL**tree, BST* binTree, int height) 
{
    if(binTree == NULL)
        return ;
    *tree = createNodeT(binTree->teamName, height);
    
    create_tree(&(*tree)->right, binTree->right, height + 1);
    create_tree(&(*tree)->left, binTree->left, height + 1);
}

void printLevel2(AVL* root, FILE* input) 
{
    if (root == NULL) {
        return;
    }
    if (root->height == 2) {
        // Afiseaza valorile de pe nivelul 2
        fprintf(input, "%s ", root->teamName);
        fprintf(input, "%d\n", root->height);
        return;
    }
    
    // Parcurge recursiv subarborii pentru nivelul 2
    printLevel2(root->left, input);
    printLevel2(root->right, input);
}
