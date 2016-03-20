#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "fila.h"

#define DEPARTING_NAME "decolando"
#define LANDING_NAME "pousando"

bool isAirstripFree(int firstAirstrip);
int readInput(Node ** flights, char * operationName);
void processPlanes(Node * departingFlights, Node * landingFlights);
void printAction(char * name, char * actionName, int airstripNumber);
Node *** getPrioritizedList(Node ** departingFlights, Node ** landingFlights, char ** name);

int main() {

    Node * departingFlights = createList();
    Node * landingFlights = createList();

    readInput(&departingFlights, "decolagem");
    readInput(&landingFlights, "pouso");

    //TODO remover antes da entrega
    printList(departingFlights);
    printList(landingFlights);

    processPlanes(departingFlights, landingFlights);

//    destroyList(&departingFlights);
//    destroyList(&landingFlights);

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
            removeNode(&departingFlights);

        }

        if(isAirstripFree(secondAirstrip) && landingFlights != NULL) {

            secondAirstrip = landingFlights->time;
            printAction(landingFlights->name, LANDING_NAME, 2);
            removeNode(&landingFlights);

        }

        if(isAirstripFree(thirdAirstrip) && (departingFlights != NULL || landingFlights != NULL)) {

            char * name;
            Node *** priorityList = getPrioritizedList(&departingFlights, landingFlights, &name);

            thirdAirstrip = (**priorityList)->time;
            printAction((**priorityList)->name, name, 3);
            removeNode(*priorityList);

        }

        if (firstAirstrip > 0) firstAirstrip--;
        if (secondAirstrip > 0) secondAirstrip--;
        if (thirdAirstrip > 0) thirdAirstrip--;

    }
}

Node *** getPrioritizedList(Node ** departingFlights, Node ** landingFlights, char ** name) {

    int landingPlanes = getListSize(*landingFlights);
    int departingPlanes = getListSize(*departingFlights);

    if(landingPlanes > departingPlanes) {
        *name = LANDING_NAME;
        return landingFlights;
    } else if (landingPlanes < departingPlanes) {
        *name = DEPARTING_NAME;
        return departingFlights;
    } else {
        *name = LANDING_NAME;
        return landingFlights;
    }

}

int readInput(Node ** flights, char * operationName) {

    char *planesInput = (char*) malloc(100 * sizeof(char));

    fprintf(stdout, "Digite o numero de avioes para %s\n", operationName);
    int planes = strtol(fgets(planesInput, INT_MAX, stdin), NULL, 10);

    if(planes) fprintf(stdout, "Digite os avioes para %s (nome tempo)\n", operationName);

    for(; planes; planes--) {

        char * buffer = (char*) malloc(100*sizeof(char));

        fgets(buffer, INT_MAX, stdin);

        char * name = strtok(buffer, " ");
        int time = strtol(strtok(NULL, " "), NULL, 10);

        insertNode(flights, name, time);

    }

    free(planesInput);

    return planes;

}

void printAction(char * name, char * actionName, int airstripNumber) {
    fprintf(stdout, "O aviao %s esta %s na pista %d\n", name, actionName, airstripNumber);
}

bool isAirstripFree(int firstAirstrip) { return firstAirstrip == 0; }
