#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuConsultar.h"
#include "hdr/functions.h"
#include "hdr/consultas.h"


void opcaoHistorico(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Histórico de Monitoramento - Individuo ###\n");
			if (verificar_qtd_individuo())
				listarIndividuo();
			else
				printf("Nenhum indivíduo inserido...\n");
			printf("\nPressione enter para voltar...");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Histórico de Monitoramento - Espécie ###\n");
			if (verificar_qtd_especie())
				listarEspecie();
			else
				printf("Nenhuma espécie inserida...\n");
			printf("\nPressione enter para voltar...");
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
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Última Captura - Indivíduo ###\n");
			if (verificar_qtd_individuo())
				ultimaCaptura();
			else
				printf("Nenhum indivíduo inserido...\n");
			printf("\nPressione enter para voltar...");
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
