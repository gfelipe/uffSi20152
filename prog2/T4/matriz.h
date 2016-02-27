#ifndef MATRIZ_H
#define MATRIZ_H

#include<stdio.h>
#include<stdlib.h>

typedef struct matriz {
	int n, m;
	int **mat;
} Matriz;

// verifica se a memória para uma matriz está alocada
int existeMatriz(Matriz M);

// aloca memória para uma matriz de tamanho n por m e preenche ela com zeros
Matriz criaMatriz(int n, int m);

// desaloca a matriz M da memória
void destroiMatriz(Matriz *M);

// leitura da matriz M
void leituraMatriz(Matriz *M);

// imprime a matriz M
void imprimeMatriz(Matriz M);

// soma duas matrizes e retorna o resultado em uma terceira matriz
Matriz somaMatriz(Matriz A, Matriz B);

// realiza a transporta da matriz M, modificando ela mesma
void transporMatriz(Matriz *M);

#endif
