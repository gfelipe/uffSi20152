#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE01_NAME "file01.in"
#define OUTPUT_FILE01_NAME "file01.out"
#define INPUT_FILE02_NAME "file02.in"
#define OUTPUT_FILE02_NAME "file02.out"
#define INPUT_FILE03_NAME "file03.in"
#define OUTPUT_FILE03_NAME "file03.out"

#define READING_FILE_OPTIONS "rb"
#define WRITING_FILE_OPTIONS "wb"

FILE * getFile(char * fileName, char * fileOptions) {

	FILE * pFile = fopen(fileName, fileOptions);

	if (pFile == NULL) {
		fprintf(stderr, "Erro ao ler arquivo. Verifique se o mesmo existe no diretório, ou se o nome está correto.\n");
        exit(-1);
	}

	return pFile;

}

unsigned char generateNextCharacter(unsigned char character, int offset){

	for(;offset;offset--) {

		character = (character > 255) ? 0 : character + 1;

	}

	return character;

}

unsigned char generatePreviousCharacter(unsigned char character, int offset){

	for(;offset;offset--) {

		character = (character < 1) ? 255 : character - 1;

	}

	return character;

}

int executeFileActions(FILE * inputFile, FILE * outputFile, int characterOffset, unsigned char (*generateCharacter)(char, int)) {

	int sizeOfReadCharacter = 0;
	char characterBuffer;

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

		buffer = generateCharacter(buffer, characterOffset);

		fwrite(&characterBuffer, 1, 1, outputFile);

	}

    return 0;
}

int encryptFile(FILE * inputFile, FILE * outputFile, int characterOffset) {

    return executeFileActions(inputFile, outputFile, characterOffset, generateNextCharacter);

}

int decryptFile(FILE * inputFile, FILE * outputFile, int characterOffset) {

    return executeFileActions(inputFile, outputFile, characterOffset, generatePreviousCharacter);

}

int init() {

}

void testExemple01() {

	FILE * inputFile = getFile(INPUT_FILE01_NAME, READING_FILE_OPTIONS);
	FILE * outputFile = getFile(OUTPUT_FILE01_NAME, WRITING_FILE_OPTIONS);

	encryptFile(inputFile, outputFile, 3);

	fclose(inputFile);
	fclose(outputFile);

}

void testExemple02() {

	FILE * inputFile = getFile(INPUT_FILE02_NAME, READING_FILE_OPTIONS);
	FILE * outputFile = getFile(OUTPUT_FILE02_NAME, WRITING_FILE_OPTIONS);

	decryptFile(inputFile, outputFile, 3);

	fclose(inputFile);
	fclose(outputFile);

}

void testExemple03() {

	FILE * inputFile = getFile(INPUT_FILE03_NAME, READING_FILE_OPTIONS);
	FILE * outputFile = getFile(OUTPUT_FILE03_NAME, WRITING_FILE_OPTIONS);

	encryptFile(inputFile, outputFile, 10);

	fclose(inputFile);
	fclose(outputFile);

}

int main () {

	testExemple01();
	testExemple02();
	testExemple03();

	return 0;
}