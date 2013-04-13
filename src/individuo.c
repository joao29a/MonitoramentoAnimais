#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/individuo.h"
#include "hdr/manipular.h"

void inserirIndividuo(){
	char idEspecie[BUFFER_SZ];
	char idIndividuo[BUFFER_SZ];
	char sexo[BUFFER_SZ];

	inserirDado("ID Indivíduo: ",idEspecie);
	inserirDado("ID Espécie: ",idIndividuo);
	inserirDado("Sexo: ",sexo);

	FILE *arquivo = abrirArquivo(individuo,"r+");
	fseek(arquivo,0,SEEK_END);
	
	char dados[BUFFER_SZ];
	strcpy(dados,"id indivíduo = ");
	strcat(dados,idEspecie);
	strcat(dados,"\n");
	
	strcat(dados,"id espécie = ");
	strcat(dados,idIndividuo);
	strcat(dados,"\n");
	
	strcat(dados,"sexo = ");
	strcat(dados,sexo);
	strcat(dados,"\n");

	strcat(dados,"#\n");
	fwrite(dados,1,TAM_REG,arquivo);

	fclose(arquivo);
}

int buscarIndividuo(){
	char id[BUFFER_SZ];
	inserirDado("ID indivíduo: ",id);
	
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
	int pos = buscarIndividuo();
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
		fclose(arquivo);
	}
	else printf("Indivíduo não encontrado(a)\n");
}
