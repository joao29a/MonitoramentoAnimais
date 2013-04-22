#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/captura.h"
#include "hdr/individuo.h"
#include "hdr/functions.h"

void inserirCaptura(){
	char idCaptura[BUFFER_SZ];
	char idIndividuo[BUFFER_SZ];
	char comprimento[BUFFER_SZ];
	char largura[BUFFER_SZ];
	char peso[BUFFER_SZ];
	char data[BUFFER_SZ];
	char local[BUFFER_SZ];

	int verificarCap;
	int verificarInd;

	do{
		inserirDado("ID Captura: ",idCaptura);
		verificarCap = buscarCaptura(idCaptura);
		insiraDiferente(verificarCap);
	} while (verificarCap!=-1);

	int idCap = atoi(idCaptura);

	do{
		inserirDado("ID Indivíduo: ",idIndividuo);
		verificarInd = buscarIndividuo(idIndividuo);
		insiraIgual(verificarInd);
	} while (verificarInd==-1);

	int idInd = atoi(idIndividuo);

	do{
		inserirDado("Comprimento: ",comprimento);
	} while (atoi(comprimento)==0);

	int compr = atoi(comprimento);

	do{
		inserirDado("Largura: ",largura);
	} while (atoi(largura)==0);

	int larg = atoi(largura);

	do{
		inserirDado("Peso: ",peso);
	} while (atoi(peso)==0);

	int pesokg = atoi(peso);

	inserirDado("Data: ",data);
	inserirDado("Local: ",local);

	FILE *arquivo = abrirArquivo(captura,"r+");
	fseek(arquivo,0,SEEK_END);
	int pos = ftell(arquivo);
	fprintf(arquivo,"id captura = %d\nid individuo = %d\n",idCap,idInd);
	fprintf(arquivo,"comprimento = %d\nlargura = %d\n",compr,larg);
	fprintf(arquivo,"peso = %d\ndata = %s\nlocal = %s\n#\n",pesokg,data,local);
	fclose(arquivo);

	FILE *arquivoPos = abrirArquivo(capturaPos,"a+");
	salvarPos(arquivoPos,pos);
	fclose(arquivoPos);
}

int buscarCaptura(char *id){
	int idNumber = atoi(id);
	FILE *arquivo = abrirArquivo(captura,"r");
	FILE *arquivoPos = abrirArquivo(capturaPos,"r");
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

void removerCaptura(){
	char id[BUFFER_SZ];
	inserirDado("ID: ",id);
	int pos = buscarCaptura(id);
	if (pos != -1){
		FILE *arquivoPos = abrirArquivo(capturaPos,"r+");
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
				printf("Captura removida\n");
			}
		}
		fclose(arquivoPos);
	}
	else printf("Captura não encontrada\n");
}
