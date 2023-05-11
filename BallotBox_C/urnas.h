#ifndef URNAS_H
#define URNAS_H

/* Tipo exportado */
typedef struct urna Urna;

/* Funcoes exportadas */
Urna *localizar_urna(Urna *urna);
Urna *cria_urna(Urna *urna, int codigo_identificacao, char *localizacao, int num_candidatos);
void imprime_urna(Urna *urna);
void atualiza_urna(Urna* urna);

#endif