#ifndef PISTA_H
#define PISTA_H

#include "fila.h"

#define MAXPISTAS 20

typedef struct {
    int id;
    char nome[80];
    float comprimento;
    char superficie[40];
    Fila fila;
} Pista;

extern Pista pistas[MAXPISTAS];
extern int totalpistas;

void cadastrar_pista();
void listar_pistas();
void ver_pista();
void editar_pista();
void remover_pista();
Pista *buscar_pista(int id);
void exibir_pista(Pista *pista);
void liberar_pistas();

#endif
