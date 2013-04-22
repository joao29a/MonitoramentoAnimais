#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/captura.h"
#include "hdr/individuo.h"
#include "hdr/functions.h"

int posVet = 0;
int inicio = 0;
Captura capturaReg[BUFFER_SZ];

void inserirCaptura(){
	int verificarCap;
	int verificarInd;

	do{
		inserirDado("ID Captura: ",capturaReg[posVet].idCaptura);
		verificarCap = buscarCaptura(capturaReg[posVet].idCaptura);
		insiraDiferente(verificarCap);
	} while (verificarCap!=-1);

	int idCap = atoi(capturaReg[posVet].idCaptura);
	sprintf(capturaReg[posVet].idCaptura,"%d",idCap);

	do{
		inserirDado("ID Indivíduo: ",capturaReg[posVet].idIndividuo);
		verificarInd = buscarIndividuo(capturaReg[posVet].idIndividuo);
		insiraIgual(verificarInd);
	} while (verificarInd==-1);

	int idInd = atoi(capturaReg[posVet].idIndividuo);
	sprintf(capturaReg[posVet].idIndividuo,"%d",idInd);

	do{
		inserirDado("Comprimento : ",capturaReg[posVet].comprimento);
	} while (atoi(capturaReg[posVet].comprimento)==0);

	int compr = atoi(capturaReg[posVet].comprimento);
	sprintf(capturaReg[posVet].comprimento,"%d",compr);

	do{
		inserirDado("Largura: ",capturaReg[posVet].largura);
	} while (atoi(capturaReg[posVet].largura)==0);

	int larg = atoi(capturaReg[posVet].largura);
	sprintf(capturaReg[posVet].largura,"%d",larg);

	do{
		inserirDado("Peso: ",capturaReg[posVet].peso);
	} while (atoi(capturaReg[posVet].peso)==0);

	int peso = atoi(capturaReg[posVet].peso);
	sprintf(capturaReg[posVet].peso,"%d",peso);

	inserirDado("Data: ",capturaReg[posVet].data);
	inserirDado("Local: ",capturaReg[posVet].local);

	posVet++;
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
