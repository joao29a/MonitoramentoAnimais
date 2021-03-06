#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/individuo.h"
#include "hdr/especie.h"
#include "hdr/functions.h"

void inserirIndividuo(){
	char idIndividuo[BUFFER_SZ];
	char idEspecie[BUFFER_SZ];
	char sexo[BUFFER_SZ];

	int verificarId;
	do{
		inserirDado("ID Indivíduo: ",idIndividuo);
		verificarId = buscarIndividuo(idIndividuo);
		insiraDiferente(verificarId);
	} while (verificarId!=-1);

	int idNumberInd = atoi (idIndividuo);
	sprintf(idIndividuo,"%d",idNumberInd);

	do{
		inserirDado("ID Espécie: ",idEspecie);
		verificarId = buscarEspecie(idEspecie);
		insiraIgual(verificarId);
	} while (verificarId==-1);

	int idNumberEsp = atoi(idEspecie);
	sprintf(idEspecie,"%d",idNumberEsp);
	
	int encontrou;
	do{
		encontrou = 0;
		inserirDado("Sexo: ",sexo);
		if (strlen(sexo) == 1){
			int a = sexo[0];
			if (a == 77 || a == 70 || a == 102 || a == 109)
				encontrou = 1;
		}
	} while (strlen(sexo) > 1 || !encontrou);

	FILE *arquivo = abrirArquivo(individuo,"r+");
	fseek(arquivo,verificar_individuo_removido(arquivo),SEEK_SET);
	
	char dados[BUFFER_SZ];
	strcpy(dados,"id indivíduo = ");
	strcat(dados,idIndividuo);
	strcat(dados,"\n");
	
	strcat(dados,"id espécie = ");
	strcat(dados,idEspecie);
	strcat(dados,"\n");
	
	strcat(dados,"sexo = ");
	strcat(dados,sexo);
	strcat(dados,"\n");

	strcat(dados,"#\n");
	fwrite(dados,1,TAM_REG,arquivo);

	fclose(arquivo);
}

int buscarIndividuo(char *id){
	FILE *arquivo = abrirArquivo(individuo,"r");

	int idNumber = atoi(id);
	
	char linha[BUFFER_SZ];
	int somaPos=0;
	while (fgets(linha,BUFFER_SZ,arquivo)!=NULL){
		int idArq = -1;
		sscanf(linha,"%*[^0-9] %d",&idArq);
		if (idNumber == idArq){
			fclose(arquivo);
			return somaPos;
		}
		somaPos+=TAM_REG;
		fseek(arquivo,somaPos,SEEK_SET);
	}
	fclose(arquivo);
	return -1;
}

void removerIndividuo(){
	char id[BUFFER_SZ];
	inserirDado("ID Indivíduo: ",id);
	int pos = buscarIndividuo(id);
	char *removed="-";
	if (pos!=-1){
		FILE *arquivo = abrirArquivo(individuo,"r+");
		fseek(arquivo,pos,SEEK_SET);
		char linha[BUFFER_SZ];
		
		fgets(linha,BUFFER_SZ,arquivo);
		
		int posArq = ftell(arquivo);
		posArq-=2;
		fseek(arquivo,posArq,SEEK_SET);
		fwrite(removed,1,1,arquivo);
		printf("Indivíduo removido!\n");
		fclose(arquivo);
	}
	else printf("Indivíduo não encontrado(a)\n");
}
