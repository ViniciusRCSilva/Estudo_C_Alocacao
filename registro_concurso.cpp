#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Questão 11. 

Crie um arquivo texto denominado “CONCURSO.txt” que contenha em cada linha 
um número e o nome de uma dupla, para representar os casais de um concurso de 
dança. O número (código do casal) deve ser separado do seu nome por um “tab” em 
branco, exemplo:

Código Nome da dupla
 01       Dupla1;
 02       Dupla2;
...

Obs: para separar palavras com um tab, em C, utiliza-se o símbolo “\t” entre as 
palavras que deseja separar.A quantidade de casais cadastrados deve ser informada pelo usuário, e, a partir disso, 
o arquivo deve ser então preenchido como mostrado acima.
Após a criação e preenchimento do arquivo “CONCURSO.txt”, crie um novo arquivo, 
também do tipo .txt, chamado “CONCURSO_NOTAS.txt” que terá as notas de cada 
dançarino da dupla (dama e cavalheiro) e a nota média de ambos.O arquivo deverá 
ser preenchido seguindo a formatação abaixo:

EXEMPLO:

Código Nome da Dupla Nota da Dama Nota do Cavalheiro Media do Casal
 01      Dupla1           9.0          6.0                 7.5 
 ....

O programa deve ler cada linha do primeiro arquivo (CONCURSO.txt) e, para cada linha
lida, apresentar na tela o código e o nome do casal e solicitar a digitação da nota para 
a dama e da nota para o cavalheiro, calcular a média das notas e gravar todas as 
informações segundo arquivo (CONCURSO_NOTAS), conforme a formatação acima.

*/

// Cria uma estrutura concurso.
typedef struct {
	int codigo;
	char nome[30];
	float nota_dama;
	float nota_cavalheiro;
	float media;
}concurso;

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
		printf("*");
	}
	printf("\n");
	
}

// Função que escreve o registro da dupla no arquivo.
void escreve_dupla_arquivo(concurso *registro){
	FILE *arquivo = fopen("concurso.txt", "at");
	
	if(arquivo != NULL){
		fprintf(arquivo, "%d\t%s\n", registro->codigo, registro->nome);
		
		fclose(arquivo);
	}else{
		printf("\nNao foi possivel abrir o arquivo concurso.txt");
	}
}

// Função que escreve o registro da nota da dupla arquivo.
void escreve_dupla_arquivo_nota(concurso *registro){
	FILE *arquivo = fopen("concurso_notas.txt", "at");
	
	if(arquivo != NULL){
		fprintf(arquivo, "%d\t%s\t%.2f\t%.2f\t%.2f\n", registro->codigo, registro->nome, registro->nota_dama, registro->nota_cavalheiro, registro->media);
		
		fclose(arquivo);
	}else{
		printf("\nNao foi possivel abrir o arquivo concurso_notas.txt");
	}
}

// Função que apaga os arquivos.
void apagar(){
	remove("concurso.txt");
	remove("concurso_notas.txt");
	
	printf("\nArquivos removidos com sucesso!\n");
}

// Função que lista todos os duplas do arquivo.
void listar_duplas() {
	char buffer[1024];
	
	// Abre o arquivo das duplas.
	FILE *arquivo = fopen("concurso.txt", "rt");
	
	printf("\nLISTAGEM DAS DUPLAS\n");
	printf("Cod\tNome\n");
	
	if(arquivo != NULL){
		while(!feof(arquivo)){
			char *linha = fgets(buffer, sizeof(buffer), arquivo);
			if(linha != NULL)	
				printf("%s", buffer);
		}
		fclose(arquivo);
	}
}	

// Função que lista todos as duplas e notas do arquivo.
void listar_duplas_notas() {
	char buffer[1024];
	
	FILE *arquivo = fopen("concurso_notas.txt", "rt");

	printf("\nLISTAGEM DAS NOTAS\n");
	printf("Cod\tNome\tNota dama\tNota cavalheiro\tMedia\n");
	
	if(arquivo != NULL){
		while(!feof(arquivo)){
			char *linha = fgets(buffer, sizeof(buffer), arquivo);
			if(linha != NULL)	
				printf("%s", buffer);
		}
		fclose(arquivo);
	}
}	

