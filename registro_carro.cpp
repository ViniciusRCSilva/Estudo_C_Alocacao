#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 
Questão 09.
*/

typedef struct{
	char  marca[15];
	char  modelo[20];
	char  placa[7];
	float km;
	int   ano_fabricacao;
	float valor;
	int   n_portas;
	int   ar_condicionado;
}veiculo;

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

// Função que escreve o registro do veiculo comum no arquivo.
void escreve_arquivo(veiculo registro){
	
	FILE *arquivo = fopen("veiculos.cad.dat", "a+b");
	
	if(arquivo != NULL){
		fwrite(&registro, sizeof(veiculo), 1, arquivo);
		fclose(arquivo);
	}else{
		printf("Falha na abertura do arquivo veiculos.cad.dat!!!");
		
		exit(1);
	}
}

// Função que escreve o registro do veiculo classe A no arquivo.
void escreve_arquivo_a(veiculo registro){
	
	FILE *arquivo = fopen("veiculos_classe_a.cad.dat", "a+b");
	
	if(arquivo != NULL){
		fwrite(&registro, sizeof(veiculo), 1, arquivo);
		fclose(arquivo);
	}else{
		printf("Falha na abertura do arquivo veiculos_classe_a.cad.dat!!!");
		
		exit(1);
	}	
}

// Função que lista todos os veiculos do arquivo
void listar_veiculos() {
	
	FILE *arquivo = fopen("veiculos.cad.dat", "r+b");
	
	veiculo veiculos_aux;
	
	desenha_linha();
		
	printf("\nListagem de veiculos comuns.\n");
	
	desenha_linha();
	
	if(arquivo != NULL){
		fread(&veiculos_aux, sizeof(veiculo), 1, arquivo);
		
		// percorre todo o arquivo até chegar no fim
		while(!feof(arquivo)) {
			// verifica se o registro tem dados
			if (veiculos_aux.placa != 0){
				printf("\nDados do veiculo de placa: %s\n", veiculos_aux.placa);
				desenha_linha2();
				printf("Marca: %s\n", veiculos_aux.marca);
				printf("Modelo: %s\n", veiculos_aux.modelo);
				printf("Quilometragem: %.2f\n", veiculos_aux.km);
				printf("Ano de fabricacao: %d\n", veiculos_aux.ano_fabricacao);
				printf("Valor da diaria: %.2f\n", veiculos_aux.valor);
				printf("Numero de portas: %d\n", veiculos_aux.n_portas);
				printf("Ar condicionado (0 - Nao possui | 1 - Possui ): %d\n", veiculos_aux.ar_condicionado);
				desenha_linha2();
			}
			// lê mais um registro
			fread(&veiculos_aux, sizeof(veiculo), 1, arquivo);
		}		
		fclose(arquivo);
	}else{
		printf("Nenhum veiculo cadastrado!\n");
	}	

}	

// Função que lista dos veiculos da classe A do arquivo
void listar_veiculos_a() {
	
	FILE *arquivo = fopen("veiculos_classe_a.cad.dat", "r+b");
	
	veiculo veiculos_aux;
	
	desenha_linha();
		
	printf("\nListagem de veiculos classe A.\n");
	
	desenha_linha();
	
	if(arquivo != NULL){
		fread(&veiculos_aux, sizeof(veiculo), 1, arquivo);
		
		// percorre todo o arquivo até chegar no fim
		while(!feof(arquivo)) {
			// verifica se o registro tem dados
			if (veiculos_aux.placa != 0){
				printf("\nDados do veiculo de placa: %s\n", veiculos_aux.placa);
				desenha_linha2();				
				printf("Marca: %s\n", veiculos_aux.marca);
				printf("Modelo: %s\n", veiculos_aux.modelo);
				printf("Valor da diaria: %.2f\n", veiculos_aux.valor);
				desenha_linha2();
			}
			// lê mais um registro
			fread(&veiculos_aux, sizeof(veiculo), 1, arquivo);
		}				
		fclose(arquivo);
	}else{
		printf("Nenhum veiculo cadastrado!\n");
	}
	
	desenha_linha();	
	
}	

void apagar(){
	remove("veiculos.cad.dat");
	remove("veiculos_classe_a.cad.dat");
	
	printf("\nArquivos removidos com sucesso!\n");
}

// Função que retorna o ano atual.
int ano_atual(){
	//ponteiro para struct que armazena data e hora  
	struct tm *data_hora_atual;     
	
	//variável do tipo time_t para armazenar o tempo em segundos  
	time_t segundos;
	
	//obtendo o tempo em segundos  
	time(&segundos);   
	
	//para converter de segundos para o tempo local  
	//utilizamos a função localtime  
	data_hora_atual = localtime(&segundos); 
	
	return data_hora_atual->tm_year+1900;
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

void cadastro_veiculos() {	
	int anoAtual = ano_atual();
	
	veiculo veiculos_aux;
	
	printf("\nMarca: ");
	ler_string(veiculos_aux.marca, 15);
	
	printf("\nModelo: ");
	ler_string(veiculos_aux.modelo, 20);

	printf("\nPlaca: ");
	ler_string(veiculos_aux.placa, 7);
	
	printf("\nQuilometragem: ");
	ler_float(&veiculos_aux.km);

	printf("\nAno de fabricacao: ");
	ler_int(&veiculos_aux.ano_fabricacao);	
	
	printf("\nValor da diaria: ");
	ler_float(&veiculos_aux.valor);

	printf("\nNumero de portas: ");
	ler_int(&veiculos_aux.n_portas);

	printf("\nAr condicionado (0 - Nao possui | 1 - Possui ): ");
	ler_int(&veiculos_aux.ar_condicionado);
	
	// escreve o registro do veiculos_aux no arquivo
	if(veiculos_aux.n_portas >= 5 && veiculos_aux.ar_condicionado == 1 && veiculos_aux.ano_fabricacao == anoAtual && veiculos_aux.valor > 380.0){
		escreve_arquivo_a(veiculos_aux);
	}else{
		escreve_arquivo(veiculos_aux);
	}
		
	printf("\n\nVeiculo cadastrado com sucesso!\n\n");
	
}

void cadastrar_novos_veiculos(){
	int n;
	int i;
	
	printf("\nCadastrar Novos Veiculos\n");
	
	printf("\nDigite a quantidade de veiculos a serem cadastrados: ");
	scanf("%d", &n);

	for(i=0; i<n; i++){
		printf("\n\nCadastrar veiculo %d\n\n", i+1);
		cadastro_veiculos();		
	}
	
}

void listar_todos_veiculos(){
	listar_veiculos();
	
	listar_veiculos_a();	
}

int menu(){
	int opcao;
	
	while(true){
		
		printf("\n######### MENU #########\n");
		
		printf("1- Cadastrar novo veiculo.\n");
		printf("2- Listar veiculos.\n");
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
				cadastrar_novos_veiculos();
			break;	
			
			case 2:
				listar_todos_veiculos();
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
