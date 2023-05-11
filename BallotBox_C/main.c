#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "urnas.c"
#include "candidato.c"
#define MAX_CANDIDATOS 5


int main (void) {
    Candidato *candidato[MAX_CANDIDATOS]; 
    Candidato *lista = NULL;
    char nome[50], partido[50], vice[50], estado[2];
    int idade, numero, n_candidatos = 0;
    
    printf("Bem-vindo ao Sistema de Gerenciamento de Urnas!\n");
    int i, escolha = 0;
    while (escolha != 7) {
        printf("1. Adicionar candidato\n");
        printf("2. Remover candidato\n");
        printf("3. Listar candidatos cadastrados\n");
        printf("4. Buscar candidato\n");
        printf("5. Editar candidato\n");
        printf("6. Consultar localizacao de urna\n");
        printf("7. Sair\n");
        printf("Digite a opcao desejada: ");
        //scanf("%d", &escolha);
        escolha = (int)scan_de_numeros();

        switch (escolha) {
            case 1:
                if(n_candidatos < MAX_CANDIDATOS-1){
                    printf("Digite o seu nome: ");
                    scanf(" %[^\n]s", nome);
                    printf("Informe a sua idade: ");
                    scanf("%d", &idade);
                    printf("Digite o seu numero: ");
                    scanf("%d", &numero);
                    printf("Informe o seu partido: ");
                    scanf(" %[^\n]s", partido);
                    printf("Digite o nome do seu vice: ");
                    scanf(" %[^\n]s", vice);
                    printf("Informe o seu estado: ");
                    scanf(" %[^\n]s", estado);

                    lista = adicionar_candidato(lista, nome, idade, numero, partido, vice, estado);


                } else {
                    printf("NUMERO MAXIMO DE CANDIDATOS ATINGIDO!\n");
                }
                break;
            case 2:
                printf("Informe o numero do candidato que deseja remover: ");
                scanf("%d", &numero);
                remover_candidato(lista, numero);
                break;
            case 3:
                listar_candidatos(lista);
                break;
            case 4:
                printf("Informe o numero do candidato que deseja buscar: ");
                scanf("%d", &numero);
                buscar_candidato(lista, numero);
                break;
            case 5:
                printf("Informe o numero do candidato que deseja editar: ");
                scanf("%d", &numero);
                Candidato *p = buscar_candidato(lista, numero);
                printf("Digite o novo nome: ");
                scanf(" %[^\n]s", nome);
                printf("Informe a nova idade: ");
                scanf("%d", &idade);
                printf("Digite o novo numero: ");
                scanf("%d", &numero);
                printf("Informe o novo partido: ");
                scanf(" %[^\n]s", partido);
                printf("Digite o novo nome do seu vice: ");
                scanf(" %[^\n]s", vice);
                printf("Informe o seu novo estado: ");
                scanf(" %[^\n]s", estado);
                editar_candidato(p, numero, nome, idade, partido, vice, estado);
                break;
            case 6:
                
                break;
            case 7:
                printf("Obrigado por usar este programa.\n");
                exit(1);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
}
