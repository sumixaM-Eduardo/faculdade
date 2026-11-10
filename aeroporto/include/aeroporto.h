#ifndef AEROPORTO_H
#define AEROPORTO_H

typedef struct {
    int id;
    char nome[80];
    char iata[10];
    char tipo[15];
    int capacidade;
    int qtdavioes;
    int qtdpistas;
    int cadastrado;
} Aeroporto;

extern Aeroporto aeroporto;

void cadastrar_aeroporto();
void ver_aeroporto();

#endif
