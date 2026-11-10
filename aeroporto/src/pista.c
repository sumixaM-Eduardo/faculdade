#include <stdio.h>
#include "pista.h"
#include "menu.h"

Pista pistas[MAXPISTAS];
int totalpistas = 0;

Pista *buscar_pista(int id) {
    for (int i = 0; i < totalpistas; i++) {
        if (pistas[i].id == id) {
            return &pistas[i];
        }
    }
    return NULL;
}

void exibir_pista(Pista *pista) {
    if (pista == NULL) {
        printf("[!] Pista nao encontrada.\n");
        return;
    }
    printf("ID: %d\n", pista->id);
    printf("Nome: %s\n", pista->nome);
    printf("Comprimento: %.1f metros\n", pista->comprimento);
    printf("Superficie: %s\n", pista->superficie);
    printf("Avioes em espera: %d\n", pista->fila.qtd);
}

void cadastrar_pista() {
    Pista nova = {0};
    exibir_cabecalho("CADASTRAR PISTA");
    if (totalpistas >= MAXPISTAS) {
        printf("[!] Limite de %d pistas atingido.\n", MAXPISTAS);
        return;
    }

    nova.id = ler_num("ID da pista: ");
    if (nova.id <= 0 || buscar_pista(nova.id) != NULL) {
        printf("[!] ID invalido ou ja cadastrado.\n");
        return;
    }

    ler_texto("Nome: ", nova.nome, 80);
    nova.comprimento = ler_decimal("Comprimento em metros: ");
    ler_texto("Superficie: ", nova.superficie, 40);
    if (nova.comprimento <= 0) {
        printf("[!] Comprimento invalido.\n");
        return;
    }

    nova.fila.inicio = NULL;
    nova.fila.fim = NULL;
    nova.fila.qtd = 0;
    pistas[totalpistas] = nova;
    totalpistas++;
    printf("[+] Pista cadastrada!\n");
}

void listar_pistas() {
    exibir_cabecalho("PISTAS CADASTRADAS");
    if (totalpistas == 0) {
        printf("[!] Nenhuma pista cadastrada.\n");
        return;
    }
    for (int i = 0; i < totalpistas; i++) {
        exibir_pista(&pistas[i]);
        linha();
    }
}

void ver_pista() {
    int id;
    exibir_cabecalho("CONSULTAR PISTA");
    id = ler_num("ID da pista: ");
    exibir_pista(buscar_pista(id));
}

void editar_pista() {
    int id;
    Pista *pista;
    Pista copia;

    exibir_cabecalho("ATUALIZAR PISTA");
    id = ler_num("ID da pista: ");
    pista = buscar_pista(id);
    if (pista == NULL) {
        printf("[!] Pista nao encontrada.\n");
        return;
    }

    copia = *pista;
    ler_texto("Novo nome: ", copia.nome, 80);
    copia.comprimento = ler_decimal("Novo comprimento: ");
    ler_texto("Nova superficie: ", copia.superficie, 40);
    if (copia.comprimento > 0) {
        *pista = copia;
        printf("[+] Pista atualizada!\n");
    } else {
        printf("[!] Comprimento invalido.\n");
    }
}

void remover_pista() {
    int id;
    exibir_cabecalho("REMOVER PISTA");
    id = ler_num("ID da pista: ");

    for (int i = 0; i < totalpistas; i++) {
        if (pistas[i].id == id) {
            if (pistas[i].fila.qtd > 0) {
                printf("[!] Esta pista ainda tem avioes aguardando.\n");
                return;
            }

            for (int j = i; j < totalpistas - 1; j++) {
                pistas[j] = pistas[j + 1];
            }
            totalpistas--;
            printf("[+] Pista removida!\n");
            return;
        }
    }
    printf("[!] Pista nao encontrada.\n");
}

void liberar_pistas() {
    for (int i = 0; i < totalpistas; i++) {
        liberar_fila(&pistas[i].fila);
    }
}
