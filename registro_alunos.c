#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Questão 07.

Faça um programa que:
a) Define um registro chamado ALUNO contendo o CPF do aluno, seu nome e uma 
nota (média geral).
b) Cria um arquivo binário chamado turma.arq.
c) Leia do teclado o número n de alunos e suas respectivas informações (nome, CPF e 
média) e grave-os no arquivo turma.arq. 

Questão 08.

Faca um programa que abra o arquivo criado na questão anterior e nele busque se 
um nome informado pelo usuário corresponde a algum aluno da lista. Caso isso ocorra, 
imprima a nota e o CPF desse aluno, já se o nome não for encontrado, imprima uma 
mensagem de notificação na tela do usuário.
*/

typedef struct {
	int cpf;
	char nome[30];
	float media_geral;
}aluno;

// Declara um global ponteiro para o arquivo.
FILE *palunos;

aluno alunos_aux;

void linha() {
	int i;
	for (i = 1; i <= 80; i++) {
		printf("_");
	}
	printf("\n");
}

void abre_arquivo_alunos(){
	// Abre o arquivo em forma de leitura.
	palunos = fopen("turma.arq.dat", "r+b");
	// Caso o arquivo não exista, ele é criado.
	if (palunos == NULL) {
		palunos = fopen("turma.arq.dat", "w+b");
	}
}

void cadastrar() {

	printf("\n\nCadastro de aluno\n\n");
	
	printf("\nCPF: ");
	scanf("%d", &alunos_aux.cpf);
	fflush(stdin);
	
	printf("\nNome: ");
	fgets(alunos_aux.nome, 30, stdin);
	fflush(stdin);
	
	printf("\nMedia: ");
	scanf("%f", &alunos_aux.media_geral);
	fflush(stdin);
	
	// coloca o leitor no inicio do arquivo
	fseek(palunos, 0, SEEK_END);
	
	// escreve o registro da mensagem_aux no arquivo
	fwrite(&alunos_aux, sizeof(aluno), 1, palunos);
	printf("\n\Aluno cadastrado com sucesso!\n\n");

}

void listar() {
	
	printf("\n\nListagem de alunos\n\n\n");
	linha();
	
	rewind(palunos);
	fread(&alunos_aux, sizeof(aluno), 1, palunos);
	
	// percorre todo o arquivo até chegar no fim
	while(feof(palunos) == 0) {
		// verifica se o registro tem dados
		if (alunos_aux.cpf != 0){
			printf("\nCPF: %d\n", alunos_aux.cpf);
			printf("\nNome: %-20s\n", alunos_aux.nome);
			printf("Media geral: %.2f\n", alunos_aux.media_geral);	
		}
		// lê mais um registro
		fread(&alunos_aux, sizeof(aluno), 1, palunos);
	}		
	
	linha();
	getchar();
}

// Função que verifica se o usuario é válido
int valida_aluno(char *nome) {
	int p = 0;
	
	// Retorna leitor do arquivo para o início do arquivo
	rewind(palunos);
	// Faz a leitura do primeiro registro do arquivo
	fread(&alunos_aux, sizeof(aluno), 1, palunos);
	
	// Enquanto não chegar ao fim do arquivo faça
	while (feof(palunos) == 0) {
		
		// Se login passado for igual do usuario_aux
		if (strcmp(alunos_aux.nome, nome) == 0) {
				return p; // Retorna a posição do usuario no arquivo
		} else {
			// Lê o próximo registro
			fread(&alunos_aux, sizeof(aluno), 1, palunos);
			p++; // Incrementa a posição lida do arquivo
		}
	}
	// Retorna -1 caso o usuario não seja encontrado
	return -1; 
}

void buscar_aluno(){
	char nome[30];
	
	printf("\nDigite o nome do aluno: ");
	fgets(nome, 30, stdin);
	
	if(valida_aluno(nome) != -1){
		printf("\nCPF: %d\n", alunos_aux.cpf);
		printf("Media: %.2f", alunos_aux.media_geral);
	}
	
}

void apagar(){
	fclose(palunos);
	remove("turma.arq.dat");
}

int main() {
	
	abre_arquivo_alunos();
	
	int n;
	int i;
	
	printf("Digite o numero de alunos a serem cadastrados: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		cadastrar();
	
	listar();
	
	buscar_aluno();
	
	apagar();
	
	return 0;
}
