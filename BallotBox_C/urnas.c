#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "urnas.h"
#include "candidato.h"


typedef struct urna{
    int codigo_identificacao;
    char localizacao[100];
    int num_candidatos;
    Candidato *candidato;
    int votos;
};

Urna *cria_urna(Urna *urna, int codigo_identificacao, char *localizacao, int num_candidatos, int votos) {
    Urna *u = (Urna*) malloc(sizeof(Urna));
    // inserindo as informações passadas por parametro
    u->codigo_identificacao = codigo_identificacao;
    strcpy(u->localizacao, localizacao);
    u-> num_candidatos = num_candidatos;
    u->votos = votos;

    return u;
}

/*Função para localizar uma urna*/
Urna *localizar_urna(Urna *urna, char *arquivo_localizacoes, int codigo_identificacao) {
    FILE *arquivo_origem = fopen("../output/urnas.txt", "r");
    Urna *nova_urna = urna;
    char localizacao[100];
    int num_candidatos, votos;

    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo de localizacoes\n");
        return NULL;
    }

    fseek(arquivo_origem, 0, SEEK_END); // posiciona o cursor no final do arquivo
    if (ftell(arquivo_origem) == 0) { // verifica a posição atual do cursor
        printf("O arquivo esta vazio.\n");
        return NULL;
    }else{
        rewind(arquivo_origem);
    }

    while (fscanf(arquivo_origem, " %[^;]; %d;%d;%d;", localizacao, &urna->codigo_identificacao, &urna->num_candidatos, &urna->votos) != NULL) {
        nova_urna = cria_urna(nova_urna, codigo_identificacao, localizacao, num_candidatos, votos);
    }

    fclose(arquivo_origem);
    free(urna);
    return nova_urna;
}


void imprime_urna(Urna *urna){
    printf("\n-------------URNA-------------\n");
    printf("Localizacao: %s\n", urna->localizacao);
    printf("Codigo de identificacao: %d\n", urna->codigo_identificacao);
    printf("Numero de Candidatos: %d\n", urna->num_candidatos);
    printf("Votos: %d\n", urna->votos);
}