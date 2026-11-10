#ifndef FILA_H
#define FILA_H

typedef struct No {
    int idaviao;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int qtd;
} Fila;

void adicionar_fila();
void listar_fila();
void total_fila_pista();
void decolar();
void ver_primeiro();
void total_espera();
int esta_na_fila(int id);
void liberar_fila(Fila *fila);

#endif
