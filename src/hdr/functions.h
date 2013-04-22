#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define BUFFER_SZ 1024
#define TAM_REG 50

#define arquivos "Arquivos/"

#define pastaEspecie arquivos"EspecieArq/"
#define especie pastaEspecie"especie.txt"
#define especiePos pastaEspecie"especiePos.txt"

#define pastaIndividuo arquivos"IndividuoArq/"
#define individuo pastaIndividuo"individuo.txt"

#define pastaCaptura arquivos"CapturaArq/"
#define captura pastaCaptura"captura.dat"
#define capturaPos pastaCaptura"capturaPos.txt"
#define capturatxt pastaCaptura"captura.txt"

void inserirDado(char *tipo, char *dado);

void imprimirDado(int pos, char *tipoArq, char *tipoTxt);

FILE* abrirArquivo(char *nomeArquivo, char *tipo);

void verificarArquivo(char *txt);

void verificarPasta(char* pastaNome);

void insiraIgual(int id);

void insiraDiferente(int id);

void verificarEspecie();

void verificarIndividuo();

void verificarCaptura();

int verificar_qtd_especie();

int verificar_qtd_individuo();

int verificar_individuo_removido(FILE *arquivo);

void salvarPos(FILE *arquivo, int pos);

void escreverCaptura(FILE *arquivo, FILE *arquivoPos);

void anexarFinal();

void reescreverCaptura();

#endif
