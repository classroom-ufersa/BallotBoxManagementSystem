#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "urnas.c"
#include "candidato.c"

int main(){
    Candidato *lista = NULL;
    lista = obter_candidato(lista);
    listar_candidatos(lista);

    return 0;
}