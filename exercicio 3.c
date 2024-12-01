/*Fazer um programa em C que lê uma lista de 20 produtos e de preços e armazena-os em um array
 do tipo da estrutura abaixo. O programa deve, em seguida, ordenar o vetor em ordem alfabética de
 nome de produto e inflacionar os produtos cujo valor for menor que 100 em 5%. Por fim, a lista de
 produtos/preços deve ser impressa. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PRODUTOS 20

// Definição da estrutura para armazenar produto e preço
typedef struct {
    char nome[50];
    float preco;
} Produto;

// Função para ler os produtos e preços
void lerProdutos(Produto produtos[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf(" %[^\n]", produtos[i].nome); // Lê uma string com espaços
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
    }
}

// Função para ordenar os produtos por nome em ordem alfabética
void ordenarProdutosPorNome(Produto produtos[], int n)
{
    Produto temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
}

// Função para inflacionar produtos com preço menor que 100 em 5%
void inflacionarProdutos(Produto produtos[], int n)
{
    for (int i = 0; i < n; i++) {
        if (produtos[i].preco < 100) {
            produtos[i].preco *= 1.05; // Aumenta o preço em 5%
        }
    }
}

// Função para imprimir a lista de produtos e preços
void imprimirProdutos(Produto produtos[], int n)
{
    printf("\nLista de produtos e preços:\n");
    for (int i = 0; i < n; i++) {
        printf("Produto: %-20s | Preço: %.2f\n", produtos[i].nome, produtos[i].preco);
    }
}

// Função principal
int main()
{
    Produto produtos[NUM_PRODUTOS];

    // Ler os produtos e preços
    printf("Cadastro de %d produtos:\n", NUM_PRODUTOS);
    lerProdutos(produtos, NUM_PRODUTOS);

    // Ordenar os produtos por nome
    ordenarProdutosPorNome(produtos, NUM_PRODUTOS);

    // Inflacionar os produtos com preço menor que 100
    inflacionarProdutos(produtos, NUM_PRODUTOS);

    // Imprimir a lista de produtos e preços
    imprimirProdutos(produtos, NUM_PRODUTOS);

    return 0;
}
