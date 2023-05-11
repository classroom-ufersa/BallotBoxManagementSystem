#ifndef URNAS_H
#define URNAS_H

/* Tipo exportado */
typedef struct urna Urna;

/* Funcoes exportadas */
void consultar_localizacao_urna(Urna *urnas, int num_urnas);
Urna *localizar_urna(char *arquivo_localizacoes, int codigo_identificacao);

#endif