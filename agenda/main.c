#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    printf(" oi");
    Node* agenda = criarAgenda();

    Contato contato = {
        .nome = "maximus"
    };
    Contato contato2 = {
        .nome = "marcos"
    };
    agenda = inserirContato(agenda, contato);
    agenda = inserirContato(agenda, contato2);

    listarContatos(agenda);

    return 0;
}

