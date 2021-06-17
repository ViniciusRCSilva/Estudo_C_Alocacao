#include <stdio.h>
#include <stdlib.h>

/*
Questão 02.  

Implemente uma função que recebe 2 vetores de valores reais em R3 (ou seja, vetores de 
tamanho 3) e retorne um ponteiro que corresponde ao produto vetorial entre esses vetores. A 
funcao principal deve imprimir na tela do usuário as coordenadas do produto vetorial obtido.
*/

// Define a quantidade máxima de elementos nos vetores.
#define MAX 3

int main() {
	// Criação das variáveis.
	double *vet1;
	double *vet2;
	double *r3;
	int i;
	
	// Alocação de memória dos vetores.
	vet1 = (double *) malloc(MAX * sizeof(int));
	vet2 = (double *) malloc(MAX * sizeof(int));
	r3 = (double *) malloc(MAX * sizeof(int));
	
	// Armazena os elementos do vetor.
	for(i=0; i<MAX; i++){
		printf("Digite o elemento %d do vetor 1: ", i+1);
		scanf("%lf", &vet1[i]);
	}

	printf("\n");
	
	// Armazena os elementos do vetor.
	for(i=0; i<MAX; i++){
		printf("Digite o elemento %d do vetor 2: ", i+1);
		scanf("%lf", &vet2[i]);
	}
	
	// Armazena os elementos do produto dos vetores.
	for(i=0; i<MAX; i++){
		r3[i] = vet1[i] * vet2[i];
	}
	
	// Imprime o resultado.
	for(i=0; i<MAX; i++){
		printf("\nr3[%d] = vet1[%d] x vet2[%d] = %.2lf", i+1, i+1, i+1, r3[i]);
	}
	
	for(i=0; i<MAX; i++){
		printf("\nr3[%d] = %.2lf x %.2lf = %.2lf", i+1, vet1[i], vet2[i], r3[i]);
	}

	return 0;
}
