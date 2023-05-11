#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "candidato.h"
#include "auxiliar.h"
#define MAX_CANDIDATOS 5

typedef struct candidato{
    char nome[50];
    int idade;
    int numero;
    char partido[20];
    char vice[50];
    char estado[2];
    struct Candidato*prox;
};

/*Função para adicionar candidatos*/
Candidato *adicionar_candidato(Candidato *lista, char *nome, int idade, int numero, char *partido, char *vice, char *estado){
    Candidato *candidato = (Candidato*)malloc(sizeof(Candidato));
    if (candidato == NULL){
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    nome[0] = toupper(nome[0]);
    strcpy(candidato->nome, nome);
    candidato->idade = idade;
    candidato->numero = numero;
    strcpy(candidato->partido, partido);
    vice[0] = toupper(vice[0]);
    strcpy(candidato->vice, vice);
    strcpy(candidato->estado, estado);

    candidato->prox = NULL;
    if(lista == NULL){
        lista = candidato;
    }else{
        Candidato *aux = lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = candidato;
    }

    return lista;
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
            printf("Candidato nao encontrado! Verifique o numero, e tente novamente.");
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
