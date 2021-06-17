#include <stdio.h>
#include <stdlib.h>

/* 
Quest�o 05. 

Fa�a um programa que:
a) L� os dados de um estoque de loja. Cada produto do estoque possui um CODIGO 
   (inteiro), uma QUANTIDADE (inteiro) e um PRECO (real). Armazene estes dados em um 
   vetor de registros de 5 posi��es.
b) Crie um novo vetor de registros e copie apenas aqueles produtos digitados no item a) 
   que custam acima de R$ 10,00.
c) Imprima a m�dia de pre�o dos produtos que custam acima de R$ 10,00.
d) Imprima todos os produtos que custam mais de R$ 10,00.
*/

// Define a quantidade m�xima.
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

// Fun��o que armazena os dados do estoque.
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

// Fun��o que calcula a m�dia de pre�o dos produtos com o pre�o maior que R$10.00.
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

// Fun��o que imprime todos os produtos acima de R$10.00.
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

// Fun��o principal.
int main() {
	
	// Chama todas as fun��es.
	dados_estoque();
	
	media_preco();
	
	impressao();
	
	return 0;
}
