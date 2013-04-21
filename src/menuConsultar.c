#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuConsultar.h"
#include "hdr/functions.h"


void opcaoHistorico(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			//listarIndividuo();
			break;
		case 2:
			//listarEspecie();
			break;
		case 0:
			printf("Voltando...\n");
			break;
		default:
			printf("Opção inválida, insira novamente...\n");
			break;	
	}
}

void historicoMonitoramento(){
	system("clear");
	int opcao;
	do{
		opcao=-1;
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("### Histórico de Monitoramento ###\n");
		printf("1 - Indivíduo.\n");
		printf("2 - Espécie.\n");
		printf("0 - Voltar\n");
		printf("Opção: ");
		char option[BUFFER_SZ];
		fgets(option,BUFFER_SZ,stdin);
		sscanf(option,"%d",&opcao);
		opcaoHistorico(opcao);
	} while (opcao!=0);
}

void opcaoConsultar(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			historicoMonitoramento();
			break;
		case 2:
			//ultimaCaptura();
			break;
		case 0:
			printf("Voltando...\n");
			break;
		default:
			printf("Opção inválida, insira novamente...\n");
			break;	
	}
}

void menuConsultar(){
	system("clear");
	int opcao;
	do{
		opcao=-1;
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("### Consultar ###\n");
		printf("1 - Histórico de monitoramento.\n");
		printf("2 - Dados da última captura.\n");
		printf("0 - Voltar\n");
		printf("Opção: ");
		char option[BUFFER_SZ];
		fgets(option,BUFFER_SZ,stdin);
		sscanf(option,"%d",&opcao);
		opcaoConsultar(opcao);
	} while (opcao!=0);
}
