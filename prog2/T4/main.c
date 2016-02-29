#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void processaEntrada();
void printError(char * nome);
bool terminarExecucao(char entrada);

void readMatrix(Matriz * matriz, char * nome);
void printMatrix(Matriz matriz, char * nome);
void transposeMatrix(Matriz * matriz, char * nome);
void sumMatrix(Matriz matriz1, Matriz matriz2);

int main() {

    processaEntrada();

    return 0;

}

void processaEntrada() {

    size_t tamanhoEntrada = 100*sizeof(int) + 106*sizeof(char);
    char * buffer = (char*)malloc(tamanhoEntrada);
    char entrada;

    Matriz A;
    A.mat = NULL;

    Matriz B;
    B.mat = NULL;

    int m, n;

    while( !terminarExecucao(entrada) ) {

        fgets(buffer, tamanhoEntrada, stdin);

        entrada = buffer[0];

        switch (entrada) {
            case 'S':
                if (existeMatriz(A)) destroiMatriz(&A);
                if (existeMatriz(B)) destroiMatriz(&B);
                break;
            case 'C':
                n = strtol(&buffer[4], NULL, 10);
                m = strtol(&buffer[6], NULL, 10);
                if (buffer[2] == 'A') {
                    A = criaMatriz(n, m);
                } else {
                    B = criaMatriz(n, m);
                }
                break;
            case 'L':
                readMatrix(buffer[2] == 'A' ? &A : &B, &buffer[2]);
                break;
            case 'I':
                printMatrix(buffer[2] == 'A' ? A : B, &buffer[2]);
                break;
            case 'T':
                transposeMatrix(buffer[2] == 'A' ? &A : &B, &buffer[2]);
                break;
            case 'A':
                sumMatrix(A, B);
                break;

        }

    }

}

void readMatrix(Matriz * matriz, char * nome) {
    if (existeMatriz(*matriz)) {
        leituraMatriz(matriz);
    } else {
        printError(nome);
    }
}

void printMatrix(Matriz matriz, char * nome) {
    if (existeMatriz(matriz)) {
        imprimeMatriz(matriz);
    } else {
        printError(nome);
    }
}

void transposeMatrix(Matriz * matriz, char * nome) {
    if (existeMatriz(*matriz)) {
        transporMatriz(matriz);
    } else {
        printError(nome);
    }
}

void sumMatrix(Matriz matriz1, Matriz matriz2) {
    if(matriz1.mat == NULL) {
        printError("A");
    } else if (matriz2.mat == NULL) {
        printError("B");
    } else if (matriz1.n != matriz2.n || matriz2.m != matriz2.m) {
        fprintf(stderr, "Matrizes devem ter o mesmo tamanho para soma.\n");
    } else {
        Matriz matrizAux = somaMatriz(matriz1, matriz2);
        imprimeMatriz(matrizAux);
        destroiMatriz(&matrizAux);
    }
}

void printError(char * nome) {
    fprintf(stderr, "A matriz %c nao foi criada!\n", *nome);
}

bool terminarExecucao(char entrada) {
    return entrada == 'S';
}