// Função para ler strings.
void ler_string(char *ptr, int tam){
	fflush(stdin);
	fgets(ptr, tam, stdin);
	
	// Remove o \n da string.
	ptr[strcspn(ptr, "\n")] = 0;
}

// Função para ler inteiro.
void ler_int(int *ptr){
	fflush(stdin);
	scanf("%d", ptr);	
}

// Função para ler real.
void ler_float(float *ptr){
	fflush(stdin);
	scanf("%f", ptr);
}

// Função para cadastrar as notas das duplas.
void cadastro_notas_duplas(int codigo){
	concurso temp;
	
	char buffer[1024];
	
	FILE *arquivo = fopen("concurso.txt", "rt");
	
	if(arquivo != NULL){
		while(!feof(arquivo)){
			char *linha = fgets(buffer, sizeof(buffer), arquivo);
			sscanf(buffer, "%d %s", &temp.codigo, &temp.nome);
			
			if(linha != NULL && temp.codigo >= codigo){
				printf("\nNotas da dupla %s\n", temp.nome);
				
				printf("\nNota da dama: ");
				ler_float(&temp.nota_dama);
			
				printf("\nNota do cavalheiro: ");
				ler_float(&temp.nota_cavalheiro);
				
				temp.media = (temp.nota_dama+temp.nota_cavalheiro)/2.0;
				
				escreve_dupla_arquivo_nota(&temp);
			}
		}
		fclose(arquivo);
	}
	
	printf("\n\nNota cadastrada com sucesso!\n\n");
}

int busca_ultimo_codigo(){
	int codigo = 0;
	
	char buffer[1024];
	
	FILE *arquivo = fopen("concurso.txt", "rt");
	
	if(arquivo != NULL){
		while(!feof(arquivo)){
			char *linha = fgets(buffer, sizeof(buffer), arquivo);
		}
		fclose(arquivo);
		
		sscanf(buffer, "%d", &codigo);
	}
	
	return codigo;
}

// Função para cadastrar novas duplas.
void cadastrar_duplas(){
	int n;
	int i;
	int offset = busca_ultimo_codigo()+1;
	
	concurso duplas_aux;
	
	printf("\nCadastrar Duplas - Existe(m) %d dupla(s) cadastrada(s).\n", offset-1);
	
	printf("\nDigite a quantidade de duplas a serem cadastradas: ");
	scanf("%d", &n);
	
	desenha_linha();
	
	for(i=offset; i<n+offset; i++){
		printf("\nCadastrar dupla %d\n", i);
		
		duplas_aux.codigo = i;
		
		printf("\nNome da dupla: ");
		ler_string(duplas_aux.nome, 20);
			
		escreve_dupla_arquivo(&duplas_aux);
			
		printf("\n\nDupla cadastrada com sucesso!\n\n");
	}
	
	desenha_linha();
	
	cadastro_notas_duplas(offset);
}

// Função menu.
int menu(){
	int opcao;
	
	while(true){
		
		printf("\n######### MENU #########\n");
		
		printf("1- Cadastrar duplas.\n");
		printf("2- Listar duplas.\n");
		printf("3- Listar notas.\n");
		printf("4- Apagar arquivos.\n");
		printf("0- Sair.\n");
		printf("Digite sua opcao: ");
		ler_int(&opcao);
		
		switch(opcao){
			case 0:
				desenha_linha();
				printf("\nEncerrando o programa.\n");
				desenha_linha();
				exit(0);
			break;
			
			case 1:
				desenha_linha();
				cadastrar_duplas();
				desenha_linha();
			break;	
			
			case 2:
				desenha_linha();
				listar_duplas();
				desenha_linha();
			break;
			
			case 3:
				desenha_linha();
				listar_duplas_notas();
				desenha_linha();
			break;
			
			case 4:
				desenha_linha();
				apagar();
				desenha_linha();
			break;
			
			default:
				desenha_linha();
				printf("\nOpcao invalida!\n");
				desenha_linha();
			break;
		}
	}
	
	return opcao;	
}

// Função principal.
int main() {
	
	menu();
	
	return 0;
}
