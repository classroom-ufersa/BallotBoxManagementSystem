#ifndef CANDIDATO_H
#define CANDIDATO_H

/* Tipo exportado */
typedef struct candidato Candidato;

/* Funcoes exportadas */
Candidato *adicionar_candidato(Candidato *lista, char *nome, int idade, int numero, char *partido, char *vice, char *estado, int votos);
Candidato *obter_candidato(Candidato *lista);
void atualiza_arquivo(Candidato* lista);
Candidato *remover_candidato(Candidato *lista, int numero);
void listar_candidatos(Candidato *lista);
Candidato *buscar_candidato(Candidato *lista, int numero);
void editar_candidato(Candidato *lista, int numero, char *nome, int idade, char *partido, char *vice, char *estado, int votos);

#endif