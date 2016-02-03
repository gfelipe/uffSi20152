#include <stdio.h>
#include "pilha.h"

Pilha criaPilha() {
	Pilha pilha;
	pilha.tamanho = 0;

	return pilha;
}

int inserePilha(Pilha p, int * elemento, int quantidade) {
	
	int i;
	
	if(p.tamanho + quantidade > 100) {
		return 1;
	}

	for(i = 0; i < quantidade ; i++) {
		p.elementos[p.tamanho++] = elemento[i];
	}
	
	return 0;

}

int removePilha(Pilha p, int quantidade) {
	
	int i;

	if(p.tamanho == 0 || p.tamanho - quantidade < 0) {
		return 1;
	}

	for(i = 0; i < quantidade ; i++) {
		p.elementos[--p.tamanho] = 0;
	}

	return 0;
}

void imprimePilha(Pilha p){

	int i;

	for(i=0; i < p.tamanho; i++) {
		printf("%d ", p.elementos[i]);
	}

	printf("\n");

}