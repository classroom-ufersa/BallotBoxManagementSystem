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

/*Função para localizar uma urna*/
Urna *localizar_urna(char *arquivo_localizacoes, int codigo_identificacao) {
    FILE *arquivo = fopen(arquivo_localizacoes, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de localizacoes\n");
        return NULL;
    }

    Urna *urna = malloc(sizeof(Urna));
    while (fscanf(arquivo, "%d %d %s %d", &urna->codigo_identificacao, &urna->num_candidatos, urna->candidato, &urna->votos) == 4) {
        if (urna->codigo_identificacao == codigo_identificacao) {
            fclose(arquivo);
            return urna;
        }
    }

    fclose(arquivo);
    free(urna);
    return NULL;
}
