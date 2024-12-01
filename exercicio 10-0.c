#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

// Função iterativa para verificar se duas listas são iguais
int saoIguaisIterativo(Node *lista1, Node *lista2) {
    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->valor != lista2->valor) {
            return 0; // As listas não são iguais
        }
        lista1 = lista1->proximo;
        lista2 = lista2->proximo;
    }
    // Ambas devem terminar ao mesmo tempo para serem iguais
    return (lista1 == NULL && lista2 == NULL);
}

// Função recursiva para verificar se duas listas são iguais
int saoIguaisRecursivo(Node *lista1, Node *lista2) {
    if (lista1 == NULL && lista2 == NULL) {
        return 1; // Ambas as listas terminaram
    }
    if (lista1 == NULL || lista2 == NULL || lista1->valor != lista2->valor) {
        return 0; // Uma lista terminou antes da outra ou valores diferentes
    }
    return saoIguaisRecursivo(lista1->proximo, lista2->proximo);
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

// Função auxiliar para imprimir uma lista
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
    // Criando duas listas encadeadas de exemplo
    Node *lista1 = criarNo(1);
    lista1->proximo = criarNo(2);
    lista1->proximo->proximo = criarNo(3);

    Node *lista2 = criarNo(1);
    lista2->proximo = criarNo(2);
    lista2->proximo->proximo = criarNo(3);

    printf("Lista 1: ");
    imprimirLista(lista1);

    printf("Lista 2: ");
    imprimirLista(lista2);

    // Testando a função iterativa
    if (saoIguaisIterativo(lista1, lista2)) {
        printf("As listas são iguais (iterativo).\n");
    } else {
        printf("As listas NÃO são iguais (iterativo).\n");
    }

    // Testando a função recursiva
    if (saoIguaisRecursivo(lista1, lista2)) {
        printf("As listas são iguais (recursivo).\n");
    } else {
        printf("As listas NÃO são iguais (recursivo).\n");
    }

    // Liberando memória
    Node *atual;
    while (lista1 != NULL) {
        atual = lista1;
        lista1 = lista1->proximo;
        free(atual);
    }
    while (lista2 != NULL) {
        atual = lista2;
        lista2 = lista2->proximo;
        free(atual);
    }

    return 0;
}
