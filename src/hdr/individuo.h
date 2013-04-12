#ifndef INDIVIDUO_H
#define INDIVIDUO_H

typedef struct individuo{
	int identificadorEspecie;
	int identificadorIndividuo;
	char sexo;
}Individuo;

//registros de tamanho fixo.

void inserirIndividuo();

int buscarIndividuo();

void removerIndividuo();

#endif
