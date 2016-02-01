#include "pilha.h"

Pilha criaPilha() {
	Pilha pilha;
	
	pilha.tamanho = 0;

	return pilha;
}

int inserePilha(Pilha p, int * elemento, int quantidade) {
	int i = 0;
	
	if(p.tamanho + quantidade > 100) {
		return 1;
	}

	for(i = 0; i < quantidade ; i++) {
		p.elementos[p.tamanho++] = elemento[i];
	}

}

int removePilha(Pilha p, int quantidade) {
	if(p.tamanho == 0 || p.tamanho - quantidade < 0) {
		return 1;
	}

	for(i = 0; i < quantidade ; i++) {
		p.elementos[--p.tamanho] = NULL;
	}
}
