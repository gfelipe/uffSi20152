#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

typedef struct entrada {
	int elementos[100];
	int quantidade;
	char comando;
	char estrutura;
} Entrada;

void processaEntrada(Fila fila, Pilha pilha);
int inserir(Fila fila, Pilha pilha, Entrada entrada);
int remover(Fila fila, Pilha pilha, Entrada entrada);
void imprimir(Fila fila, Pilha pilha, Entrada entrada);
bool terminarExecucao(Entrada entrada);
void tratarRetorno(int retorno, char * acao);

int main() {

	Fila fila = criaFila();
	Pilha pilha = criaPilha();

	processaEntrada(fila, pilha);

	return 0;

}

void processaEntrada(Fila fila, Pilha pilha) {

	int i = 0;
	int retorno;
	char * buffer = (char*)malloc(203*sizeof(char));;
	char * stringBuffer;
	Entrada entrada;


	while( !terminarExecucao(entrada) ) {
		
		fgets(buffer, "%s", stdin);

		entrada.estrutura = buffer[0];
		entrada.comando = buffer[2];
		entrada.quantidade = buffer[4];

		if(entrada.quantidade) {

//			strncpy(buffer, buffer+5, strlen(buffer)-5);

			stringBuffer = strtok(buffer, " PFir");

			while(stringBuffer != NULL){
				entrada.elementos[i] = strtol(stringBuffer, NULL, 10);
				stringBuffer = strtok(NULL, " PFir");
				i++;
			}

		}

		printf("Teste: %c\n%c\n%d\n%s" entrada.estrutura, entrada.comando, entrada.quantidade, entrada.elementos);

		switch (entrada.comando) {
			case 'i':
				retorno = inserir(fila, pilha, entrada);
				tratarRetorno(retorno, "inserir");
			case 'r':
				retorno = remover(fila, pilha, entrada);
				tratarRetorno(retorno, "remover");
			case 'p':
				imprimir(fila, pilha, entrada);
				break;
		}

	}

}

int inserir(Fila fila, Pilha pilha, Entrada entrada) {

	switch(entrada.estrutura) {
		case 'P':
			return inserePilha(pilha, entrada.elementos, entrada.quantidade);
		case 'F':
			return insereFila(fila, entrada.elementos, entrada.quantidade);
		default:
			return 1;	
	}
	
}

int remover(Fila fila, Pilha pilha, Entrada entrada) {


	switch(entrada.estrutura) {
		case 'P':
			return removePilha(pilha, entrada.quantidade);
		case 'F':
			return removeFila(fila, entrada.quantidade);
		default:
			return 1;	
	}

}

void imprimir(Fila fila, Pilha pilha, Entrada entrada) {

	switch(entrada.estrutura) {
		case 'P':
			return imprimePilha(pilha);
		case 'F':
			return imprimeFila(fila);
	}

}

bool terminarExecucao(Entrada entrada) {
	return entrada.estrutura == 'S';
}

void tratarRetorno(int retorno, char * acao) {
	if (retorno == 1){
		fprintf(stderr, "Nao foi possivel %s os elementos\n", acao);
	}
}