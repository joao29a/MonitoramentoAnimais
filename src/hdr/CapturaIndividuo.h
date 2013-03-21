#ifndef CAPTURAINDIVIDUO_H
#define CAPTURAINDIVIDUO_H

typedef struct capturaIndividuo{
	int identificadorIndividuo;
	int comprimento;
	int largura;
	int peso;
	int dataCaptura;
	char *localCaptura;
}Captura;

//registros de tamanho variável.

void inserirCaptura();

void buscarCaptura(); //ID

void removerCaptura();

#endif
