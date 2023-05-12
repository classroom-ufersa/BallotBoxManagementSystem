#include "urnas.c"
#include "candidato.c"

int main (void) {
    //Declaração de variáveis
    Candidato *candidato; 
    Candidato *lista = NULL;
    char nome[50], partido[20], vice[50], estado[5];
    int idade, numero, votos;
    Urna *urna;
    urna = localizar_urna(urna); //Abrindo os arquivos de urna
    lista = obter_candidato(lista); //Abrindo os arquivos de candidatos
    printf("Bem-vindo ao Sistema de Gerenciamento de Urnas!\n");
    int escolha = 0;
    while (escolha != 8) {
        printf("1. Adicionar candidato\n");
        printf("2. Remover candidato\n");
        printf("3. Listar candidatos cadastrados\n");
        printf("4. Buscar candidato\n");
        printf("5. Editar candidato\n");
        printf("6. Consultar localizacao de urna\n");
        printf("7. Iniciar votacao\n");
        printf("8. Sair\n");
        printf("Digite a opcao desejada: ");
        //scanf("%d", &escolha);
        escolha = (int)scan_de_numeros(); //Função auxiliar para verificar se a escolha é um numero

        switch (escolha) {
            case 1:
                printf("Digite o seu nome: ");
                scanf(" %[^\n]s", nome);
                remover_caracteres_especiais(nome);
                printf("Informe a sua idade: ");
                scanf("%d", &idade);
                printf("Digite o seu numero: ");
                scanf("%d", &numero);
                printf("Informe o seu partido: ");
                scanf(" %[^\n]s", partido);
                remover_caracteres_especiais(partido);
                printf("Digite o nome do seu vice: ");
                scanf(" %[^\n]s", vice);
                remover_caracteres_especiais(vice);
                printf("Informe o seu estado: ");
                scanf(" %[^\n]s", estado);
                remover_caracteres_especiais(estado);
                votos = 0;
                lista = adicionar_candidato(lista, nome, idade, numero, partido, vice, estado, votos);
                printf("Candidato adicionado com sucesso!\n"); 
                urna->num_candidatos++;
                atualiza_arquivo(lista);
                atualiza_urna(urna);        
                break;
            case 2:
                printf("Informe o numero do candidato que deseja remover: ");
                scanf("%d", &numero);
                lista = remover_candidato(lista, numero);
                printf("Candidato removido com sucesso!\n");
                urna->num_candidatos--;
                atualiza_arquivo(lista);
                atualiza_urna(urna); 
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

                if(p != NULL){
                    char resposta;
                    printf("Deseja editar este candidato (s/n)? ");
                    scanf(" %c", &resposta);

                    if(resposta == 's' || resposta == 'S'){
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
                        editar_candidato(p, numero, nome, idade, partido, vice, estado, votos);
                        atualiza_arquivo(lista);
                    }
                }
                break;
            case 6:
                imprime_urna(urna);
                listar_candidatos(lista);
                break;
            case 7:
                printf("Informe o numero do candidato que deseja votar: ");
                scanf("%d", &numero);
                Candidato *c = buscar_candidato(lista, numero);

                if(c != NULL){
                    char resposta;
                    printf("Deseja votar neste candidato (s/n)? ");
                    scanf(" %c", &resposta);
                    if(resposta == 's' || resposta == 'S'){
                        c->votos++;
                        printf("Voto com sucesso!\n");
                    }
                }
                atualiza_arquivo(lista);
                break;
            case 8:
                printf("Obrigado por usar este programa.\n");
                exit(1);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
    return 0;
}
