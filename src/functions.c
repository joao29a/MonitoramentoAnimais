#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "hdr/functions.h"
#include "hdr/captura.h"

void inserirDado(char *tipo, char *dado){
	printf("%s",tipo);
	fgets(dado,BUFFER_SZ,stdin);
	sscanf(dado,"%[^\n]",dado);
}

void imprimirDado(int pos, char *tipoArq, char *tipoTxt){
	if (pos!=-1){
		FILE *arquivo = abrirArquivo(tipoArq,"r");
		fseek(arquivo,pos,SEEK_SET);
		char dado[BUFFER_SZ];
		while (fgets(dado,BUFFER_SZ,arquivo)!=NULL && strcmp(dado,"#\n")!=0){
			printf("%s",dado);
			dado[0]='\0';
		}

	} else printf("%s não encontrado(a)\n",tipoTxt);

}

FILE* abrirArquivo(char *nomeArquivo, char *tipo){
	return fopen(nomeArquivo,tipo);
}

void insiraDiferente(int id){
	if (id != -1)
		printf("ID já inserido...\n");
}

void insiraIgual(int id){
	if (id == -1)
		printf("Insira um ID existente...\n");
}

void verificarArquivo(char *txt){
	FILE *arquivo=fopen(txt,"r");
	if (arquivo==NULL)
		arquivo=fopen(txt,"w");
	fclose(arquivo);
}

void verificarPasta(char* pastaNome){
	struct stat st;
	if (stat(pastaNome, &st) == -1)
    		mkdir(pastaNome, 0777);	
}

void verificarEspecie(){
	verificarPasta(pastaEspecie);
	verificarArquivo(especie);
	verificarArquivo(especiePos);
}

void verificarIndividuo(){
	verificarPasta(pastaIndividuo);
	verificarArquivo(individuo);
}

void verificarCaptura(){
	verificarPasta(pastaCaptura);
	verificarArquivo(captura);
	verificarArquivo(capturaPos);
	verificarArquivo(capturatxt);
}

int verificar_qtd_especie(){
	FILE *arquivo = abrirArquivo(especiePos,"r");
	char linha[BUFFER_SZ];
	while (fgets(linha,BUFFER_SZ,arquivo)!=NULL){
		sscanf(linha,"%*s %[^\n]",linha);
		if (strcmp(linha,"#INSERIDO#")==0)
			return 1;
	}
	return 0;
}

int verificar_qtd_individuo(){
	FILE *arquivo = abrirArquivo(individuo,"r");
	char linha[BUFFER_SZ];
	int somaPos = 0;
	while (fgets(linha,BUFFER_SZ,arquivo)!=NULL){
		int id = -1;
		sscanf(linha,"%*[^0-9] %d",&id);
		if (id != -1)
			fclose(arquivo);
			return 1;
		somaPos+=TAM_REG;
		fseek(arquivo,somaPos,SEEK_SET);
	}
	fclose(arquivo);
	return 0;
}

int verificar_individuo_removido(FILE *arquivo){
	int somaPos = 0;
	char linha[BUFFER_SZ];
	while (fgets(linha,BUFFER_SZ,arquivo)!=NULL){
		int id = -1;
		sscanf(linha,"%*[^0-9] %d",&id);
		if (id == -1)
			return somaPos;
		somaPos+=TAM_REG;
		fseek(arquivo,somaPos,SEEK_SET);
	}
	return somaPos;
}


void salvarPos(FILE *arquivo, int pos){
	fprintf(arquivo,"%d #INSERIDO#\n",pos);
}

void anexarFinal(){
	FILE *arquivo = abrirArquivo(captura,"ab");
	FILE *arquivoPos = abrirArquivo(capturaPos,"a+");
	escreverCaptura(arquivo,arquivoPos);
}

void reescreverCaptura(){
	FILE *arquivo = abrirArquivo(captura,"wb");
	FILE *arquivoPos = abrirArquivo(capturaPos,"w");
	escreverCaptura(arquivo,arquivoPos);
}

void escreverCaptura(FILE *arquivo, FILE *arquivoPos){
	FILE *arquivotxt = abrirArquivo(capturatxt,"r");
	char buffer[BUFFER_SZ];
	fseek(arquivo,0,SEEK_END);
	int pos = ftell(arquivo);
	while (fgets(buffer,BUFFER_SZ,arquivotxt)!=NULL){
		char id[BUFFER_SZ];
		sscanf(buffer,"%[^=]",id);
		if (strcmp(id,"id da captura ")==0){
			salvarPos(arquivoPos,pos);
		}
		fprintf(arquivo,"%s",buffer);
		if (strcmp(buffer,"#\n")==0){
			pos = ftell(arquivo);
		}
	}
	fclose(arquivo);
	fclose(arquivoPos);
	fclose(arquivotxt);
}
