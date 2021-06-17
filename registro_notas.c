#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Questão 04.

Faça um programa que leia do teclado os dados de n alunos. Utilize vetor de registro 
para armazenar os dados de cada aluno. Esse vetor deve ser obtido através de uma 
alocação dinâmica, a partir do valor de n informado pelo usuário. O registro contém 
CPF (tipo inteiro), NOME (tipo String) e um vetor de reais de tamanho 3 chamado 
NOTAS. Ao final, imprima seus dados, seguido da média das três notas de cada aluno e 
sua situação (aprovado – média>=7, reprovado – média < 3, exame final – média entre 
3 e 6); 
*/

#define MAX 3

// Registro do aluno.
typedef struct {
	int cpf;
	char nome[30];
	double notas [3];
}aluno;

// Função que preenche os dados de cada aluno.
void preenche(aluno *ptr){
	int i;
	int count = 0;
	double *p;
	
	printf("\nEntre com os dados\n");
	
	printf("CPF: ");
	scanf("%d", &ptr->cpf);
	fflush(stdin);
	
	printf("Nome: ");
	fgets(ptr->nome, 30, stdin);
	fflush(stdin);
	
	// p -> primeira posição (notas[0])
	// primeira posição -> valor de p na primeira posição;
	// p -> segunda posição (notas[1])
	// segunda posição -> valor de p na segunda posição;
	// ...
	// p -> n posição (notas[n])
	// n posição -> valor de p na n posição.
	
	for (p = &ptr->notas[0]; p <= &ptr->notas[2]; p++ ){
		printf("Digite a nota %d: ", count + 1);
		scanf("%lf", p);
		count++;
	}

}

// Função que calcula e imprime os dados de cada aluno.
void impressao(aluno *ptr){
	double media = 0.0;
	double soma = 0, *p;
	int i;
	
	for (p = &ptr->notas[0]; p <= &ptr->notas[2]; p++ ){
		soma += *p;
	}
	
	media = soma / MAX;
	
	printf("\nCPF: %d | Nome: %s", ptr->cpf, ptr->nome);
	printf("Media: %.2f\n", media);
	
	if(media>=7){
		printf("Aprovado!\n");	
	}else if(media>=3 && media<=6.99){
			printf("Exame final!\n");
		}else if(media<3){
				printf("Reprovado!\n");			
		}
}

// Função principal.
int main() {
	// Criação das variáveis.
	aluno *ptr;	
	int n;
	int i;
	
	printf("Insira o numero de alunos: ");
	scanf("%d", &n);
	
	// Alocando a memória para armazenar "n" alunos.
	ptr = (aluno *) malloc(n * sizeof(aluno));
	
	// Laço para preencher os dados de cada aluno.
	for(i=0; i<n; i++)
		preenche(ptr+i);
	
	printf("\nResultado:\n");
	
	// Laço para imprimir os dados de cada aluno.
	for(i=0; i<n; i++)
		impressao(ptr+i);
	
	// Libera a memória armazenada.
	free(ptr);
		
	return 0;
}
