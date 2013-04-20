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

int verificar_individuo_removido(){
	FILE *arquivo = abrirArquivo(individuo,"r");
	int somaPos = 0;
	char linha[BUFFER_SZ];
	while (fgets(linha,BUFFER_SZ,arquivo)!=NULL){
		int id = -1;
		sscanf(linha,"%*[^0-9] %d",&id);
		if (id == -1)
			fclose(arquivo);
			return somaPos;
		somaPos+=TAM_REG;
		fseek(arquivo,somaPos,SEEK_SET);
	}
	fclose(arquivo);
	return somaPos;
}


void salvarPos(FILE *arquivo, int pos){
	fprintf(arquivo,"%d #INSERIDO#\n",pos);
}

void escreverCaptura(FILE *arquivo, FILE *arquivoPos){
	int i;
	int size;
	int pos = ftell(arquivo);
	int total = 0;
	for (i = inicio; i < posVet; i++){
		size = strlen(capturaReg[i].idCaptura);
		total+=size;
		fwrite(capturaReg[i].idCaptura,size,1,arquivo);
		fwrite("\n",1,1,arquivo);
		total+=1;
		
		size = strlen(capturaReg[i].idIndividuo);
		total+=size;
		fwrite(capturaReg[i].idIndividuo,size,1,arquivo);
		fwrite("\n",1,1,arquivo);
		total+=1;

		size = strlen(capturaReg[i].comprimento);
		total+=size;
		fwrite(capturaReg[i].comprimento,size,1,arquivo);
		fwrite("\n",1,1,arquivo);
		total+=1;

		size = strlen(capturaReg[i].largura);
		total+=size;
		fwrite(capturaReg[i].largura,size,1,arquivo);
		fwrite("\n",1,1,arquivo);
		total+=1;

		size = strlen(capturaReg[i].peso);
		total+=size;
		fwrite(capturaReg[i].peso,size,1,arquivo);
		fwrite("\n",1,1,arquivo);
		total+=1;

		size = strlen(capturaReg[i].data);
		total+=size;
		fwrite(capturaReg[i].data,size,1,arquivo);
		fwrite("\n",1,1,arquivo);
		total+=1;

		size = strlen(capturaReg[i].local);
		total+=size;
		fwrite(capturaReg[i].local,size,1,arquivo);
		
		fwrite("\n#\n",3,1,arquivo);
		total+=3;

		salvarPos(arquivoPos,pos);
		pos+=total;
		total = 0;
	}
	inicio = posVet;
	fclose(arquivo);
	fclose(arquivoPos);
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
