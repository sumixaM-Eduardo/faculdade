#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Node* criarAgenda() {
    return NULL;
}

Node* inserirContato(Node* agenda, Contato C) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    
}

void listarContatos(Node* agenda) {
    for (Node* i = agenda; i->proximo != NULL; i = i->proximo) {
        printf("%s", i->contato.nome);
    }
}

Node* buscarContato(Node* agenda, char *nome) {
    for (Node* i = agenda; i->proximo != NULL; i = i->proximo) {
        if (strcmp(i->contato.nome, nome) == 0) {
            return i;
        }
    }
}