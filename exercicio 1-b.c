/*Faça uma cópia da lista L1 em uma outra lista L2;
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

// Função para copiar a lista L1 para L2
Lista *copiaLista(Lista *L1)
{
    Lista *L2 = criaLista();
    Lista *atual = L1;
    Lista *fimL2 = NULL;

    while (atual != NULL)
    {
        Lista *novoNo = (Lista *)malloc(sizeof(Lista));
        novoNo->info = atual->info;
        novoNo->prox = NULL;

        if (L2 == NULL)
        {
            L2 = novoNo;
            fimL2 = novoNo;
        }
        else
        {
            fimL2->prox = novoNo;
            fimL2 = novoNo;
        }

        atual = atual->prox;
    }

    return L2;
}

// Função principal para testar
int main()
{
    Lista *L1 = criaLista();
    Lista *L2;

    // Inserindo valores na lista L1
    L1 = insereNoLista(L1, 10);
    L1 = insereNoLista(L1, 20);
    L1 = insereNoLista(L1, 30);

    printf("Lista L1:\n");
    imprimir(L1);

    // Copiando a lista L1 para L2
    L2 = copiaLista(L1);

    printf("Lista L2 (copia de L1):\n");
    imprimir(L2);

    return 0;
}
