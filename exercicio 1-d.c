/*Inverta L1 colocando o resultado em L2;
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

// Função para verificar se um valor já existe na lista
int existeNaLista(Lista *inicio, int valor)
{
    for (Lista *p = inicio; p != NULL; p = p->prox)
    {
        if (p->info == valor)
        {
            return 1; // Valor já existe
        }
    }
    return 0; // Valor não existe
}

// Função para inverter a lista L1 em L2, eliminando repetidos
Lista *inverterListaSemRepetidos(Lista *L1)
{
    Lista *L2 = criaLista();
    Lista *atual = L1;

    while (atual != NULL)
    {
        // Insere no início de L2 apenas se o valor ainda não estiver em L2
        if (!existeNaLista(L2, atual->info))
        {
            L2 = insereNoLista(L2, atual->info);
        }

        atual = atual->prox;
    }

    return L2;
}

// Função principal para teste
int main()
{
    Lista *L1 = criaLista();
    Lista *L2;

    // Inserindo valores na lista L1 (com repetidos)
    L1 = insereNoLista(L1, 10);
    L1 = insereNoLista(L1, 20);
    L1 = insereNoLista(L1, 30);
    L1 = insereNoLista(L1, 20);
    L1 = insereNoLista(L1, 10);

    printf("Lista L1 (com repetidos):\n");
    imprimir(L1);

    // Invertendo a lista L1 em L2, eliminando repetidos
    L2 = inverterListaSemRepetidos(L1);

    printf("Lista L2 (invertida e sem repetidos):\n");
    imprimir(L2);

    return 0;
}
