#include <string.h>
#include <stdlib.h>
#include "hdr/consultas.h"
#include "hdr/functions.h"
#include "hdr/individuo.h"
#include "hdr/especie.h"

void listarIndividuo(){
	char id[BUFFER_SZ];
	int verificarId;
	do {
		inserirDado("ID: ",id);
		verificarId = buscarIndividuo(id);
		insiraIgual(verificarId);
	} while (verificarId == -1);

	FILE *arquivo = abrirArquivo(individuo,"r");
	fseek(arquivo,verificarId,SEEK_SET);
	
	int idIndividuo;
	char linha[BUFFER_SZ];
	fgets(linha,BUFFER_SZ,arquivo);
	sscanf(linha,"%*[^0-9] %d",&idIndividuo);

	fclose(arquivo);

	arquivo = abrirArquivo(captura,"r");
	FILE *arquivoPos = abrirArquivo(capturaPos,"r");
	while (fgets(linha,BUFFER_SZ,arquivoPos)!=NULL){
		int pos;
		char removido[BUFFER_SZ];
		sscanf(linha,"%d %s",&pos,removido);
		fseek(arquivo,pos,SEEK_SET);
		fgets(linha,BUFFER_SZ,arquivo);
		fgets(linha,BUFFER_SZ,arquivo);
		int idArquivo;
		sscanf(linha,"%*[^0-9] %d",&idArquivo);
		if (idIndividuo==idArquivo && strcmp(removido,"#REMOVIDO#")!=0){
			imprimirDado(pos,captura,"Captura");
			printf("\n");
		}
	}
	fclose(arquivo);
	fclose(arquivoPos);
}

void listarEspecie(){
	char id[BUFFER_SZ];
	int verificarId;
	do{
		inserirDado("ID: ",id);
		verificarId = buscarEspecie(id);
		insiraIgual(verificarId);
	} while (verificarId == -1);

	char linha[BUFFER_SZ];

	FILE *arquivo = abrirArquivo(individuo,"r");

	int vetorId[BUFFER_SZ];
	int tamanho = 0;
	int somaPos=0;

	while (fgets(linha,BUFFER_SZ,arquivo)!=NULL){
		int idArq = -1;
		sscanf(linha,"%*[^0-9] %d",&idArq);
		if (idArq!=-1){
			fgets(linha,BUFFER_SZ,arquivo);
			int idEsp;
			sscanf(linha,"%*[^0-9] %d",&idEsp);
			if (verificarId == idEsp)
				vetorId[tamanho++]=idArq;
		}
		somaPos+=TAM_REG;
		fseek(arquivo,somaPos,SEEK_SET);
	}
	fclose(arquivo);

	arquivo = abrirArquivo(captura,"r");
	FILE *arquivoPos = abrirArquivo(capturaPos,"r");
	
	while (fgets(linha,BUFFER_SZ,arquivoPos)!=NULL){
		int pos;
		char removido[BUFFER_SZ];
		sscanf(linha,"%d %s",&pos,removido);
		fseek(arquivo,pos,SEEK_SET);
		fgets(linha,BUFFER_SZ,arquivo);
		fgets(linha,BUFFER_SZ,arquivo);
		int idArquivo;
		sscanf(linha,"%*[^0-9] %d",&idArquivo);
		for(int i=0;i<tamanho;i++){
			if (vetorId[i]==idArquivo && strcmp(removido,"#REMOVIDO#")!=0){
				imprimirDado(pos,captura,"Captura");
				printf("\n");
			}
		}	
	}
	fclose(arquivo);
	fclose(arquivoPos);
}

void ultimaCaptura(){
	char id[BUFFER_SZ];
	int verificarId;
	do{
		inserirDado("ID: ",id);
		verificarId = buscarIndividuo(id);
		insiraIgual(verificarId);
	} while (verificarId == -1);
	
	int idInd = atoi(id);

	FILE *arquivo = abrirArquivo(captura,"r");
	FILE *arquivoPos = abrirArquivo(capturaPos,"r");
	
	int finalPos = -1;

	char linha[BUFFER_SZ];
	while (fgets(linha,BUFFER_SZ,arquivoPos)!=NULL){
		int pos;
		int idIndArq;
		char removido[BUFFER_SZ];
		sscanf(linha,"%d %s",&pos,removido);
		if (strcmp(removido,"#INSERIDO#")==0){
			fseek(arquivo,pos,SEEK_SET);
			fgets(linha,BUFFER_SZ,arquivo);
			fgets(linha,BUFFER_SZ,arquivo);
			sscanf(linha,"%*[^0-9] %d",&idIndArq);
			if (idInd == idIndArq)
				finalPos = pos;
		}

	}
	fclose(arquivoPos);

	imprimirDado(finalPos,captura,"Captura");

	fclose(arquivo);
}
