
/*Usando listas dinâmicas, crie um programa que guarde strings. Re-implemente todas as funcionalidades para que
 seja possível usar as funções básicas de inserção, remoção, busca e detecção de fim de lista;
Implemente também a função que retorna o tamanho da lista (quantidade de elementos),
 e a perda de memória (total da lista - quantidade de itens vazios)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 100

// Estrutura de nó para lista dinâmica
typedef struct No {
    char dado[TAM_STRING];
    struct No *prox;
} No;

// Função para criar uma nova lista (retorna NULL para lista vazia)
No *criarLista()
{
    return NULL;
}

// Função para inserir uma string na lista
No *inserirNo(No *inicio, const char *str)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novoNo->dado, str);
    novoNo->prox = inicio;
    return novoNo;
}

// Função para buscar uma string na lista
No *buscarNo(No *inicio, const char *str)
{
    No *atual = inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->dado, str) == 0)
        {
            return atual; // String encontrada
        }
        atual = atual->prox;
    }
    return NULL; // String não encontrada
}

// Função para remover uma string da lista
No *removerNo(No *inicio, const char *str)
{
    No *atual = inicio, *anterior = NULL;

    while (atual != NULL)
    {
        if (strcmp(atual->dado, str) == 0)
        {
            if (anterior == NULL)
            {
                // Remover o primeiro nó
                No *temp = atual;
                inicio = atual->prox;
                free(temp);
            }
            else
            {
                // Remover nó intermediário ou final
                anterior->prox = atual->prox;
                free(atual);
            }
            return inicio; // Retorna o novo início
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("String \"%s\" não encontrada na lista.\n", str);
    return inicio;
}

// Função para verificar se chegou ao fim da lista
int fimDaLista(No *no)
{
    return (no == NULL);
}

// Função para calcular o tamanho da lista (quantidade de elementos)
int tamanhoLista(No *inicio)
{
    int tamanho = 0;
    No *atual = inicio;
    while (atual != NULL)
    {
        tamanho++;
        atual = atual->prox;
    }
    return tamanho;
}

// Função para calcular a perda de memória
int perdaDeMemoria(No *inicio)
{
    int totalAlocado = 0;
    int totalUtilizado = 0;
    No *atual = inicio;

    while (atual != NULL)
    {
        totalAlocado += sizeof(No);
        totalUtilizado += sizeof(char) * (strlen(atual->dado) + 1);
        atual = atual->prox;
    }

    return totalAlocado - totalUtilizado;
}

// Função para imprimir a lista
void imprimirLista(No *inicio)
{
    No *atual = inicio;
    if (atual == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    while (atual != NULL)
    {
        printf("%s -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função principal para teste
int main()
{
    No *lista = criarLista();

    // Inserção de strings na lista
    lista = inserirNo(lista, "C");
    lista = inserirNo(lista, "Python");
    lista = inserirNo(lista, "Java");
    lista = inserirNo(lista, "JavaScript");

    printf("Lista inicial:\n");
    imprimirLista(lista);

    // Buscar elemento
    char *busca = "Python";
    No *encontrado = buscarNo(lista, busca);
    if (encontrado)
    {
        printf("Elemento \"%s\" encontrado na lista.\n", busca);
    }
    else
    {
        printf("Elemento \"%s\" nao encontrado na lista.\n", busca);
    }

    // Remover elemento
    lista = removerNo(lista, "Java");
    printf("\nLista apos remover \"Java\":\n");
    imprimirLista(lista);

    // Tamanho da lista
    int tamanho = tamanhoLista(lista);
    printf("\nTamanho da lista: %d elementos.\n", tamanho);

    // Perda de memória
    int perda = perdaDeMemoria(lista);
    printf("Perda de memoria: %d bytes.\n", perda);

    // Verificar fim da lista
    if (fimDaLista(lista))
    {
        printf("Lista esta vazia.\n");
    }
    else
    {
        printf("Lista nao esta vazia.\n");
    }

    return 0;
}
