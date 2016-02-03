#include <stdio.h>
#include "fila.h"

Fila criaFila() {
	Fila fila;
	
	fila.final = -1;
	fila.inicio = -1;
	fila.tamanho = 0;

	return fila;
}

int insereFila(Fila f, int * elemento, int quantidade){
	
	int i;
	
	if(f.final + quantidade > 100) {
		return 1;
	}

	if(f.inicio == -1) {
		f.final = 0;
		f.inicio = 0;
	}

	for(i = 0; i < quantidade ; i++) {
		f.elementos[++f.final] = elemento[i];
		f.tamanho++;
	}
	
	return 0;
}

int removeFila(Fila f, int quantidade) {
	
	int i;

	if(f.tamanho == 0 || f.tamanho - quantidade < 0) {
		return 1;
	}

	for(i = f.inicio; quantidade ; i++, quantidade--) {
		f.elementos[i] = 0;
		f.tamanho--;
		f.inicio++;
	}

	return 0;

}

void imprimeFila(Fila f){

	int i;

	for(i=f.inicio; i <= f.final; i++) {
		printf("%d ", f.elementos[i]);
	}

	printf("\n");

}