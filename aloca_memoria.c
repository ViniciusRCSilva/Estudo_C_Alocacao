#include <stdio.h>
#include <stdlib.h>

/* 
Questão 01.

Construa um programa em C que realize as seguintes operações:
a) Faça uma função int* AlocaMemoria(int n) que receba um valor n como parâmetro e crie 
dinamicamente um vetor de n elementos inteiros e retorne um ponteiro para o início deste 
vetor;
b) Crie uma função void imprime(int * p, int n) que receba um ponteiro para um vetor e um 
valor n e imprima os n elementos desse vetor;
c) Construa uma função void LiberaMemoria(int* p) que receba um ponteiro para um vetor e 
libere (usando free()) esta área de memória;
d) Crie a função principal que leia um valor n do usuário e chame a função AlocaMemoria. 
Depois, a função principal deve ler os n elementos desse vetor. Então, a função principal deve 
chamar a função Imprime para impressão dos n elementos do vetor criado e, finalmente, 
liberar a memória alocada através da função LiberaMemoria.
*/


// Cria uma função para a alocação de memória do vetor.
int *AlocaMemoria(int n){
	int *p;
	
	// Aloca a memória de acordo com o tamanho.
	p = (int *) malloc(n * sizeof(int));
	
	return *p;
}

// Função que imprime os elementos dentro do vetor.
void imprime(int *p, int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("\nVetor[%d]: %d", i+1, p[i]);
	}
		
}

// Função que libera a memória do ponteiro.
void LiberaMemoria(int *p){
	free(p);
}

int main() {
	// Criação das variáveis.
	int *vetor;
	int n;
	int i;
	
	// Determina a quantidade de elementos dentro do vetor.
	printf("Digite a quantidade de elementos do vetor: ");
	scanf("%d", &n);
	
	// vetor recebe o ponteiro de inteiro.
	vetor = AlocaMemoria(n);
	
	// Laço para armazenar os elementos do vetor.
	for(i=0; i<n; i++){
		printf("Digite o elemento %d: ", i+1);
		scanf("%d", &vetor[i]);
	}	
	
	// Chama função para imprimir os elementos do vetor.	
	imprime(vetor, n);
	
	// Libera a memória alocada.
	LiberaMemoria(vetor);
	
	return 0;
}
