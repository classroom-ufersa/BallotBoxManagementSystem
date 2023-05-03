#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "urnas.h"
#include "candidato.h"
#define MAX_CANDIDATOS 5

typedef struct urna{
    int codigo_verificacao;
    char localizacao[100];
    int num_candidatos;
    Candidato *candidato[MAX_CANDIDATOS];
    int votos[MAX_CANDIDATOS];
};

/*Função para localizar uma urna*/
void consultar_localizacao_urna(Urna *urnas, int num_urnas){
    int codigo;
    
    printf("Código de verificação da urna: ");
    scanf("%d", codigo);
    
    for (int i = 0; i < num_urnas; i++) {
        if (strcmp(urnas[i].codigo_verificacao, codigo) == 0) {
            printf("Localização: %s\n", urnas[i].localizacao);
            return;
        }
    }
    
    printf("Urna não encontrada.\n");
}
