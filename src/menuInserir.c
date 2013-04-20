#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuInserir.h"
#include "hdr/menuImportar.h"
#include "hdr/especie.h"
#include "hdr/individuo.h"
#include "hdr/captura.h"
#include "hdr/functions.h"

void opcaoInserir(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Inserir Espécie ###\n");
			inserirEspecie();
			printf("\nDados inseridos com sucesso, pressione enter para continuar...");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Inserir Indivíduo ###\n");
			if (verificar_qtd_especie()){
				inserirIndividuo();
				printf("\nDados inseridos com sucesso, pressione enter para continuar...");
			} else
				printf("Insira espécie antes para adicionar algum indivíduo...");
			while (getchar()!='\n');
			system("clear");
			break;
		case 3:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Inserir Captura ###\n");
			if (verificar_qtd_individuo())
				inserirCaptura();
			else
				printf("Insira indivíduo antes para adicionar alguma captura...");
			while (getchar()!='\n');
			system("clear");
			break;
		case 4:
			menuImportar();
			break;
		case 0:
			printf("Voltando...\n");
			break;
		default:
			printf("Opção inválida, insira novamente...\n");
			break;	
	}
}

void menuInserir(){
	system("clear");
	int opcao;
	do{
		opcao = -1;
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("### Inserir ###\n");
		printf("1 - Espécie\n");
		printf("2 - Indivíduo\n");
		printf("3 - Captura\n");
		printf("4 - Importar Capturas\n");
		printf("0 - Voltar\n");
		printf("Opção: ");
		char option[BUFFER_SZ];
		fgets(option,BUFFER_SZ,stdin);
		sscanf(option,"%d",&opcao);
		opcaoInserir(opcao);
	} while (opcao!=0);
}
