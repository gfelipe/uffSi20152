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

void processaEntrada(Fila * fila, Pilha * pilha);
int inserir(Fila * fila, Pilha * pilha, Entrada entrada);
int remover(Fila * fila, Pilha * pilha, Entrada entrada);
void imprimir(Fila fila, Pilha pilha, Entrada entrada);
bool terminarExecucao(Entrada entrada);
void tratarRetorno(int retorno, char * acao);

int main() {

	Fila fila = criaFila();
	Pilha pilha = criaPilha();

	processaEntrada(&fila, &pilha);

	return 0;

}

void processaEntrada(Fila * fila, Pilha * pilha) {

	char * buffer = (char*)malloc(100*sizeof(int) + 106*sizeof(char));
	Entrada entrada;


	while( !terminarExecucao(entrada) ) {
		
		fgets(buffer, sizeof(buffer), stdin);

		entrada.estrutura = buffer[0];
		entrada.comando = buffer[2];
		entrada.quantidade = strtol(&buffer[4], NULL, 10);

		if(entrada.quantidade) {

            int i;
            char * stringBuffer = strtok(buffer, " PFirp"); // Ignorando o primeiro número encontrado, pois é a quantidade.

            // Separando a string de entrada em tokens, que serão os números para inserir. Usando como delimitadores os espaços, e as letras de comando/estrutura.
			for(stringBuffer = strtok(NULL, " PFirp"), i = 0; stringBuffer != NULL; stringBuffer = strtok(NULL, " PFirp"), i++){
                entrada.elementos[i] = strtol(stringBuffer, NULL, 10);
			}

		}

        switch (entrada.comando) {
			case 'i':
				tratarRetorno(inserir(fila, pilha, entrada), "inserir");
                break;
			case 'r':
				tratarRetorno(remover(fila, pilha, entrada), "remover");
                break;
			case 'p':
				imprimir(*fila, *pilha, entrada);
				break;
            default:
                fprintf(stderr, "Opção não encontrada.");
                break;
		}

	}

}

int inserir(Fila * fila, Pilha * pilha, Entrada entrada) {

	switch(entrada.estrutura) {
		case 'P':
			return inserePilha(pilha, entrada.elementos, entrada.quantidade);
		case 'F':
			return insereFila(fila, entrada.elementos, entrada.quantidade);
		default:
			return 1;
	}
	
}

int remover(Fila * fila, Pilha * pilha, Entrada entrada) {


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

void tratarRetorno(int erro, char * acao) {
	if (erro){
		fprintf(stderr, "Nao foi possivel %s os elementos\n", acao);
	}
}

bool terminarExecucao(Entrada entrada) {
    return entrada.estrutura == 'S';
}