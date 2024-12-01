#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

// Função iterativa para buscar um valor na lista encadeada crescente
Node *buscarIterativa(Node *head, int chave) {
    while (head != NULL) {
        if (head->valor == chave) {
            return head; // Retorna o nó encontrado
        }
        if (head->valor > chave) {
            break; // Valor não está na lista
        }
        head = head->proximo;
    }
    return NULL; // Valor não encontrado
}

// Função recursiva para buscar um valor na lista encadeada crescente
Node *buscarRecursiva(Node *head, int chave) {
    if (head == NULL || head->valor > chave) {
        return NULL; // Lista vazia ou valor não encontrado
    }
    if (head->valor == chave) {
        return head; // Retorna o nó encontrado
    }
    return buscarRecursiva(head->proximo, chave);
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

    int chave = 3;
    printf("Buscando valor %d (iterativa)...\n", chave);
    Node *resultado = buscarIterativa(head, chave);
    if (resultado) {
        printf("Valor encontrado: %d\n", resultado->valor);
    } else {
        printf("Valor não encontrado.\n");
    }

    printf("Buscando valor %d (recursiva)...\n", chave);
    resultado = buscarRecursiva(head, chave);
    if (resultado) {
        printf("Valor encontrado: %d\n", resultado->valor);
    } else {
        printf("Valor não encontrado.\n");
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
