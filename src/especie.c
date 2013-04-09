#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/especie.h"
#include "hdr/buffer.h"


void inserirDado(char *tipo, char *dado){
	printf("%s",tipo);
	fgets(dado,BUFFER_SZ,stdin);
	sscanf(dado,"%[^\n]",dado);
}

void imprimirEspecie(int pos){
	if (pos!=-1){
		FILE *arquivo = abrirArquivoEspecie("r");
		fseek(arquivo,pos,SEEK_SET);
		char dado[BUFFER_SZ];
		while (fgets(dado,BUFFER_SZ,arquivo)!=NULL && strcmp(dado,"#\n")!=0){
			printf("%s",dado);
			dado[0]='\0';
		}

	} else printf("Espécie não encontrada\n");

}

FILE* abrirArquivoEspecie(char *tipo){
	return fopen("EspecieArq/especie.txt",tipo);
}

FILE* abrirArquivoPosEspecie(char *tipo){
	return fopen("EspecieArq/especiePos.txt",tipo);
}


void inserirEspecie(){
	char id[BUFFER_SZ];
	char nomeCientifico[BUFFER_SZ];
	char nomePopular[BUFFER_SZ];
	char descricao[BUFFER_SZ];

	inserirDado("ID: ",id);
	inserirDado("Nome científico: ",nomeCientifico);
	inserirDado("Nome popular: ",nomePopular);
	inserirDado("Descrição: ",descricao);

	FILE *arquivo = abrirArquivoEspecie("r+");
	fseek(arquivo,0,SEEK_END);
	int pos = ftell(arquivo);
	fprintf(arquivo,"id = %s\nnome científico = %s\nnome popular = %s\ndescrição = %s\n#\n",id,nomeCientifico,nomePopular,descricao);
	fclose(arquivo);

	FILE *arquivoPos = abrirArquivoPosEspecie("r+");
	fseek(arquivoPos,0,SEEK_END);
	fprintf(arquivoPos,"%d #INSERIDO#\n",pos);
	fclose(arquivoPos);

}


int buscarEspecie(){
	char id[BUFFER_SZ];
	inserirDado("ID: ",id);
	int idNumber = atoi(id);
	FILE *arquivo = abrirArquivoEspecie("r");
	FILE *arquivoPos = abrirArquivoPosEspecie("r");
	char linha[BUFFER_SZ];
	while (fgets(linha,BUFFER_SZ,arquivoPos)!=NULL){
		int pos;
		char removido[BUFFER_SZ];
		sscanf(linha,"%d %s",&pos,removido);
		fseek(arquivo,pos,SEEK_SET);
		fgets(linha,BUFFER_SZ,arquivo);
		int idArquivo;
		sscanf(linha,"%*[^0-9] %d",&idArquivo);
		if (idNumber==idArquivo && strcmp(removido,"#REMOVIDO#")!=0){
			fclose(arquivo);
			fclose(arquivoPos);
			return pos;
		}
	}
	fclose(arquivo);
	fclose(arquivoPos);
	return -1;
}

void removerEspecie(){
	int pos = buscarEspecie();
	if (pos != -1){
		FILE *arquivoPos = abrirArquivoPosEspecie("r+");
		char buffer[BUFFER_SZ];
		int encontrou = 0;
		while (!encontrou){
			int posArqBytes = ftell(arquivoPos);
			fgets(buffer,BUFFER_SZ,arquivoPos);
			int posArq;
			sscanf(buffer,"%d",&posArq);
			if (pos == posArq){
				encontrou = 1;
				fseek(arquivoPos,posArqBytes,SEEK_SET);
				fprintf(arquivoPos,"%d #REMOVIDO#\n",pos);
				printf("Espécie removida\n");
			}
		}
		fclose(arquivoPos);
	}
	else printf("Espécie não encontrada\n");
}
