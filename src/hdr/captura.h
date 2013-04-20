#ifndef CAPTURAINDIVIDUO_H
#define CAPTURAINDIVIDUO_H

#include "functions.h"

typedef struct capturaIndividuo{
	char idCaptura[BUFFER_SZ];
	char idIndividuo[BUFFER_SZ];
	char comprimento[BUFFER_SZ];
	char largura[BUFFER_SZ];
	char peso[BUFFER_SZ];
	char data[BUFFER_SZ];
	char local[BUFFER_SZ];
}Captura;

extern int posVet;

extern int inicio;

extern Captura capturaReg[BUFFER_SZ];

void inserirCaptura();

int buscarCaptura(char *id);

void removerCaptura();

#endif
