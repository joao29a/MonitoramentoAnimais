#include <stdio.h>
#include <stdlib.h>
#include "../hdr/menuInserir.h"
#include "../hdr/especie.h"
#include "../hdr/individuo.h"
#include "../hdr/captura.h"

void opcaoInserir(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			inserirEspecie();
			break;
		case 2:
			inserirIndividuo();
			break;
		case 3:
			inserirCaptura();
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

void menuInserir(){
	system("clear");
	int opcao=-1;
	while (opcao!=0){
		printf("Sistema de informação para monitoramento de animais silvestres.\n");
		printf("### Inserir ###\n");
		printf("1 - Especie\n");
		printf("2 - Indivíduo\n");
		printf("3 - Captura\n");
		printf("0 - Voltar\n");
		printf("Opção: ");
		scanf("%d",&opcao);
		opcaoInserir(opcao);
	}
}
