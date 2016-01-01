#include<stdio.h>
#include<time.h>
#include <stdlib.h>

unsigned long long fat(unsigned short n) {
	if (n == 1) return 1;
	else return n * fat(n-1);
}

unsigned long long somafat_rec(unsigned short n, int *tempo) {

	clock_t startOfExecutionClock = clock();
	clock_t totalTimeOfExecutionClock;


    if (n == 1) {

        totalTimeOfExecutionClock = clock() - startOfExecutionClock;
        (*tempo) = (*tempo) + (int)totalTimeOfExecutionClock;

        return 1;

    } else {

        totalTimeOfExecutionClock = clock() - startOfExecutionClock;
        (*tempo) = (*tempo) + (int)totalTimeOfExecutionClock;

        return fat(n) + somafat_rec(n-1,tempo);

    }

}

unsigned long long somafat_norm(unsigned short n, int *tempo) {

    clock_t startOfExecutionClock = clock();
    clock_t totalTimeOfExecutionClock;
    unsigned long long fatorialSum = 0;

	while(n) {
		fatorialSum = fatorialSum + fat(n);
		n--;
	}

	totalTimeOfExecutionClock = clock() - startOfExecutionClock;
	(*tempo) = (int)totalTimeOfExecutionClock;

	return fatorialSum;

}

int main() {

	int * normalExecutionClock = (int*) malloc(sizeof(int));
	int * recursiveExecutionClock = (int*) malloc(sizeof(int));

    unsigned short input;

    unsigned long long normalFatorialSum;
    unsigned long long recursiveFatorialSum;
    
    fscanf(stdin, "%hu", &input);

    normalFatorialSum = somafat_norm(input, normalExecutionClock);
    recursiveFatorialSum = somafat_rec(input, recursiveExecutionClock);

    fprintf(stdout, "A soma fatorial de %hu é: %llu\n", input, normalFatorialSum);
    fprintf(stdout, "A soma fatorial de %hu é: %llu\n", input, recursiveFatorialSum);
    fprintf(stderr, "O tempo com recursão é de: %d\n", *recursiveExecutionClock);
    fprintf(stderr, "O tempo sem recursão é de: %d\n", *normalExecutionClock);

	return 0;

}
