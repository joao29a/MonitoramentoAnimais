#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hdr/menuPrincipal.h"

char *pastaEspecie = "EspecieArq";
char *especie = "especie.txt";
char *especiePos = "especiePos.txt";

char *pastaIndividuo = "IndividuoArq";
char *individuo = "individuo.txt";

char *pastaCaptura = "CapturaArq";
char *captura = "captura.data";


void verificarArquivo(char *pasta, char *txt){
	char buffer[256];
	strcpy(buffer,pasta);
	strcat(buffer,"/");
	strcat(buffer,txt);
	FILE *arquivo=fopen(buffer,"r");
	if (arquivo==NULL)
		arquivo=fopen(buffer,"w");
	fclose(arquivo);
}

void verificarPasta(char* pastaNome){
	struct stat st;
	if (stat(pastaNome, &st) == -1)
    		mkdir(pastaNome, 0777);	
}

void verificarEspecie(){
	verificarPasta(pastaEspecie);
	verificarArquivo(pastaEspecie,especie);
	verificarArquivo(pastaEspecie,especiePos);
}

void verificarIndividuo(){
	verificarPasta(pastaIndividuo);
	verificarArquivo(pastaIndividuo,individuo);
	//verificarArquivo(pastaEspecie,especiePos);
}

void verificarCaptura(){
	verificarPasta(pastaCaptura);
	verificarArquivo(pastaCaptura,captura);
	//verificarArquivo(pastaEspecie,especiePos);
}


int main(){
	verificarEspecie();
	//verificarIndividuo();
	//verificarCaptura();
	menuPrincipal();
	return 0;
}
