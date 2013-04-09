#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../hdr/menuRemover.h"
#include "../hdr/especie.h"
#include "../hdr/individuo.h"
#include "../hdr/captura.h"
#include "../hdr/buffer.h"

void opcaoRemover(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			printf("Sistema de informação para monitoramento de animais silvestres.\n");
			printf("### Remover Espécie ###\n");
			removerEspecie();
			printf("\nPressione enter para voltar...");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			removerIndividuo();
			break;
		case 3:
			removerCaptura();
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

void menuRemover(){
	system("clear");
	int opcao=-1;
	while (opcao!=0){
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("### Remover ###\n");
		printf("1 - Espécie\n");
		printf("2 - Indivíduo\n");
		printf("3 - Captura\n");
		printf("0 - Voltar\n");
		printf("Opção: ");
		char option[BUFFER_SZ];
		fgets(option,BUFFER_SZ,stdin);
		sscanf(option,"%[^\n]",option);
		if (strlen(option) == 1)
			opcao = atoi(option);
		else
			opcao = -1;
		opcaoRemover(opcao);
	}
}
