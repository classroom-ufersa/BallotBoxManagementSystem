#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "urnas.h"
#include "candidato.h"
#include "auxiliar.h"
#define TAM_LINHA 200

typedef struct urna{
    int codigo_identificacao;
    char localizacao[100];
    int num_candidatos;
    Candidato *candidato;
    int votos;
    struct urna*prox;
};

Urna *cria_urna(Urna *urna, int codigo_identificacao, char *localizacao, int num_candidatos) {
    Urna *u = (Urna*) malloc(sizeof(Urna));
    // inserindo as informações passadas por parametro
    u->codigo_identificacao = codigo_identificacao;
    strcpy(u->localizacao, localizacao);
    u->num_candidatos = num_candidatos;
    u->prox = urna;
    return u;
}

/*Função para localizar uma urna*/
Urna *localizar_urna(Urna *urna) {
    FILE *arquivo_origem;
    Urna *nova_urna = urna;
    char localizacao[100], linha[TAM_LINHA];
    int codigo_identificacao, num_candidatos, votos;
    arquivo_origem = fopen("../output/urnas.txt", "r");
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo de localizacoes\n");
        exit(1);
    }

    /*fseek(arquivo_origem, 0, SEEK_END); // posiciona o cursor no final do arquivo
    if (ftell(arquivo_origem) == 0) { // verifica a posição atual do cursor
        printf("O arquivo esta vazio.\n");
        return NULL;
    }else{
        rewind(arquivo_origem);
    }*/

    while (fgets(linha, TAM_LINHA, arquivo_origem) != NULL){
        sscanf(linha, " %[^;];%d;%d;", localizacao, &codigo_identificacao, &num_candidatos);
        nova_urna = cria_urna(nova_urna, codigo_identificacao, localizacao, num_candidatos);
    }

    fclose(arquivo_origem);
    return nova_urna;
}

void atualiza_urna(Urna* urna) {
    FILE *arquivo;
    arquivo = fopen("../output/urnas.txt", "w"); // Abre o arquivo para escrita
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fprintf(arquivo, "%s;", urna->localizacao);
    fprintf(arquivo, "%d;", urna->codigo_identificacao);
    fprintf(arquivo, "%d;\n", urna->num_candidatos);

    fclose(arquivo); // Fecha o arquivo
    printf("Arquivo urnas atualizado!\n");
}

void imprime_urna(Urna *urna){
    printf("\n-------------URNA-------------\n");
    printf("Localizacao: %s\n", urna->localizacao);
    printf("Codigo de identificacao: %d\n", urna->codigo_identificacao);
    printf("Numero de Candidatos: %d\n", urna->num_candidatos);
}