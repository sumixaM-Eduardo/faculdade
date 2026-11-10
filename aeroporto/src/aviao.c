#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"
#include "fila.h"
#include "menu.h"

Aviao *avioes = NULL;
int totalavioes = 0;

Aviao *buscar_aviao(int id) {
    Aviao *aux = avioes;
    while (aux != NULL) {
        if (aux->id == id) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void exibir_aviao(Aviao *aviao) {
    if (aviao == NULL) {
        printf("[!] Aviao nao encontrado.\n");
        return;
    }
    printf("ID: %d\n", aviao->id);
    printf("Nome: %s\n", aviao->nome);
    printf("Modelo: %s\n", aviao->modelo);
    printf("Fabricante: %s\n", aviao->fabricante);
    printf("Codigo do voo: %s\n", aviao->voo);
    printf("Passageiros maximos: %d\n", aviao->passageiros);
    printf("Velocidade maxima: %.1f km/h\n", aviao->velocidade);
}

void cadastrar_aviao() {
    int id;
    Aviao *novoaviao;

    exibir_cabecalho("CADASTRAR AVIAO");
    id = ler_num("ID do aviao: ");
    if (id <= 0 || buscar_aviao(id) != NULL) {
        printf("[!] ID invalido ou ja cadastrado.\n");
        return;
    }

    novoaviao = malloc(sizeof(Aviao));
    if (novoaviao == NULL) {
        printf("[!] Erro ao reservar memoria.\n");
        return;
    }

    novoaviao->id = id;
    ler_texto("Nome: ", novoaviao->nome, 80);
    ler_texto("Modelo: ", novoaviao->modelo, 60);
    ler_texto("Fabricante: ", novoaviao->fabricante, 60);
    ler_texto("Codigo do voo: ", novoaviao->voo, 20);
    novoaviao->passageiros = ler_num("Quantidade maxima de passageiros: ");
    novoaviao->velocidade = ler_decimal("Velocidade maxima (km/h): ");

    if (novoaviao->passageiros < 0 || novoaviao->velocidade <= 0) {
        printf("[!] Quantidade ou velocidade invalida.\n");
        free(novoaviao);
        return;
    }

    novoaviao->prox = avioes;
    avioes = novoaviao;
    totalavioes++;
    printf("[+] Aviao cadastrado!\n");
}

void listar_avioes() {
    Aviao *aux = avioes;
    exibir_cabecalho("AVIOES CADASTRADOS");
    if (aux == NULL) {
        printf("[!] Nenhum aviao cadastrado.\n");
        return;
    }

    while (aux != NULL) {
        exibir_aviao(aux);
        linha();
        aux = aux->prox;
    }
    printf("Total de avioes: %d\n", totalavioes);
}

void ver_aviao() {
    int id;
    exibir_cabecalho("CONSULTAR AVIAO");
    id = ler_num("Informe o ID: ");
    exibir_aviao(buscar_aviao(id));
}

void editar_aviao() {
    int id;
    Aviao *aviao;
    Aviao copia;

    exibir_cabecalho("ATUALIZAR AVIAO");
    id = ler_num("ID do aviao: ");
    aviao = buscar_aviao(id);
    if (aviao == NULL) {
        printf("[!] Aviao nao encontrado.\n");
        return;
    }

    copia = *aviao;
    ler_texto("Novo nome: ", copia.nome, 80);
    ler_texto("Novo modelo: ", copia.modelo, 60);
    ler_texto("Novo fabricante: ", copia.fabricante, 60);
    ler_texto("Novo codigo do voo: ", copia.voo, 20);
    copia.passageiros = ler_num("Nova qtd maxima: ");
    copia.velocidade = ler_decimal("Nova velocidade maxima: ");
    if (copia.passageiros >= 0 && copia.velocidade > 0) {
        *aviao = copia;
        printf("[+] Aviao atualizado!\n");
    } else {
        printf("[!] Quantidade ou velocidade invalida.\n");
    }
}

void remover_aviao() {
    int id;
    Aviao *aux = avioes;
    Aviao *ant = NULL;

    exibir_cabecalho("REMOVER AVIAO");
    id = ler_num("ID do aviao: ");

    if (esta_na_fila(id) == 1) {
        printf("[!] O aviao esta esperando em uma pista.\n");
        return;
    }

    while (aux != NULL && aux->id != id) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("[!] Aviao nao encontrado.\n");
        return;
    }

    if (ant == NULL) {
        avioes = aux->prox;
    } else {
        ant->prox = aux->prox;
    }
    free(aux);
    totalavioes--;
    printf("[+] Aviao removido!\n");
}

void liberar_avioes() {
    Aviao *aux = avioes;
    while (aux != NULL) {
        Aviao *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    avioes = NULL;
    totalavioes = 0;
}
