/*
Integrantes:
Maximus Eduardo Pacheco Cruz - 2025022558
Ryan Henrique Mendes Campos - 2025022450
Geovane Alexandre - 2025022333
*/

/*
Integrantes:
Maximus Eduardo Pacheco Cruz - 2025022558
Ryan Henrique Mendes Campos - 2025022450
Geovane Alexandre - 2025022333
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "aeroporto.h"
#include "aviao.h"
#include "pista.h"
#include "fila.h"

void linha() {
    printf("--------------------------------------------------\n");
}

void exibir_cabecalho(const char *titulo) {
    printf("\n==================================================\n");
    printf("            CONTROLE AEREO - UFAL\n");
    printf("                  %s\n", titulo);
    printf("==================================================\n");
}

int ler_num(const char *mensagem) {
    int valor;
    int c;
    printf("%s", mensagem);
    if (scanf("%d", &valor) != 1) {
        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("[!] Digite apenas numeros.\n");
        return -1;
    }
    while ((c = getchar()) != '\n' && c != EOF) { }
    return valor;
}

float ler_decimal(const char *mensagem) {
    float valor;
    int c;
    printf("%s", mensagem);
    if (scanf("%f", &valor) != 1) {
        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("[!] Numero invalido.\n");
        return -1;
    }
    while ((c = getchar()) != '\n' && c != EOF) { }
    return valor;
}

void ler_texto(const char *mensagem, char texto[], int tamanho) {
    int c;
    printf("%s", mensagem);
    if (fgets(texto, tamanho, stdin) == NULL) {
        texto[0] = '\0';
        return;
    }
    if (strchr(texto, '\n') != NULL) {
        texto[strcspn(texto, "\n")] = '\0';
    } else {
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

void menu_aeroporto() {
    int op;
    do {
        exibir_cabecalho("MENU AEROPORTO");
        printf("1. Cadastrar dados do aeroporto\n");
        printf("2. Visualizar informacoes\n");
        printf("0. Voltar\n");
        linha();
        op = ler_num("Escolha: ");

        switch (op) {
            case 1: cadastrar_aeroporto(); break;
            case 2: ver_aeroporto(); break;
            case 0: break;
            default: printf("[!] Opcao invalida.\n");
        }
    } while (op != 0);
}

void menu_avioes() {
    int op;
    do {
        exibir_cabecalho("MENU AVIOES");
        printf("1. Cadastrar aviao\n");
        printf("2. Listar todos os avioes\n");
        printf("3. Buscar aviao por ID\n");
        printf("4. Atualizar aviao\n");
        printf("5. Remover aviao\n");
        printf("0. Voltar\n");
        linha();
        op = ler_num("Escolha: ");

        switch (op) {
            case 1: cadastrar_aviao(); break;
            case 2: listar_avioes(); break;
            case 3: ver_aviao(); break;
            case 4: editar_aviao(); break;
            case 5: remover_aviao(); break;
            case 0: break;
            default: printf("[!] Opcao invalida.\n");
        }
    } while (op != 0);
}

void menu_pistas() {
    int op;
    do {
        exibir_cabecalho("MENU PISTAS");
        printf("1. Cadastrar pista\n");
        printf("2. Listar todas as pistas\n");
        printf("3. Buscar pista por ID\n");
        printf("4. Atualizar pista\n");
        printf("5. Remover pista\n");
        printf("0. Voltar\n");
        linha();
        op = ler_num("Escolha: ");

        switch (op) {
            case 1: cadastrar_pista(); break;
            case 2: listar_pistas(); break;
            case 3: ver_pista(); break;
            case 4: editar_pista(); break;
            case 5: remover_pista(); break;
            case 0: break;
            default: printf("[!] Opcao invalida.\n");
        }
    } while (op != 0);
}

void menu_controle() {
    int op;
    do {
        exibir_cabecalho("MENU CONTROLE AEREO");
        printf("1. Adicionar aviao na fila de uma pista\n");
        printf("2. Listar a fila de uma pista\n");
        printf("3. Numero de avioes aguardando na pista\n");
        printf("4. Autorizar decolagem do primeiro\n");
        printf("5. Caracteristicas do primeiro da fila\n");
        printf("6. Total de avioes em todas as filas\n");
        printf("0. Voltar\n");
        linha();
        op = ler_num("Escolha: ");

        switch (op) {
            case 1: adicionar_fila(); break;
            case 2: listar_fila(); break;
            case 3: total_fila_pista(); break;
            case 4: decolar(); break;
            case 5: ver_primeiro(); break;
            case 6: total_espera(); break;
            case 0: break;
            default: printf("[!] Opcao invalida.\n");
        }
    } while (op != 0);
}

int main() {
    int op;

    do {
        exibir_cabecalho("MENU PRINCIPAL");
        printf("1. Aeroporto\n");
        printf("2. Avioes\n");
        printf("3. Pistas\n");
        printf("4. Controle aereo\n");
        printf("5. Sair\n");
        linha();
        op = ler_num("Escolha: ");

        switch (op) {
            case 1: menu_aeroporto(); break;
            case 2: menu_avioes(); break;
            case 3: menu_pistas(); break;
            case 4: menu_controle(); break;
            case 5: printf("Saindo do sistema...\n"); break;
            default: printf("[!] Opcao invalida.\n");
        }
    } while (op != 5);

    liberar_pistas();
    liberar_avioes();
    return 0;
}
