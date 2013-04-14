#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuPrincipal.h"
#include "hdr/menuInserir.h"
#include "hdr/menuBuscar.h"
#include "hdr/menuRemover.h"
#include "hdr/functions.h"

void opcaoPrincipal(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			menuInserir();
			break;
		case 2:
			menuBuscar();
			break;
		case 3:
			menuRemover();
			break;
		case 0:
			printf("Saindo...\n");
			break;
		default:
			printf("Opção inválida, insira novamente...\n");
			//while (getchar()!='\n');
			break;	
	}
}

void menuPrincipal(){
	system("clear");
	int opcao;
	do{
		opcao=-1;
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("1 - Inserir\n");
		printf("2 - Buscar\n");
		printf("3 - Remover\n");
		printf("0 - Sair\n");
		printf("Opção: ");
		char option[BUFFER_SZ];
		fgets(option,BUFFER_SZ,stdin);
		sscanf(option,"%d",&opcao);
		opcaoPrincipal(opcao);
	} while (opcao!=0);
}
