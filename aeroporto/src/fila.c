#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pista.h"
#include "aviao.h"
#include "menu.h"

int esta_na_fila(int id) {
    for (int i = 0; i < totalpistas; i++) {
        No *aux = pistas[i].fila.inicio;
        while (aux != NULL) {
            if (aux->idaviao == id) {
                return 1;
            }
            aux = aux->prox;
        }
    }
    return 0;
}

void adicionar_fila() {
    int idpista, idaviao;
    Pista *pista;
    No *novo;

    exibir_cabecalho("ADICIONAR AVIAO NA FILA");
    idpista = ler_num("ID da pista: ");
    pista = buscar_pista(idpista);
    if (pista == NULL) {
        printf("[!] Pista nao encontrada.\n");
        return;
    }

    idaviao = ler_num("ID do aviao: ");
    if (buscar_aviao(idaviao) == NULL) {
        printf("[!] Aviao nao encontrado.\n");
        return;
    }
    if (esta_na_fila(idaviao) == 1) {
        printf("[!] Este aviao ja esta em uma fila.\n");
        return;
    }

    novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("[!] Erro ao reservar memoria.\n");
        return;
    }
    novo->idaviao = idaviao;
    novo->prox = NULL;

    if (pista->fila.inicio == NULL) {
        pista->fila.inicio = novo;
    } else {
        pista->fila.fim->prox = novo;
    }
    pista->fila.fim = novo;
    pista->fila.qtd++;
    printf("[+] Aviao adicionado na fila da pista %d.\n", idpista);
}

void listar_fila() {
    int id, posicao = 1;
    Pista *pista;
    No *aux;

    exibir_cabecalho("LISTAR FILA DA PISTA");
    id = ler_num("ID da pista: ");
    pista = buscar_pista(id);
    if (pista == NULL) {
        printf("[!] Pista nao encontrada.\n");
        return;
    }
    aux = pista->fila.inicio;
    if (aux == NULL) {
        printf("[!] A fila esta vazia.\n");
        return;
    }

    while (aux != NULL) {
        Aviao *aviao = buscar_aviao(aux->idaviao);
        if (aviao != NULL) {
            printf("%d. ID %d - %s - Voo %s\n", posicao, aviao->id, aviao->nome, aviao->voo);
        }
        posicao++;
        aux = aux->prox;
    }
}

void total_fila_pista() {
    int id;
    Pista *pista;
    exibir_cabecalho("QUANTIDADE NA FILA");
    id = ler_num("ID da pista: ");
    pista = buscar_pista(id);
    if (pista == NULL) {
        printf("[!] Pista nao encontrada.\n");
        return;
    }
    printf("Avioes aguardando: %d\n", pista->fila.qtd);
}

void decolar() {
    int id;
    Pista *pista;
    No *sai;

    exibir_cabecalho("AUTORIZAR DECOLAGEM");
    id = ler_num("ID da pista: ");
    pista = buscar_pista(id);
    if (pista == NULL) {
        printf("[!] Pista nao encontrada.\n");
        return;
    }
    if (pista->fila.inicio == NULL) {
        printf("[!] Nao tem avioes nessa fila.\n");
        return;
    }

    sai = pista->fila.inicio;
    printf("[+] Decolagem autorizada para o aviao ID %d!\n", sai->idaviao);
    pista->fila.inicio = sai->prox;
    if (pista->fila.inicio == NULL) {
        pista->fila.fim = NULL;
    }
    free(sai);
    pista->fila.qtd--;
}

void ver_primeiro() {
    int id;
    Pista *pista;
    exibir_cabecalho("PRIMEIRO AVIAO DA FILA");
    id = ler_num("ID da pista: ");
    pista = buscar_pista(id);
    if (pista == NULL) {
        printf("[!] Pista nao encontrada.\n");
        return;
    }
    if (pista->fila.inicio == NULL) {
        printf("[!] A fila esta vazia.\n");
        return;
    }
    exibir_aviao(buscar_aviao(pista->fila.inicio->idaviao));
}

void total_espera() {
    int total = 0;
    exibir_cabecalho("TOTAL DE AVIOES EM ESPERA");
    for (int i = 0; i < totalpistas; i++) {
        total += pistas[i].fila.qtd;
    }
    printf("Total de avioes aguardando: %d\n", total);
}

void liberar_fila(Fila *fila) {
    No *aux = fila->inicio;
    while (aux != NULL) {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtd = 0;
}
