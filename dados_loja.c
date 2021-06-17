#include <stdio.h>
#include <stdlib.h>

/* 
Questão 05. 

Faça um programa que:
a) Lê os dados de um estoque de loja. Cada produto do estoque possui um CODIGO 
   (inteiro), uma QUANTIDADE (inteiro) e um PRECO (real). Armazene estes dados em um 
   vetor de registros de 5 posições.
b) Crie um novo vetor de registros e copie apenas aqueles produtos digitados no item a) 
   que custam acima de R$ 10,00.
c) Imprima a média de preço dos produtos que custam acima de R$ 10,00.
d) Imprima todos os produtos que custam mais de R$ 10,00.
*/

// Define a quantidade máxima.
#define MAX 5

// Cria o registro do produto.
struct Produto{
	int codigo;
	int quantidade;
	float preco;
};

// Declara os vetores de registro.
struct Produto produtos1[MAX];

struct Produto produtos2[MAX];

// Função que armazena os dados do estoque.
void dados_estoque(){
	int i;
	
	printf("\nDados do estoque\n");
	
	for(i=0; i<MAX; i++){
		printf("\nCodigo: ");
		scanf("%d", &produtos1[i].codigo);
		fflush(stdin);	
		
		printf("Quantidade: ");	
		scanf("%d", &produtos1[i].quantidade);
		fflush(stdin);
		
		printf("Preco: ");
		scanf("%f", &produtos1[i].preco);
		fflush(stdin);
	}

}

// Função que calcula a média de preço dos produtos com o preço maior que R$10.00.
void media_preco(){
	int i;
	int soma = 0;
	float media = 0.0;
	int contador_p = -1;
	int contador = 0;
	
	for(i=0; i<MAX; i++){
		if(produtos1[i].preco>10){

			contador_p++;
			produtos2[contador_p] = produtos1[i];
			
			contador++;
			
			soma += produtos2[contador_p].preco;
		}
	}

	printf("\nMedia de preco dos produtos maiores que R$ 10.00: %.2f\n", media = (float)soma/contador);
}

// Função que imprime todos os produtos acima de R$10.00.
void impressao(){
	int i;
	int contador = 0;
	
	printf("\nProdutos com preco maior que R$ 10.00\n");
	
	for(i=0; i<MAX; i++){
		if(produtos2[i].preco>10){
			contador++;
		}
	}

	for(i=0; i<contador; i++){
		printf("\nCodigo: %d - Quantidade: %d - Preco: R$ %.2f", produtos2[i].codigo, produtos2[i].quantidade, produtos2[i].preco);
	}
}

// Função principal.
int main() {
	
	// Chama todas as funções.
	dados_estoque();
	
	media_preco();
	
	impressao();
	
	return 0;
}
