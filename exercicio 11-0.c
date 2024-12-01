#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para encontrar o meio da lista
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL; // Lista vazia

    Node* slow = head;
    Node* fast = head;

    // Avançar os ponteiros até o fim da lista
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Avança 1 passo
        fast = fast->next->next;     // Avança 2 passos
    }

    return slow; // Ponteiro `slow` estará no meio
}

// Função auxiliar para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função auxiliar para imprimir a lista
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função principal para testar
int main() {
    // Criando uma lista encadeada manualmente: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Imprimindo a lista
    printf("Lista encadeada: ");
    printList(head);

    // Encontrando o meio
    Node* middle = findMiddle(head);
    if (middle != NULL) {
        printf("O nó do meio tem o valor: %d\n", middle->data);
    } else {
        printf("A lista está vazia.\n");
    }

    // Liberando memória
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
