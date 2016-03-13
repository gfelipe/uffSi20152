#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "fila.h"

#define DEPARTING_NAME "decolando"
#define LANDING_NAME "pousando"

/*
2
1
BBB1234 1
2
CCC1234 1
DDD1234 1
*/

bool isAirstripFree(int firstAirstrip);
int readInput(Node *flights, char * operationName);
void processPlanes(Node * departingFlights, Node * landingFlights);
void printAction(char * name, char * actionName, int airstripNumber);
Node * getPrioritizedList(Node * departingFlights, Node * landingFlights, char * name);

int main() {

    Node * departingFlights = createList();
    Node * landingFlights = createList();

    int departingPlanes = readInput(departingFlights, "decolagem");
    int landingPlanes = readInput(landingFlights, "pouso");

    //TODO remover antes da entrega
    printList(departingFlights); printList(landingFlights);

    processPlanes(departingFlights, landingFlights);

    return 0;

}

void processPlanes(Node * departingFlights, Node * landingFlights) {

    int firstAirstrip = 0;
    int secondAirstrip = 0;
    int thirdAirstrip = 0;

    while (departingFlights != NULL || landingFlights != NULL) {

        if(isAirstripFree(firstAirstrip) && departingFlights != NULL) {

            firstAirstrip = departingFlights->time;
            printAction(departingFlights->name, DEPARTING_NAME, 1);
            removeNode(departingFlights);

        } else if(isAirstripFree(secondAirstrip) && landingFlights != NULL) {

            secondAirstrip = landingFlights->time;
            printAction(departingFlights->name, LANDING_NAME, 2);
            removeNode(landingFlights);

        } else if(isAirstripFree(thirdAirstrip) && (departingFlights != NULL || landingFlights != NULL)) {

            char * name;
            Node * priorityList = getPrioritizedList(departingFlights, landingFlights, name);

            thirdAirstrip = priorityList->time;
            printAction(departingFlights->name, name, 3);
            removeNode(priorityList);

        }

        firstAirstrip--;
        secondAirstrip--;
        thirdAirstrip--;

    }
}

bool isAirstripFree(int firstAirstrip) { return firstAirstrip == 0; }

Node * getPrioritizedList(Node * departingFlights, Node * landingFlights, char * name) {

    int landingPlanes = getListSize(landingFlights);
    int departingPlanes = getListSize(departingFlights);
    Node * biggerList;

    if(landingPlanes > departingPlanes) {
        name = LANDING_NAME;
        biggerList = landingFlights;
    } else if (landingPlanes < departingPlanes) {
        name = DEPARTING_NAME;
        biggerList = departingFlights;
    } else {
        name = LANDING_NAME;
        biggerList = landingFlights;
    }

    return biggerList;
}

void printAction(char * name, char * actionName, int airstripNumber) {
    fprintf(stdout, "O aviao %s esta %s na pista %d\n", name, actionName, airstripNumber);
}

int readInput(Node * flights, char * operationName) {

    char * buffer = (char*) malloc(INT_MAX * sizeof(char));

    fprintf(stdout, "Digite o numero de avioes para %s\n", operationName);
    int planes = strtol(fgets(buffer, INT_MAX, stdin), NULL, 10);

    if(planes) fprintf(stdout, "Digite os avioes para %s (nome tempo)\n", operationName);

    for(; planes; planes--) {

        fgets(buffer, INT_MAX, stdin);

        char * name = strtok(buffer, " ");
        int time = strtol(strtok(NULL, " "), NULL, 10);

        insertNode(flights, createNode(name, time));
    }

    return planes;

}