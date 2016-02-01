#include "fila.h"
#include "pilha.h"

typedef entrada {
	int elementos[100];
	int quantidade;
	char comando;
	char estrutura;
} Entrada;

void processaEntrada(Fila fila, Pilha pilha);
bool terminarExecucao(Entrada entrada);

int main() {

	Fila fila = criaFila();
	Pilha pilha = criaPilha();

	processaEntrada(fila, pilha);

}

void processaEntrada(Fila fila, Pilha pilha) {

	Entrada entrada;

	char buffer[204];

	while( !terminarExecucao(entrada) ) {
		
		fgets(buffer, "%s", stdin);

		entrada.estrutura = buffer[0];
		entrada.comando = buffer[2];

		switch(entrada.estrutura) {
			case 'P':
				acoesDePilha(pilha);
				break;
			case 'F':
				acoesDeFila(fila);
				break;
		}

	}

}

void acoesDePilha(Pilha pilha) {
	switch (entrada.comando) {
		case 'i':
			inserePilha(pilha, entrada.elementos, entrada.quantidade);
			break;
		case 'r':
			removePilha(pilha, entrada.quantidade);
			break;
	}
}

void acoesDeFila(Fila fila) {
	switch (entrada.comando) {
		case 'i':
			insereFila(fila, entrada.elementos, entrada.quantidade);
			break;
		case 'r':
			removeFila(fila, entrada.quantidade);
			break;
	}
}

bool terminarExecucao(Entrada entrada) {
	return entrada.comando == S;
}