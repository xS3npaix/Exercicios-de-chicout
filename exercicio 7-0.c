#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

// Função para verificar se a lista está em ordem crescente
int estaEmOrdemCrescente(Node *head) {
    if (head == NULL || head->proximo == NULL) {
        // Lista vazia ou com um único elemento está em ordem crescente
        return 1;
    }

    Node *atual = head;
    while (atual->proximo != NULL) {
        if (atual->valor > atual->proximo->valor) {
            return 0; // Não está em ordem crescente
        }
        atual = atual->proximo;
    }
    return 1; // Está em ordem crescente
}

// Função auxiliar para criar um novo nó
Node *criarNo(int valor) {
    Node *novoNo = (Node *)malloc(sizeof(Node));
    if (!novoNo) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função auxiliar para imprimir a lista
void imprimirLista(Node *head) {
    Node *atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função principal para testar
int main() {
    // Criando uma lista encadeada de exemplo: 1 -> 2 -> 3 -> 4
    Node *head = criarNo(1);
    head->proximo = criarNo(2);
    head->proximo->proximo = criarNo(3);
    head->proximo->proximo->proximo = criarNo(4);

    imprimirLista(head);

    if (estaEmOrdemCrescente(head)) {
        printf("A lista está em ordem crescente.\n");
    } else {
        printf("A lista NÃO está em ordem crescente.\n");
    }

    // Liberando a memória alocada
    Node *atual = head;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
