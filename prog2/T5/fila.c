#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int existsList(Node * list) {
    return list != NULL;
}

Node * createList() {
    Node * list = NULL;
    return list;
}

Node * createNode(char * name, int time) {

    Node * node = (Node*) malloc(sizeof(Node));
    node->name = name;
    node->time = time;
    node->next = NULL;

    return node;

}

void insertNode(Node ** list, char * name, int time){

    Node * node = createNode(name, time);

    if(*list == NULL){
        *list = node;
    } else {

        Node * tmp = *list;

        while(tmp != NULL) {
            if(tmp->next == NULL) {
                tmp->next = node;
                break;
            }
            tmp = tmp->next;
        }

    }

}

void removeNode(Node ** list){

    if(!existsList(*list)) {
        fprintf(stderr, "Lista já se encontra vazia.");
    } else if ((*list)->next == NULL) {
        free((*list)->name);
        free(*list);
        *list = NULL;
    } else {
        Node * tmp = *list;
        *list = (*list)->next;
        free(tmp->name);
        free(tmp);
    }

}

int getListSize(Node * list) {

    int size = 0;

    while(list != NULL) {
        list = list->next;
        size++;
    }

    return size;

}

void printList(Node * list){

    Node * tmp = list;

    for(int i =0; tmp != NULL; i++){
        printf("Aviao: %s Tempo: %d Posiçao: %d\n", tmp->name, tmp->time, i+1);
        tmp = tmp->next;
    }

}

void destroyList(Node ** list){

    while(*list!=NULL){
        Node * tmp = *list;
        *list = (*list)->next;
        free(tmp->name);
        free(tmp);
    }

}