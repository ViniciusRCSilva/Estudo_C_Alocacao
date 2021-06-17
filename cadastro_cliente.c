#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Questão 10. 
*/

typedef struct{
	char nome[20];
	char endereco[40];
	char sexo;
	int  dia_nascimento;
	int  mes_nascimento;
	int  ano_nascimento;
}cliente;

// Procedimento que imprime uma linha no terminal.
void desenha_linha() {
	int i;

	for (i = 1; i <= 80; i++) {
		printf("_");
	}
	printf("\n");	
	
}

void desenha_linha2(){
	int i;
	for (i = 1; i <= 80; i++) {
		printf("#");
	}
	printf("\n");
	
}

// Função que escreve o registro do cliente no arquivo.
void arquivo_cliente(cliente registro){
	
	FILE *arquivo = fopen("zinho.cad.dat", "a+b");
	
	if(arquivo != NULL){
		fwrite(&registro, sizeof(cliente), 1, arquivo);
		fclose(arquivo);
	}else{
		printf("Falha na abertura do arquivo zinho.cad.dat!!!");
		
		exit(1);
	}
}

// Função que escreve o registro do cliente homem com 50 ou mais anos no arquivo.
void arquivo_cliente_m50(cliente registro){
	
	FILE *arquivo = fopen("zinho.m50.cad.dat", "a+b");
	
	if(arquivo != NULL){
		fwrite(&registro, sizeof(cliente), 1, arquivo);
		fclose(arquivo);
	}else{
		printf("Falha na abertura do arquivo zinho.m50.cad.dat!!!");
		
		exit(1);
	}
}

void apagar(){
	remove("zinho.cad.dat");
	remove("zinho.m50.cad.dat");
	
	printf("\nArquivos removidos com sucesso!\n");
}

// Função que lista todos os clientes do arquivo.
void listar_clientes() {
	
	FILE *arquivo = fopen("zinho.cad.dat", "r+b");
	
	cliente clientes_aux;
	
	desenha_linha();
		
	printf("\nListagem de clientes.\n");
	
	desenha_linha();
	
	if(arquivo != NULL){
		fread(&clientes_aux, sizeof(cliente), 1, arquivo);
		
		// percorre todo o arquivo até chegar no fim
		while(!feof(arquivo)) {
			// verifica se o registro tem dados
			if (clientes_aux.nome != 0){
				printf("\nNome: %s\n", clientes_aux.nome);
				printf("Endereco: %s\n", clientes_aux.endereco);
				printf("Sexo: %s\n", clientes_aux.sexo);
				printf("%d/%d/%d\n", clientes_aux.dia_nascimento, clientes_aux.mes_nascimento, clientes_aux.ano_nascimento);
				desenha_linha2();
			}
			// lê mais um registro
			fread(&clientes_aux, sizeof(cliente), 1, arquivo);
		}		
		fclose(arquivo);
	}else{
		printf("Nenhum cliente cadastrado!\n");
	}	
}	

// Função que lista todos os clientes do arquivo.
void listar_clientes_m50() {
	
	FILE *arquivo = fopen("zinho.m50.cad.dat", "r+b");
	
	cliente clientes_aux;
	
	desenha_linha();
		
	printf("\nListagem de clientes M50.\n");
	
	desenha_linha();
	
	if(arquivo != NULL){
		fread(&clientes_aux, sizeof(cliente), 1, arquivo);
		
		// percorre todo o arquivo até chegar no fim
		while(!feof(arquivo)) {
			// verifica se o registro tem dados
			if (clientes_aux.nome != 0){
				printf("\nNome: %s\n", clientes_aux.nome);
				printf("Endereco: %s\n", clientes_aux.endereco);
				desenha_linha2();
			}
			// lê mais um registro
			fread(&clientes_aux, sizeof(cliente), 1, arquivo);
		}		
		fclose(arquivo);
	}else{
		printf("Nenhum cliente cadastrado!\n");
	}	
}	

// Função para ler strings.
void ler_string(char *ptr, int tam){
	fflush(stdin);
	fgets(ptr, tam, stdin);
	
	// Remove o \n da string.
	ptr[strcspn(ptr, "\n")] = 0;
}

// Função para ler caracteres.
void ler_char(char *ptr){
	fflush(stdin);
	gets(ptr);
}

// Função para ler inteiro.
void ler_int(int *ptr){
	fflush(stdin);
	scanf("%d", ptr);	
}

// Função que cadastra o cliente.
void cadastro_clientes() {	
	
	cliente clientes_aux;
	
	printf("\nNome: ");
	ler_string(clientes_aux.nome, 20);
	
	printf("\nEndereco: ");
	ler_string(clientes_aux.endereco, 40);

	printf("\nSexo (m - f): ");
	ler_char(&clientes_aux.sexo);
	
	printf("\nDia de nascimento: ");
	ler_int(&clientes_aux.dia_nascimento);

	printf("\nMes de nascimento: ");
	ler_int(&clientes_aux.mes_nascimento);	
	
	printf("\nAno de nascimento: ");
	ler_int(&clientes_aux.ano_nascimento);

	// escreve o registro do clientes_aux no arquivo
	if((clientes_aux.sexo == 'm' || clientes_aux.sexo == 'M') && clientes_aux.ano_nascimento == 1961){
		arquivo_cliente_m50(clientes_aux);
	}else{
		arquivo_cliente(clientes_aux);
	}
		
	printf("\n\nCliente cadastrado com sucesso!\n\n");
	
}

void cadastrar_novos_clientes(){
	int n;
	int i;
	
	printf("\nCadastrar Novos clientes\n");
	
	printf("\nDigite a quantidade de clientes a serem cadastrados: ");
	scanf("%d", &n);

	for(i=0; i<n; i++){
		printf("\n\nCadastrar o cliente %d\n\n", i+1);
		cadastro_clientes();		
	}
	
}

void listar_todos_clientes(){
	listar_clientes();
	
	listar_clientes_m50();	
}

int menu(){
	int opcao;
	
	while(true){
		
		printf("\n######### MENU #########\n");
		
		printf("1- Cadastrar novo cliente.\n");
		printf("2- Listar clientes.\n");
		printf("3- Apagar arquivos.\n");
		printf("0- Sair.\n");
		printf("Digite sua opcao: ");
		ler_int(&opcao);
		
		switch(opcao){
			case 0:
				printf("Encerrando o programa.");
				exit(0);
			break;
			
			case 1:
				cadastrar_novos_clientes();
			break;	
			
			case 2:
				listar_todos_clientes();
			break;
			
			case 3:
				apagar();
			break;
			
			default:
				printf("\nOpcao invalida!\n");
			break;
		}
	}
	
	return opcao;	
}

int main() {
	
	menu();
	
	return 0;
}
