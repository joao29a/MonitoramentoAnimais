#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hdr/menuPrincipal.h"

int main(){
	struct stat st;
	if (stat("EspecieArq", &st) == -1)
    		mkdir("EspecieArq", 0777);	
	FILE *arquivo=fopen("EspecieArq/especie.txt","r");
	if (arquivo==NULL){
		arquivo=fopen("EspecieArq/especie.txt","w");
		fclose(arquivo);
	}
	arquivo=fopen("EspecieArq/especiePos.txt","r");
	if (arquivo==NULL){
		arquivo=fopen("EspecieArq/especiePos.txt","w");
		fclose(arquivo);
	}
	menuPrincipal();
	return 0;
}
