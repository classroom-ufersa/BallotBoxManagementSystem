#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "candidato.h"
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
void remover_candidato(Candidato *candidato){
    int numero;
    
    printf("Numero do candidato a ser removido: ");
    scanf("%d", &numero);
    
    for (int i = 0; i < urna->num_candidatos; i++) {
        if (urna->candidatos[i].numero == numero) {
            for (int j = i; j < urna->num_candidatos - 1; j++) {
                urna->candidatos[j] = urna->candidatos[j + 1];
                urna->votos[j] = urna->votos[j + 1];
            }
            
            urna->num_candidatos--;
            
            printf("Candidato removido com sucesso.\n");
            return;
        }
    }
    
    printf("Candidato não encontrado.\n");
}

/*Função para listar os candidatos cadastrados*/
void listar_candidatos(Candidato *candidato){
    for (int i = 0; i < urna->num_candidatos; i++) {
        Candidato c = urna->candidatos[i];
        
        printf("%d - %s (%s)\n", c.numero, c.nome, c.partido);
        printf("Idade: %d\n", c.idade);
        printf("Vice: %s\n", c.vice);
        printf("Estado: %s\n", c.estado);
        printf("\n");
    }
}

/*Função para buscar candidato*/
void buscar_candidato(Candidato *candidato){
    int numero;
    
    printf("Numero do candidato a ser buscado: ");
    scanf("%d", &numero);
    
    for (int i = 0; i < urna->num_candidatos; i++) {
        if (urna->candidatos[i].numero == numero) {
            Candidato c = urna->candidatos[i];
            
            printf("%d - %s (%s)\n", c.numero, c.nome, c.partido);
            printf("Idade: %d\n", c.idade);
            printf("Vice: %s\n", c.vice);
            printf("Estado: %s\n", c.estado);
            
            return;
        }
    }
    
    printf("Candidato não encontrado.\n");
}

/*Função para editar candidato*/
void editar_candidato(Candidato *candidato){
    int numero;
    
    printf("Número do candidato a ser editado: ");
    scanf("%d", &numero);
    
    for (int i = 0; i < urna->num_candidatos; i++) {
        if (urna->candidatos[i].numero == numero) {
            Candidato *candidato = &urna->candidatos[i];
            
            printf("Novo nome (%s): ", candidato->nome);
            scanf("%s", candidato->nome);
            
            printf("Nova idade (%d): ", candidato->idade);
            scanf("%d", &candidato->idade);
            
            printf("Novo partido (%s): ", candidato->partido);
            scanf("%s", candidato->partido);
            
            printf("Novo vice (%s): ", candidato->vice);
            scanf("%s", candidato->vice);
            
            printf("Novo estado (%s): ", candidato->estado);
            scanf("%s", candidato->estado);
            
            printf("Candidato editado.\n");
            return;
        }
    }
    
    printf("Candidato não encontrado.\n");
}