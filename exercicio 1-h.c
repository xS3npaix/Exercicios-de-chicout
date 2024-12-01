/*Elimine de L1 todas as ocorrências de um elemento dado, L1 ordenada.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista
typedef struct No {
    int info;
    struct No *prox;
} Lista;

// Função para criar uma nova lista
Lista *criaLista()
{
    return NULL;
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
void imprimirLista(Lista *inicio)
{
    if (inicio == NULL)
    {
        printf("Lista Vazia\n");
        return;
    }

    for (Lista *p = inicio; p != NULL; p = p->prox)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}

// Função para remover todas as ocorrências de um elemento em L1
Lista *removerElemento(Lista *L1, int valor)
{
    Lista *atual = L1;
    Lista *anterior = NULL;

    while (atual != NULL)
    {
        // Se o valor atual é igual ao elemento a ser removido
        if (atual->info == valor)
        {
            // Caso o nó a ser removido seja o primeiro da lista
            if (anterior == NULL)
            {
                Lista *temp = atual;
                atual = atual->prox;
                free(temp);
                L1 = atual; // Atualiza o início da lista
            }
            else
            {
                // Remove o nó intermediário ou final
                Lista *temp = atual;
                anterior->prox = atual->prox;
                atual = atual->prox;
                free(temp);
            }
        }
        else
        {
            // Avança o ponteiro
            anterior = atual;
            atual = atual->prox;
        }
    }

    return L1;
}

// Função principal para teste
int main()
{
    Lista *L1 = criaLista();

    // Inserindo valores na lista L1 (ordenada)
    L1 = insereNoFinal(L1, 10);
    L1 = insereNoFinal(L1, 20);
    L1 = insereNoFinal(L1, 20);
    L1 = insereNoFinal(L1, 30);
    L1 = insereNoFinal(L1, 40);
    L1 = insereNoFinal(L1, 40);
    L1 = insereNoFinal(L1, 50);

    printf("Lista L1 antes de remover elemento:\n");
    imprimirLista(L1);

    // Removendo todas as ocorrências de um elemento
    int valorRemover = 20;
    L1 = removerElemento(L1, valorRemover);

    printf("Lista L1 depois de remover elemento %d:\n", valorRemover);
    imprimirLista(L1);

    return 0;
}
