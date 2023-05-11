#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "candidato.h"
#include "auxiliar.h"
#define TAM_LINHA 200

typedef struct candidato{
    char nome[50];
    int idade;
    int numero;
    char partido[20];
    char vice[50];
    char estado[5];
    struct candidato*prox;
};

/*Função para adicionar candidatos*/
Candidato *adicionar_candidato(Candidato *lista, char *nome, int idade, int numero, char *partido, char *vice, char *estado){
    Candidato *candidato = (Candidato*) malloc(sizeof(Candidato));
    if (candidato == NULL){
        printf("Memoria insuficiente!\n");
        exit(1);
    }

    strcpy(candidato->nome, nome);
    candidato->idade = idade;
    candidato->numero = numero;
    strcpy(candidato->partido, partido);
    strcpy(candidato->vice, vice);
    strcpy(candidato->estado, estado);

    candidato->prox = lista;
    return candidato;
}

Candidato *obter_candidato(Candidato *lista){
    FILE *arquivo_origem;
    Candidato *nova_lista = lista;
    char linha[TAM_LINHA], nome[50], partido[20], vice[50], estado[5];
    int idade, numero;
    arquivo_origem = fopen("../output/abc.txt", "r"); // abre o arquivo_origem para leitura
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fseek(arquivo_origem, 0, SEEK_END); // posiciona o cursor no final do arquivo
    if (ftell(arquivo_origem) == 0) { // verifica a posição atual do cursor
        printf("O arquivo esta vazio.\n");
        return NULL;
    }else{
        rewind(arquivo_origem);
    }

    while (fgets(linha, TAM_LINHA, arquivo_origem) != NULL) {
        sscanf(linha, " %[^;];%d;%d;%[^;];%[^;];%[^;];", nome, &idade, &numero, partido, vice, estado);
        nova_lista = adicionar_candidato(nova_lista, nome, idade, numero, partido, vice, estado);
    
    }
    fclose(arquivo_origem); // fecha o arquivo
    return nova_lista;
}

void atualiza_arquivo(Candidato* lista) {
    Candidato* p; /* variável auxiliar para percorrer a lista */
    FILE *arquivo;
    arquivo = fopen("../output/abc.txt", "w"); // Abre o arquivo para escrita
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (p = lista; p != NULL; p = p->prox) {
        fprintf(arquivo, "%s;", p->nome);
        fprintf(arquivo, "%d;", p->idade);
        fprintf(arquivo, "%d;", p->numero);
        fprintf(arquivo, "%s;", p->partido);
        fprintf(arquivo, "%s;", p->vice);
        fprintf(arquivo, "%s\n", p->estado);
    }
    fclose(arquivo); // Fecha o arquivo
    printf("Arquivo atualizado!\n");
}   


/*Função para remover candidato*/
Candidato *remover_candidato(Candidato *lista, int numero) {
    Candidato *ant = NULL;
    Candidato *p = lista;
    
    while (p != NULL && p->numero != numero) {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL) {
        return lista;
    }
    
    if (ant == NULL) {
        lista = p->prox;
    } else {
        ant->prox = p->prox;
    }
    
    free(p);
    return lista;
}

/*Função para listar os candidatos cadastrados*/
void listar_candidatos(Candidato *lista) {
    Candidato *p;
    for (p = lista; p != NULL; p = p->prox) {
        printf("Nome: %s\n", p->nome);
        printf("Idade: %d\n", p->idade);
        printf("Numero: %d\n", p->numero);
        printf("Partido: %s\n", p->partido);
        printf("Vice: %s\n", p->vice);
        printf("Estado: %s\n", p->estado);
        printf("\n");
    }
}

/*Função para buscar candidato*/
Candidato *buscar_candidato(Candidato *lista, int numero) {
    Candidato *p;
    for (p = lista; p != NULL; p = p->prox) {
        if (p->numero == numero) {
            printf("Nome: %s\n", p->nome);
            printf("Idade: %d\n", p->idade);
            printf("Numero: %d\n", p->numero);
            printf("Partido: %s\n", p->partido);
            printf("Vice: %s\n", p->vice);
            printf("Estado: %s\n", p->estado);
            printf("\n");
            return p;
        } else{
            printf("Candidato nao encontrado! Verifique o numero, e tente novamente.\n");
        }
    }
    return NULL;
}

/*Função para editar candidato*/
void editar_candidato(Candidato *p, int numero, char *nome, int idade, char *partido, char *vice, char *estado) {
    if (p != NULL) {
        strcpy(p->nome, nome);
        p->idade = idade;
        strcpy(p->partido, partido);
        strcpy(p->vice, vice);
        strcpy(p->estado, estado);
    } else{
        printf("Candidato não encontrado!\n");
    }
    return p;
}
