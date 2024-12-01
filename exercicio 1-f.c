/*Intercale L1 com a lista L2, gerando a lista L3. considere que L1, L2 e L3 são ordenadas.
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

// Função para inserir um nó no final da lista
Lista *insereNoFinal(Lista *cursor, int valor)
{
    Lista *novoNo = (Lista *)malloc(sizeof(Lista));
    novoNo->info = valor;
    novoNo->prox = NULL;

    if (cursor == NULL)
        return novoNo;

    Lista *p = cursor;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = novoNo;
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

// Função para intercalar duas listas ordenadas (L1 e L2) em L3
Lista *intercalarListasOrdenadas(Lista *L1, Lista *L2)
{
    Lista *L3 = criaLista();

    while (L1 != NULL && L2 != NULL)
    {
        if (L1->info <= L2->info)
        {
            L3 = insereNoFinal(L3, L1->info);
            L1 = L1->prox;
        }
        else
        {
            L3 = insereNoFinal(L3, L2->info);
            L2 = L2->prox;
        }
    }

    // Se ainda houver elementos em L1, adiciona-os em L3
    while (L1 != NULL)
    {
        L3 = insereNoFinal(L3, L1->info);
        L1 = L1->prox;
    }

    // Se ainda houver elementos em L2, adiciona-os em L3
    while (L2 != NULL)
    {
        L3 = insereNoFinal(L3, L2->info);
        L2 = L2->prox;
    }

    return L3;
}

// Função principal para teste
int main()
{
    Lista *L1 = criaLista();
    Lista *L2 = criaLista();
    Lista *L3;

    // Inserindo valores ordenados na lista L1
    L1 = insereNoFinal(L1, 1);
    L1 = insereNoFinal(L1, 3);
    L1 = insereNoFinal(L1, 5);

    // Inserindo valores ordenados na lista L2
    L2 = insereNoFinal(L2, 2);
    L2 = insereNoFinal(L2, 4);
    L2 = insereNoFinal(L2, 6);

    printf("Lista L1:\n");
    imprimir(L1);

    printf("Lista L2:\n");
    imprimir(L2);

    // Intercalando L1 e L2 em L3
    L3 = intercalarListasOrdenadas(L1, L2);

    printf("Lista L3 (intercalada):\n");
    imprimir(L3);

    return 0;
}
