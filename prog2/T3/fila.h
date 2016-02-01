#ifndef FILA_H
#define FILA_H

typedef struct fila {
	int elementos[100];
	int inicio;
	int final;
	int tamanho;
} Fila;

Fila criaFila();
void insereFila(Fila f, int * elemento, int quantidade);
int removeFila(Fila f, int quantidade);

#endif