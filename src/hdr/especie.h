#ifndef ESPECIE_H
#define ESPECIE_H

typedef struct especie{
	int identificadorEspecie;
	char *nomeCientifico;
	char *nomePopular;
	char *descricao;
}Especie;

//extern char *arqEspecie;

void inserirDado(char *tipo, char *dado);

void imprimirEspecie(int pos);

FILE* abrirArquivoEspecie(char *tipo);

FILE* abrirArquivoPosEspecie(char *tipo);

//registros de tamanho váriavel.
void inserirEspecie();

int buscarEspecie(); //ID

void removerEspecie();

#endif
