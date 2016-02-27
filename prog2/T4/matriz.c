#include <string.h>
#include "matriz.h"
#include <limits.h>

typedef char * String;

// verifica se a memória para uma matriz está alocada
int existeMatriz(Matriz M) {
    return M.mat != NULL;
}

// aloca memória para uma matriz de tamanho n por m e preenche ela com zeros
Matriz criaMatriz(int n, int m) {

    Matriz matriz;

    matriz.m = m;
    matriz.n = n;
    matriz.mat = (int**) malloc(sizeof(int)*n);

    for (int i = 0; i < m; ++i) {
        matriz.mat[i] = (int*) malloc(sizeof(int)*m);
    }

    return matriz;

}

// desaloca a matriz M da memória
void destroiMatriz(Matriz *M) {

    if(!existeMatriz(*M)) {
        return;
    }

    for (int i = 0; i < (*M).m; ++i) {
        free((*M).mat[i]);
    }

    free((*M).mat);

}

// leitura da matriz M
void leituraMatriz(Matriz *M){

    String linhaMatriz = (String) malloc(sizeof(int)*(*M).m*2);
    String buffer;
    int i, j;

    for (i = 0; i < (*M).n; ++i) {
        fgets(linhaMatriz, INT_MAX, stdin);

        for (j = 0, buffer = strtok(linhaMatriz, " "); buffer != NULL; buffer = strtok(NULL, " "), j++) {
            (*M).mat[i][j] = strtol(buffer, NULL, 10);
        }
    }

}

// imprime a matriz M
void imprimeMatriz(Matriz M) {

    for (int i = 0; i < M.n; ++i) {
        for (int j = 0; j < M.m; ++j) {
            printf("%d ", M.mat[i][j]);
        }
        printf("\n");
    }

}

// soma duas matrizes e retorna o resultado em uma terceira matriz
Matriz somaMatriz(Matriz A, Matriz B) {

    Matriz matriz = criaMatriz(A.n, A.m);

    for (int i = 0; i < A.n; ++i) {
        for (int j = 0; j < A.m; ++j) {
            matriz.mat[i][j] = A.mat[i][j] + B.mat[i][j];
        }
    }

    return matriz;

}

// realiza a transporta da matriz M, modificando ela mesma
void transporMatriz(Matriz *M) {

    Matriz matrizAux = criaMatriz((*M).n, (*M).m);

    for (int i = 0; i < (*M).n; ++i) {
        for (int j = 0; j < (*M).n; ++j) {
            matrizAux.mat[i][j] = (*M).mat[j][i];
        }
    }

    destroiMatriz(M);
    (*M).mat = matrizAux.mat;

}