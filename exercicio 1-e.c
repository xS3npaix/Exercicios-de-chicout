/*Inverta L1 colocando o resultado na própria L1;
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura com typedef
typedef struct No {
    int info;
    struct No *prox;
} Lista;

// Função para criar uma nova lista
Lista *criaLista()
{
    return NULL;
}

// Função para inserir um nó no início da lista
Lista *insereNoLista(Lista *cursor, int valor)
{
    Lista *novoNo = (Lista *)malloc(sizeof(Lista));
    novoNo->info = valor;
    novoNo->prox = cursor;
    cursor = novoNo;
    return cursor;
}

// Função para imprimir os elementos da lista
void imprimir(Lista *inicio)
{
    if (inicio == NULL)
    {
        printf("Lista Vazia\n");
        return;
    }

    for (Lista *p = inicio; p != NULL; p = p->prox)
    {
        printf("%d \n", p->info);
    }
}

// Função para inverter a lista L1 in-place
Lista *inverterLista(Lista *L1)
{
    Lista *anterior = NULL;
    Lista *atual = L1;
    Lista *proximo = NULL;

    while (atual != NULL)
    {
        // Armazena o próximo nó
        proximo = atual->prox;
        // Inverte o ponteiro
        atual->prox = anterior;
        // Avança os ponteiros
        anterior = atual;
        atual = proximo;
    }

    // Retorna o novo início da lista
    return anterior;
}

// Função principal para teste
int main()
{
    Lista *L1 = criaLista();

    // Inserindo valores na lista L1
    L1 = insereNoLista(L1, 10);
    L1 = insereNoLista(L1, 20);
    L1 = insereNoLista(L1, 30);

    printf("Lista L1 antes da inversa:\n");
    imprimir(L1);

    // Invertendo a lista L1
    L1 = inverterLista(L1);

    printf("Lista L1 depois da inversao:\n");
    imprimir(L1);

    return 0;
}
