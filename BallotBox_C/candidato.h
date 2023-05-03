#ifndef CANDIDATO_H
#define CANDIDATO_H

/* Tipo exportado */
typedef struct candidato Candidato;

/* Funcoes exportadas */

Candidato *adicionar_candidato(char *nome, int idade, int numero, char *partido, char *vice, char *estado);
void remover_candidato(Candidato *candidato);
void listar_candidatos(Candidato *candidato);
void buscar_candidato(Candidato *candidato);
void editar_candidato(Candidato *candidato);

#endif