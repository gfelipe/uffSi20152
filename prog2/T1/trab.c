#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE_NAME_01 "file01.in"
#define OUTPUT_FILE_NAME_01 "file01.out"
#define INPUT_FILE_NAME_02 "file02.in"
#define OUTPUT_FILE_NAME_02 "file02.out"
#define INPUT_FILE_NAME_03 "file03.in"
#define OUTPUT_FILE_NAME_03 "file03.out"

#define READING_FILE_OPTIONS "rb"
#define WRITING_FILE_OPTIONS "wb"

FILE * getFile(char * fileName, char * fileOptions);

unsigned char generateNextCharacter(unsigned char character, int offset);

unsigned char generatePreviousCharacter(unsigned char character, int offset);

int encryptFile(char * inputFileName, char * outputFileName, int key);

int decryptFile(char * inputFileName, char * outputFileName, int key);

int executeFileActions(FILE * inputFile, FILE * outputFile, int key,
                       unsigned char (*generateCharacter)(unsigned char, int));

int init(char operation, int key, char * inputFileName, char * outputFileName);

void testExample01() {
    if (init('E', 3, INPUT_FILE_NAME_01, OUTPUT_FILE_NAME_01) != 0) {
        fprintf(stderr, "Houveram erros durante a execução do exemplo 01.\n");
    }
}

void testExample02() {
	if (init('D', 3, INPUT_FILE_NAME_02, OUTPUT_FILE_NAME_02) != 0) {
        fprintf(stderr, "Houveram erros durante a execução do exemplo 02.\n");
    }
}

void testExample03() {
	if (init('E', 10, INPUT_FILE_NAME_03, OUTPUT_FILE_NAME_03) != 0) {
        fprintf(stderr, "Houveram erros durante a execução do exemplo 03.\n");
    }
}

int main () {

    testExample01();
    testExample02();
    testExample03();

	return 0;
}

/**
 * Entrada do programa
 */
int init(char operation, int key, char * inputFileName, char * outputFileName) {

    int success;

    switch (operation) {
        case 'E':
            success = encryptFile(inputFileName, outputFileName, key);
            break;
        case 'D':
            success = decryptFile(inputFileName, outputFileName, key);
            break;
        default:
            fprintf(stderr, "Operação não suportada.\n");
            return -1;
    }

    return success;

}

/**
 * Função que chama a encriptação do arquivo
 */
int encryptFile(char * inputFileName, char * outputFileName, int key) {

    int success;

    FILE * inputFile = getFile(inputFileName, READING_FILE_OPTIONS);
    FILE * outputFile = getFile(outputFileName, WRITING_FILE_OPTIONS);

    success = executeFileActions(inputFile, outputFile, key, generateNextCharacter);

    fclose(inputFile);
    fclose(outputFile);

    return success;

}

/**
 * Função que chama a decriptação do arquivo
 */
int decryptFile(char * inputFileName, char * outputFileName, int key) {

    int success;

    FILE * inputFile = getFile(inputFileName, READING_FILE_OPTIONS);
    FILE * outputFile = getFile(outputFileName, WRITING_FILE_OPTIONS);

    success = executeFileActions(inputFile, outputFile, key, generatePreviousCharacter);

    fclose(inputFile);
    fclose(outputFile);

    return success;

}

/**
 * Função que realiza a encriptação/decriptação do arquivo de acordo com os parâmetros passados
 */
int executeFileActions(FILE * inputFile, FILE * outputFile, int key,
                       unsigned char (*generateCharacter)(unsigned char, int)) {

    int sizeOfReadCharacter = 0;
    unsigned char buffer;

    while(1) {

        sizeOfReadCharacter = fread(&buffer, 1, 1, inputFile);

        if (!sizeOfReadCharacter) {
            if (feof(inputFile)) {
                break;
            } else {
                fprintf(stderr, "Erro ao ler do arquivo.\n");
                return -1;
            }
        }

        buffer = generateCharacter(buffer, key);

        fwrite(&buffer, 1, 1, outputFile);

    }

    return 0;
}

/**
 * Função que encripta um caracter utilizando a chave recebida.
 */
unsigned char generateNextCharacter(unsigned char character, int offset){

    for(;offset;offset--) {

        character = (character > 255) ? 0 : character + 1;

    }

    return character;

}

/**
 * Função que decripta um caracter utilizando a chave recebida.
 */
unsigned char generatePreviousCharacter(unsigned char character, int offset){

    for(;offset;offset--) {

        character = (character < 1) ? 255 : character - 1;

    }

    return character;

}

FILE * getFile(char * fileName, char * fileOptions) {

    FILE * pFile = fopen(fileName, fileOptions);

    if (pFile == NULL) {
        fprintf(stderr, "Erro ao ler arquivo. "
                "Verifique se o mesmo existe no diretório, ou se o nome está correto.\n");
        exit(-1);
    }

    return pFile;

}