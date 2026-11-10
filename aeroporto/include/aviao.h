#ifndef AVIAO_H
#define AVIAO_H

typedef struct Aviao {
    int id;
    char nome[80];
    char modelo[60];
    char fabricante[60];
    char voo[20];
    int passageiros;
    float velocidade;
    struct Aviao *prox;
} Aviao;

extern Aviao *avioes;
extern int totalavioes;

void cadastrar_aviao();
void listar_avioes();
void ver_aviao();
void editar_aviao();
void remover_aviao();
Aviao *buscar_aviao(int id);
void exibir_aviao(Aviao *aviao);
void liberar_avioes();

#endif
