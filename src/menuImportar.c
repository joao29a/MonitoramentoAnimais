#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuImportar.h"
#include "hdr/functions.h"

void opcaoImportar(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Importar Captura ###\n");
			printf("Anexando...");
			anexarFinal();
			printf(" Finalizado.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Importar Captura ###\n");
			printf("Reescrevendo...");
			reescreverCaptura();
			printf(" Finalizado.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 0:
			printf("Voltando...\n");
			break;
		default:
			printf("Opção inválida, insira novamente...\n");
			break;	
	}
}

void menuImportar(){
	system("clear");
	int opcao;
	do{
		opcao=-1;
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("### Importar Captura ###\n");
		printf("1 - Anexar no final do arquivo.\n");
		printf("2 - Reescrever arquivo.\n");
		printf("0 - Voltar\n");
		printf("Opção: ");
		char option[BUFFER_SZ];
		fgets(option,BUFFER_SZ,stdin);
		sscanf(option,"%d",&opcao);
		opcaoImportar(opcao);
	} while (opcao!=0);
}
