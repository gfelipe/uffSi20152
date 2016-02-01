#include "fila.h"

Fila criaFila() {
	Fila fila;
	
	fila.fim = -1;
	fila.inicio = -1;
	fila.tamanho = 0;

	return fila;
}

void insereFila(Fila f, int * elemento, int quantidade);
int removeFila(Fila f, int quantidade);
