#include <stdio.h>
#include <stdlib.h>
#include "../hdr/menuBuscar.h"
#include "../hdr/especie.h"
#include "../hdr/individuo.h"
#include "../hdr/captura.h"

void opcaoBuscar(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Buscar Espécie ###\n");
			buscarEspecie();
			printf("Busca concluída, pressione enter para voltar...");
			while (getchar()!='\r' && getchar()!='\n');
			system("clear");
			break;
		case 2:
			buscarIndividuo();
			break;
		case 3:
			buscarCaptura();
			break;
		case 0:
			printf("Voltando...\n");
			break;
		default:
			printf("Opção inválida, insira novamente...\n");
			while (getchar()!='\n');
			break;	
	}
}

void menuBuscar(){
	system("clear");
	int opcao=-1;
	while (opcao!=0){
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("### Buscar ###\n");
		printf("1 - Espécie\n");
		printf("2 - Indivíduo\n");
		printf("3 - Captura\n");
		printf("0 - Voltar\n");
		printf("Opção: ");
		scanf("%d",&opcao);
		opcaoBuscar(opcao);
	}
}
