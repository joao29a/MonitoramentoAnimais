#include <stdio.h>
#include <stdlib.h>
#include "../hdr/menuRemover.h"
#include "../hdr/especie.h"
#include "../hdr/individuo.h"
#include "../hdr/captura.h"

void opcaoRemover(int escolha){
	system("clear");
	switch(escolha){
		case 1:
			removerEspecie();
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
			while (getchar()!='\n');
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
		scanf("%d",&opcao);
		opcaoRemover(opcao);
	}
}
