#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/especie.h"
#include "hdr/removerLinha.h"

void inserirEspecie(){
	char *id = malloc(sizeof(char)*MAX);
	char *nomeCientifico = malloc(sizeof(char)*MAX);
	char *nomePopular = malloc(sizeof(char)*MAX);
	char *descricao = malloc(sizeof(char)*MAX);

	getchar();

	printf("ID: ");
	fgets(id,MAX,stdin);

	printf("Nome científico: ");
	fgets(nomeCientifico,MAX,stdin);

	printf("Nome popular: ");
	fgets(nomePopular,MAX,stdin);
	
	printf("Descrição: ");
	fgets(descricao,MAX,stdin);
	
	id = removerLinha(id);
	nomeCientifico = removerLinha(nomeCientifico);
	nomePopular = removerLinha(nomePopular);
	descricao = removerLinha(descricao);

	FILE *arquivo = fopen("EspecieArq/especie.txt","r+");
	FILE *arquivoPos = fopen("EspecieArq/especiePos.txt","r+");
	fseek(arquivo,0,SEEK_END);
	fseek(arquivoPos,0,SEEK_END);
	int pos = ftell(arquivo);
	fprintf(arquivoPos,"%d\n",pos);
	fprintf(arquivo,"id = %s\nnome científico = %s\nnome popular = %s\ndescrição = %s\n#\n",id,nomeCientifico,nomePopular,descricao);
	fclose(arquivo);
	fclose(arquivoPos);

	free(id);
	free(nomeCientifico);
	free(nomePopular);
	free (descricao);
}

void buscarEspecie(){
	getchar();

	int id;
	printf("ID: ");
	scanf("%d",&id);
	
	FILE *arquivo = fopen("EspecieArq/especie.txt","r");
	FILE *arquivoPos = fopen("EspecieArq/especiePos.txt","r");
	int encontrou=0;
	char linha[MAX];
	while (fgets(linha,MAX,arquivoPos)!=NULL && !encontrou){
			int pos = atoi(linha);
			fseek(arquivo,pos,SEEK_SET);
			fgets(linha,MAX,arquivo);
			int idArquivo;
			sscanf(linha,"%*[^0-9] %d",&idArquivo);
			if (id==idArquivo){
				encontrou=1;
				linha[0]='\0';
				fgets(linha,MAX,arquivo);
				while (strcmp(linha,"#\n")!=0){
					printf("%s",linha);
					linha[0]='\0';
					fgets(linha,MAX,arquivo);
				}
			}
	}
	fclose(arquivo);
	fclose(arquivoPos);
}

void removerEspecie(){
}
