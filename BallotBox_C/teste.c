#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "urnas.c"
#include "candidato.c"

int main(){
    Candidato *lista = NULL;
    lista = obter_candidato(lista);
    lista = remover_candidato(lista, 1234);
    atualiza_arquivo(lista);
    return 0;
}