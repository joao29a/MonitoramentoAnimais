#include <stdlib.h>
#include <string.h>
#include "hdr/removerLinha.h"

char* removerLinha(char *palavra){
	int tamanho=strlen(palavra);
	if (tamanho > 0 && palavra[tamanho-1]=='\n')
		palavra[tamanho-1]='\0';
	return palavra;
}
