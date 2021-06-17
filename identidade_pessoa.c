#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Quest�o 03.

Crie uma estrutura que represente uma pessoa, contendo nome, data de 
nascimento e CPF. Crie uma vari�vel que � um ponteiro para esta estrutura (no 
programa principal). Depois crie uma fun��o que receba este ponteiro e preencha os 
dados da estrutura e tamb�m uma uma fun��o que receba este ponteiro e imprima os 
dados da estrutura. Na funcao principal pergunte ao usu�rio o numero n de pessoas a 
serem representadas e utilize "n" para alocar a m�moria para seu ponteiro de 
estrutura. Ao final das chamadas das fun��es, n�o esque�a de liberar a mem�ria 
alocada!
*/

typedef struct pessoa_ {
	char nome[30];
	char data_nascimento[11];
	char cpf[12];
}pessoa;

void entrada(pessoa *ptr){
	printf("\nEntre com os dados da pessoa:\n");
	
    printf("Nome: ");
    fgets(ptr->nome, 30, stdin);
    fflush(stdin);
 
    printf("Data nascimento: ");
    fgets(ptr->data_nascimento, 11, stdin);
    fflush(stdin);
 
    printf("CPF: ");
    fgets(ptr->cpf, 12, stdin);
    fflush(stdin);
}

void impressao(pessoa *ptr){
    printf("Nome: %sData de Nascimento: %sCPF: %s\n", ptr->nome,ptr->data_nascimento, ptr->cpf);
}


int main()
{
   pessoa *ptr;
   int i, n;

   printf("Entre com o numero de pessoas: ");
   scanf("%d", &n);
   fflush(stdin);

   // Alocando a mem�ria para armazenar "n" pessoas
   ptr = (pessoa*) malloc(n * sizeof(pessoa));

   // La�o para a leitura de dados de n pessoas
   for(i = 0; i < n; ++i)
   		entrada(ptr+i);
       
   printf("\nMostrando a lista de pessoas informadas:\n");

   for(i = 0; i < n; ++i)
   		impressao(ptr+i);

	free(ptr);
	
   return 0;
}
