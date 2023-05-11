#ifndef URNAS_H
#define URNAS_H

/* Tipo exportado */
typedef struct urna Urna;

/* Funcoes exportadas */
Urna *localizar_urna(Urna *urna, char *arquivo_localizacoes, int codigo_identificacao);
Urna *cria_urna(Urna *urna, int codigo_identificacao, char *localizacao, int num_candidatos, int votos);
void imprime_urna(Urna *urna);

#endif