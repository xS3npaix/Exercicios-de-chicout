#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

// Função iterativa para encontrar a célula com o valor mínimo
Node *encontrarMinIterativo(Node *head) {
    if (head == NULL) {
        return NULL; // Lista vazia
    }
    
    Node *minimo = head;
    Node *atual = head->proximo;
    
    while (atual != NULL) {
        if (atual->valor < minimo->valor) {
            minimo = atual;
        }
        atual = atual->proximo;
    }
    return minimo;
}

// Função recursiva para encontrar a célula com o valor mínimo
Node *encontrarMinRecursivo(Node *head) {
    if (head == NULL || head->proximo == NULL) {
        return head; // Lista vazia ou último nó
    }

    Node *minimoSublista = encontrarMinRecursivo(head->proximo);

    return (head->valor < minimoSublista->valor) ? head : minimoSublista;
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
    // Criando uma lista encadeada de exemplo: 4 -> 2 -> 7 -> 1 -> 5
    Node *head = criarNo(4);
    head->proximo = criarNo(2);
    head->proximo->proximo = criarNo(7);
    head->proximo->proximo->proximo = criarNo(1);
    head->proximo->proximo->proximo->proximo = criarNo(5);

    imprimirLista(head);

    // Testando a função iterativa
    Node *minIterativo = encontrarMinIterativo(head);
    if (minIterativo) {
        printf("Valor mínimo encontrado (iterativo): %d\n", minIterativo->valor);
    } else {
        printf("A lista está vazia (iterativo).\n");
    }

    // Testando a função recursiva
    Node *minRecursivo = encontrarMinRecursivo(head);
    if (minRecursivo) {
        printf("Valor mínimo encontrado (recursivo): %d\n", minRecursivo->valor);
    } else {
        printf("A lista está vazia (recursivo).\n");
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
