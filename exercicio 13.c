#include <stdio.h>
#include <stdlib.h>

// Definição de um nó da árvore binária
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inverter (espelhar) a árvore
void mirrorTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    // Troca as subárvores
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Aplica o mesmo processo nas subárvores
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Função para imprimir a árvore em ordem (in-order traversal)
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Exemplo de uso
int main() {
    // Construção da árvore de exemplo
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(10);
    root->right->right->left = createNode(8);

    printf("Árvore original (em ordem): ");
    inOrder(root);
    printf("\n");

    // Obtendo o espelho da árvore
    mirrorTree(root);

    printf("Árvore espelhada (em ordem): ");
    inOrder(root);
    printf("\n");

    return 0;
}
