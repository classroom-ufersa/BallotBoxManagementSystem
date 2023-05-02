#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "urnas.h"

typedef struct urna{
    char codigo[20];
    int num_candidatos;
    Candidato candidatos[50];
    int votos[50];
};

typedef struct candidato{
    char nome[50];
    int idade;
    int numero;
    char partido[20];
    char vice[50];
    char estado[2];
};