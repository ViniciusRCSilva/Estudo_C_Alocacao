#include <stdio.h>
#include <stdlib.h>

/* 
Quest�o 01.

Construa um programa em C que realize as seguintes opera��es:
a) Fa�a uma fun��o int* AlocaMemoria(int n) que receba um valor n como par�metro e crie 
dinamicamente um vetor de n elementos inteiros e retorne um ponteiro para o in�cio deste 
vetor;
b) Crie uma fun��o void imprime(int * p, int n) que receba um ponteiro para um vetor e um 
valor n e imprima os n elementos desse vetor;
c) Construa uma fun��o void LiberaMemoria(int* p) que receba um ponteiro para um vetor e 
libere (usando free()) esta �rea de mem�ria;
d) Crie a fun��o principal que leia um valor n do usu�rio e chame a fun��o AlocaMemoria. 
Depois, a fun��o principal deve ler os n elementos desse vetor. Ent�o, a fun��o principal deve 
chamar a fun��o Imprime para impress�o dos n elementos do vetor criado e, finalmente, 
liberar a mem�ria alocada atrav�s da fun��o LiberaMemoria.
*/


// Cria uma fun��o para a aloca��o de mem�ria do vetor.
int *AlocaMemoria(int n){
	int *p;
	
	// Aloca a mem�ria de acordo com o tamanho.
	p = (int *) malloc(n * sizeof(int));
	
	return *p;
}

// Fun��o que imprime os elementos dentro do vetor.
void imprime(int *p, int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("\nVetor[%d]: %d", i+1, p[i]);
	}
		
}

// Fun��o que libera a mem�ria do ponteiro.
void LiberaMemoria(int *p){
	free(p);
}

int main() {
	// Cria��o das vari�veis.
	int *vetor;
	int n;
	int i;
	
	// Determina a quantidade de elementos dentro do vetor.
	printf("Digite a quantidade de elementos do vetor: ");
	scanf("%d", &n);
	
	// vetor recebe o ponteiro de inteiro.
	vetor = AlocaMemoria(n);
	
	// La�o para armazenar os elementos do vetor.
	for(i=0; i<n; i++){
		printf("Digite o elemento %d: ", i+1);
		scanf("%d", &vetor[i]);
	}	
	
	// Chama fun��o para imprimir os elementos do vetor.	
	imprime(vetor, n);
	
	// Libera a mem�ria alocada.
	LiberaMemoria(vetor);
	
	return 0;
}
