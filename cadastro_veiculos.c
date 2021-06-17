#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Questão 06.

Escreva um programa que crie um pequeno cadastro de veículos para aluguel em 
uma locadora de veículos em um vetor de registros com a seguinte estrutura:
* Marca: (string de 15 posições)
* Modelo: (string de 20 posições)
* Valor da diária: (real)
* Número de portas: (integer)
Após a criação do cadastro, o programa deve, em processo repetitivo, ler do teclado o 
número de portas e o valor máximo da diária do veículo desejado e, em seguida, 
apresentar na tela uma relação contendo a marca e o modelo de todos os veículos 
cadastrados e que satisfaçam as condições solicitadas. O processo repetitivo termina 
quando for informado o valor 0 (zero) para o número de portas.
OBS.:
1) O número de veículos a serem cadastrados deve ser lido no início do programa no 
intervalo [1,20];
Enquanto não for digitado um número no intervalo definido o programa não deve 
prosseguir.
2) O programa deve conter necessariamente:
a) Uma função ou procedimento que receba o número de veículos a serem 
cadastrados e retorne por parâmetro o vetor registro com os veículos cadastrados;
b) Uma função ou procedimento para imprimir uma relação contendo a marca e 
modelo de todos os veículos que tenham as características indicadas a ser chamada no 
programa principal. 
*/

#define MAX 20

struct carro {
	char marca[15];
	char modelo[20];
	float preco;
	int n_portas;
};

struct carro carros[MAX];

int n_veiculos(){
	int num_veiculos;
	
	printf("Digite o numero de veiculos a serem cadastrados: ");
	scanf("%d", &num_veiculos);
	fflush(stdin);
	
	while(num_veiculos>=20 && num_veiculos<1){
		printf("Numero de veiculos excede o maximo ou nao apresenta a quantidade minima para serem cadastrados.\nPor favor, insira novamente: ");
		scanf("%d", &num_veiculos);
		fflush(stdin);
	}
	
	return num_veiculos;
}

void cadastro(int num_veiculos){
	int i;
	
	for(i=0; i<num_veiculos; i++){
		printf("\nInforme a marca: ");
		fgets(carros[i].marca, 15, stdin);
		fflush(stdin);
		
		printf("\nInforme o modelo: ");
		fgets(carros[i].modelo, 20, stdin);
		fflush(stdin);
		
		printf("\nInforme o preco: ");
		scanf("%f", &carros[i].preco);
		fflush(stdin);
		
		printf("\nInforme a quantidade de portas: ");
		scanf("%d", &carros[i].n_portas);
		fflush(stdin);
		
		while(carros[i].n_portas == 0){
			printf("\nLimite minimo de portas: 1");
			printf("\nInforme a quantidade de portas: ");
			scanf("%d", &carros[i].n_portas);
			fflush(stdin);			
		}	
	}
}

void pesquisa(int num_veiculos){
	int i;
	int num_portas;
	float valor_diaria;
	
	while(num_portas != 0){
		printf("\nSe caso os parametros passados nao satisfacam as condicoes solicitadas, nada sera mostrado.\n");
		printf("Para sair do programa, digite 0\n");
		
		printf("\nDigite o numero de portas do veiculo desejado: ");
		scanf("%d", &num_portas);
		fflush(stdin);
		
		if(num_portas == 0){
			return 0;
		}
		
		printf("Informe o valor maxima da diaria do veiculo: ");
		scanf("%f", &valor_diaria);
		fflush(stdin);
		
		for(i=0; i<num_veiculos; i++){
			if(num_portas == carros[i].n_portas && carros[i].preco<=valor_diaria){
				printf("\n%s %s", carros[i].marca, carros[i].modelo);
			}
		}	
	}
	
}

int main() {
	int quantidade_veiculos = 0;
	
	quantidade_veiculos = n_veiculos();
	
	cadastro(quantidade_veiculos);
	
	pesquisa(quantidade_veiculos);
	
	return 0;
}
