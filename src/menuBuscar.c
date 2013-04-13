#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuBuscar.h"
#include "hdr/especie.h"
#include "hdr/individuo.h"
#include "hdr/captura.h"
#include "hdr/manipular.h"

void opcaoBuscar(int escolha){
	system("clear");
	char id[BUFFER_SZ];
	switch(escolha){
		case 1:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Buscar Espécie ###\n");
			inserirDado("ID: ",id);
			imprimirDado(buscarEspecie(id),especie,"Espécie");
			printf("\nBusca concluída, pressione enter para voltar...");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Buscar Indivíduo ###\n");
			inserirDado("ID: ",id);
			imprimirDado(buscarIndividuo(id),individuo,"Indivíduo");
			printf("\nBusca concluída, pressione enter para voltar...");
			while (getchar()!='\n');
			system("clear");
			break;
		case 3:
			buscarCaptura();
			break;
		case 0:
			printf("Voltando...\n");
			break;
		default:
			printf("Opção inválida, insira novamente...\n");
			//while (getchar()!='\n');
			break;	
	}
}

void menuBuscar(){
	system("clear");
	int opcao;
	do{
		opcao = -1;
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("### Buscar ###\n");
		printf("1 - Espécie\n");
		printf("2 - Indivíduo\n");
		printf("3 - Captura\n");
		printf("0 - Voltar\n");
		printf("Opção: ");
		char option[BUFFER_SZ];
		fgets(option,BUFFER_SZ,stdin);
		sscanf(option,"%d",&opcao);
		opcaoBuscar(opcao);
	} while (opcao!=0);
}
