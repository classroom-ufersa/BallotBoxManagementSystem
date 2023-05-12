#ifndef AUXILIAR_H
#define AUXILIAR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Pede um numero e verifica se o numero foi inserido corretamente
float scan_de_numeros(void)
{
    char *line = NULL;
    char resto[50] = "Codigo Verificador &*()";
    size_t len = 0;
    float result;

    while (1) {
       if (getline(&line, &len, stdin) == -1) {
           /* EOF or Error */
           return 1;
       }
       if (sscanf(line, "%f%s", &result, resto) != 1) {
           printf("\nSomente numeros, por favor: ");
           continue; 
       } 
       break;
    }
    return result;
}

//Função para remover caracteres especiais
void remover_caracteres_especiais(char *string) {
  int i = 0, j = 0;

  // Utilizando while para percorrer toda a string
  while (string[i] != '\0') {
    if (isalpha(string[i])) {
      // Salvando a string contendo apenas os caracteres
      string[j] = string[i];
      ++j;
    }
    ++i;
  }
  string[j] = '\0'; // Definindo o final da string
}

#endif