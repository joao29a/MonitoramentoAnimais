#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/especie.h"
#include "hdr/functions.h"

void inserirEspecie(){
	char id[BUFFER_SZ];
	char nomeCientifico[BUFFER_SZ];
	char nomePopular[BUFFER_SZ];
	char descricao[BUFFER_SZ];
	
	int verificarId;
	do{
		inserirDado("ID: ",id);
		verificarId = buscarEspecie(id);
		insiraDiferente(verificarId);
	}while (verificarId!=-1);

	int idNumber = atoi(id);

	inserirDado("Nome científico: ",nomeCientifico);
	inserirDado("Nome popular: ",nomePopular);
	inserirDado("Descrição: ",descricao);

	FILE *arquivo = abrirArquivo(especie,"r+");
	fseek(arquivo,0,SEEK_END);
	int pos = ftell(arquivo);
	fprintf(arquivo,"id = %d\nnome científico = %s\nnome popular = %s\ndescrição = %s\n#\n",idNumber,nomeCientifico,nomePopular,descricao);
	fclose(arquivo);

	FILE *arquivoPos = abrirArquivo(especiePos,"a+");
	salvarPos(arquivoPos,pos);
	fclose(arquivoPos);
}


int buscarEspecie(char *id){
    	int idNumber = atoi(id);
	FILE *arquivo = abrirArquivo(especie,"r");
	FILE *arquivoPos = abrirArquivo(especiePos,"r");
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
	char id[BUFFER_SZ];
	inserirDado("ID: ",id);
	int pos = buscarEspecie(id);
	if (pos != -1){
		FILE *arquivoPos = abrirArquivo(especiePos,"r+");
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
