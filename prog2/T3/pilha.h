#ifndef PILHA_H
#define PILHA_H

typedef struct pilha {
	int elementos[100];
	int tamanho;
} Pilha;

Pilha criaPilha();
int inserePilha(Pilha * p, int * elemento, int quantidade);
int removePilha(Pilha * p, int quantidade);
void imprimePilha(Pilha p);

#endif