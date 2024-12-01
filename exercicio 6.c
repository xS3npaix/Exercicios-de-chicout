#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_TELEFONE 15
#define TAM_EMAIL 50

// Definição da struct para armazenar informações de contato
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
} Contato;

// Definição da lista de contatos
typedef struct {
    Contato contatos[MAX_CONTATOS];
    int tamanho;
} ListaContatos;

// Inicializa a lista de contatos
void inicializarLista(ListaContatos *lista) {
    lista->tamanho = 0;
}

// Insere um novo contato na lista
void inserirContato(ListaContatos *lista, Contato novoContato) {
    if (lista->tamanho >= MAX_CONTATOS) {
        printf("Erro: A lista de contatos está cheia.\n");
        return;
    }
    lista->contatos[lista->tamanho] = novoContato;
    lista->tamanho++;
    printf("Contato adicionado com sucesso.\n");
}

// Remove um contato pelo índice
void removerContato(ListaContatos *lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Erro: Índice inválido.\n");
        return;
    }
    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->contatos[i] = lista->contatos[i + 1];
    }
    lista->tamanho--;
    printf("Contato removido com sucesso.\n");
}

// Busca um contato pelo nome
int buscarContato(ListaContatos *lista, char *nome) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->contatos[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// Atualiza o nome de um contato
void atualizarNome(ListaContatos *lista, int indice, char *novoNome) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Erro: Índice inválido.\n");
        return;
    }
    strcpy(lista->contatos[indice].nome, novoNome);
    printf("Nome atualizado com sucesso.\n");
}

// Atualiza o telefone de um contato
void atualizarTelefone(ListaContatos *lista, int indice, char *novoTelefone) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Erro: Índice inválido.\n");
        return;
    }
    strcpy(lista->contatos[indice].telefone, novoTelefone);
    printf("Telefone atualizado com sucesso.\n");
}

// Atualiza o email de um contato
void atualizarEmail(ListaContatos *lista, int indice, char *novoEmail) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Erro: Índice inválido.\n");
        return;
    }
    strcpy(lista->contatos[indice].email, novoEmail);
    printf("Email atualizado com sucesso.\n");
}

// Exibe todos os contatos
void exibirContatos(ListaContatos *lista) {
    if (lista->tamanho == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", lista->contatos[i].nome);
        printf("Telefone: %s\n", lista->contatos[i].telefone);
        printf("Email: %s\n\n", lista->contatos[i].email);
    }
}

// Menu principal
void menu(ListaContatos *lista) {
    int opcao;
    do {
        printf("=== Agenda de Contatos ===\n");
        printf("1. Adicionar Contato\n");
        printf("2. Remover Contato\n");
        printf("3. Buscar Contato\n");
        printf("4. Atualizar Contato\n");
        printf("5. Exibir Contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Contato novoContato;
                printf("Nome: ");
                scanf(" %[^\n]", novoContato.nome);
                printf("Telefone: ");
                scanf(" %[^\n]", novoContato.telefone);
                printf("Email: ");
                scanf(" %[^\n]", novoContato.email);
                inserirContato(lista, novoContato);
                break;
            }
            case 2: {
                char nome[TAM_NOME];
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %[^\n]", nome);
                int indice = buscarContato(lista, nome);
                if (indice != -1) {
                    removerContato(lista, indice);
                } else {
                    printf("Contato não encontrado.\n");
                }
                break;
            }
            case 3: {
                char nome[TAM_NOME];
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %[^\n]", nome);
                int indice = buscarContato(lista, nome);
                if (indice != -1) {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s\n", lista->contatos[indice].nome);
                    printf("Telefone: %s\n", lista->contatos[indice].telefone);
                    printf("Email: %s\n", lista->contatos[indice].email);
                } else {
                    printf("Contato não encontrado.\n");
                }
                break;
            }
            case 4: {
                char nome[TAM_NOME];
                printf("Digite o nome do contato a ser atualizado: ");
                scanf(" %[^\n]", nome);
                int indice = buscarContato(lista, nome);
                if (indice != -1) {
                    printf("1. Atualizar Nome\n");
                    printf("2. Atualizar Telefone\n");
                    printf("3. Atualizar Email\n");
                    int escolha;
                    printf("Escolha o campo para atualizar: ");
                    scanf("%d", &escolha);
                    switch (escolha) {
                        case 1: {
                            char novoNome[TAM_NOME];
                            printf("Novo Nome: ");
                            scanf(" %[^\n]", novoNome);
                            atualizarNome(lista, indice, novoNome);
                            break;
                        }
                        case 2: {
                            char novoTelefone[TAM_TELEFONE];
                            printf("Novo Telefone: ");
                            scanf(" %[^\n]", novoTelefone);
                            atualizarTelefone(lista, indice, novoTelefone);
                            break;
                        }
                        case 3: {
                            char novoEmail[TAM_EMAIL];
                            printf("Novo Email: ");
                            scanf(" %[^\n]", novoEmail);
                            atualizarEmail(lista, indice, novoEmail);
                            break;
                        }
                        default:
                            printf("Opção inválida.\n");
                    }
                } else {
                    printf("Contato não encontrado.\n");
                }
                break;
            }
            case 5:
                exibirContatos(lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}

// Função principal
int main() {
    ListaContatos lista;
    inicializarLista(&lista);
    menu(&lista);
    return 0;
}
