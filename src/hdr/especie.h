#ifndef ESPECIE_H
#define ESPECIE_H

typedef struct especie{
	int identificadorEspecie;
	char *nomeCientifico;
	char *nomePopular;
	char *descricao;
}Especie;

//extern char *arqEspecie;

#define MAX 1024

//registros de tamanho váriavel.
void inserirEspecie();

void buscarEspecie(); //ID

void removerEspecie();

#endif
