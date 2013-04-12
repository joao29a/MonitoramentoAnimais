#ifndef MANIPULAR_H
#define MANIPULAR_H

#include <stdio.h>

#define BUFFER_SZ 1024
#define TAM_REG 50

#define pastaEspecie "EspecieArq/"
#define especie pastaEspecie"especie.txt"
#define especiePos pastaEspecie"especiePos.txt"

#define pastaIndividuo "IndividuoArq/"
#define individuo pastaIndividuo"individuo.txt"

#define pastaCaptura "CapturaArq/"
#define captura pastaCaptura"captura.dat"

void inserirDado(char *tipo, char *dado);

void imprimirDado(int pos, char *tipoArq, char *tipoTxt);

FILE* abrirArquivo(char *nomeArquivo, char *tipo);

void verificarArquivo(char *txt);

void verificarPasta(char* pastaNome);

void verificarEspecie();

void verificarIndividuo();

void verificarCaptura();

#endif
