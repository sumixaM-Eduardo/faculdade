#include <stdio.h>
#include <string.h>
#include "aeroporto.h"
#include "aviao.h"
#include "pista.h"
#include "menu.h"

Aeroporto aeroporto = {0};

void cadastrar_aeroporto() {
    Aeroporto novo = {0};
    int tipo;

    exibir_cabecalho("CADASTRAR AEROPORTO");
    novo.id = ler_num("ID do aeroporto: ");
    if (novo.id <= 0) {
        printf("[!] ID invalido.\n");
        return;
    }

    ler_texto("Nome do aeroporto: ", novo.nome, 80);
    ler_texto("Codigo IATA (3 letras): ", novo.iata, 10);
    if (strlen(novo.iata) != 3) {
        printf("[!] O codigo IATA precisa ter 3 caracteres.\n");
        return;
    }

    printf("1. Publico\n2. Privado\n");
    tipo = ler_num("Tipo: ");
    if (tipo == 1) {
        strcpy(novo.tipo, "Publico");
    } else if (tipo == 2) {
        strcpy(novo.tipo, "Privado");
    } else {
        printf("[!] Tipo invalido.\n");
        return;
    }

    novo.capacidade = ler_num("Capacidade anual de passageiros: ");
    if (novo.capacidade < 0) {
        printf("[!] Capacidade invalida.\n");
        return;
    }

    novo.cadastrado = 1;
    aeroporto = novo;
    printf("[+] Aeroporto cadastrado!\n");
}

void ver_aeroporto() {
    exibir_cabecalho("INFORMACOES DO AEROPORTO");
    if (aeroporto.cadastrado == 0) {
        printf("[!] Nenhum aeroporto cadastrado.\n");
        return;
    }

    aeroporto.qtdavioes = totalavioes;
    aeroporto.qtdpistas = totalpistas;

    printf("ID: %d\n", aeroporto.id);
    printf("Nome: %s\n", aeroporto.nome);
    printf("Codigo IATA: %s\n", aeroporto.iata);
    printf("Tipo: %s\n", aeroporto.tipo);
    printf("Capacidade anual: %d passageiros\n", aeroporto.capacidade);
    printf("Avioes cadastrados: %d\n", aeroporto.qtdavioes);
    printf("Pistas disponiveis: %d\n", aeroporto.qtdpistas);
}
