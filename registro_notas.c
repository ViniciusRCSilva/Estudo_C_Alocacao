#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Quest�o 04.

Fa�a um programa que leia do teclado os dados de n alunos. Utilize vetor de registro 
para armazenar os dados de cada aluno. Esse vetor deve ser obtido atrav�s de uma 
aloca��o din�mica, a partir do valor de n informado pelo usu�rio. O registro cont�m 
CPF (tipo inteiro), NOME (tipo String) e um vetor de reais de tamanho 3 chamado 
NOTAS. Ao final, imprima seus dados, seguido da m�dia das tr�s notas de cada aluno e 
sua situa��o (aprovado � m�dia>=7, reprovado � m�dia < 3, exame final � m�dia entre 
3 e 6); 
*/

#define MAX 3

// Registro do aluno.
typedef struct {
	int cpf;
	char nome[30];
	double notas [3];
}aluno;

// Fun��o que preenche os dados de cada aluno.
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
	
	// p -> primeira posi��o (notas[0])
	// primeira posi��o -> valor de p na primeira posi��o;
	// p -> segunda posi��o (notas[1])
	// segunda posi��o -> valor de p na segunda posi��o;
	// ...
	// p -> n posi��o (notas[n])
	// n posi��o -> valor de p na n posi��o.
	
	for (p = &ptr->notas[0]; p <= &ptr->notas[2]; p++ ){
		printf("Digite a nota %d: ", count + 1);
		scanf("%lf", p);
		count++;
	}

}

// Fun��o que calcula e imprime os dados de cada aluno.
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

// Fun��o principal.
int main() {
	// Cria��o das vari�veis.
	aluno *ptr;	
	int n;
	int i;
	
	printf("Insira o numero de alunos: ");
	scanf("%d", &n);
	
	// Alocando a mem�ria para armazenar "n" alunos.
	ptr = (aluno *) malloc(n * sizeof(aluno));
	
	// La�o para preencher os dados de cada aluno.
	for(i=0; i<n; i++)
		preenche(ptr+i);
	
	printf("\nResultado:\n");
	
	// La�o para imprimir os dados de cada aluno.
	for(i=0; i<n; i++)
		impressao(ptr+i);
	
	// Libera a mem�ria armazenada.
	free(ptr);
		
	return 0;
}
