#ifndef FILA_H
#define FILA_H

typedef struct node {
    char * name;
    int time;
    struct node * next;
} Node;

int existsList(Node * list);
Node * createList();
Node * createNode(char * name, int time);
void insertNode(Node ** list, Node * node);
void removeNode(Node ** list);
int getListSize(Node * list);
void printList(Node * list);

#endif
