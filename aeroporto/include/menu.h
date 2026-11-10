#ifndef MENU_H
#define MENU_H

void exibir_cabecalho(const char *titulo);
void linha();
int ler_num(const char *mensagem);
float ler_decimal(const char *mensagem);
void ler_texto(const char *mensagem, char texto[], int tamanho);

#endif
