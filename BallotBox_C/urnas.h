#ifndef URNAS_H
#define URNAS_H

/* Tipo exportado */
typedef struct urna Urna;
typedef struct candidato Candidato;

/* Funcoes exportadas */

Candidato *adicionar_candidato(char *nome, int idade, int numero, char *partido, char *vice, char *estado);
void remover_candidato(Urna *urna);
void listar_candidatos(Urna *urna);
void buscar_candidato(Urna *urna);
void editar_candidato(Urna *urna);
void consultar_localizacao_urna(Urna *urnas, int num_urnas);

#endif