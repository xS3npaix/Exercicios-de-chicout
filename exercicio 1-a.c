/*Dada uma lista sequencial ordenada estática L1, escreva métodos em C que:

Verifique se L1 está ordenada ou não (a ordem pode ser crescente ou decrescente)
*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura com typedef diretamente
typedef struct No {
    int info;
    struct No *prox;
} Lista;

// Função para criar uma nova lista
Lista *criaLista()
{
    return NULL;
}

// Função para inserir um nó na lista
Lista *insereNoLista(Lista *cursor, int valor) //cursor é o ponteiro para o inicio da lista, que atulamente aponta para NULL
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

// Função para remover um nó da lista
Lista *removeNoLista(Lista *ref, int valor)
{
    Lista *ant = NULL;
    Lista *p = ref;

    while (p != NULL && p->info != valor)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) // elemento não encontrado
        return ref;

    // Remove o primeiro elemento
    if (p == ref)
    {
        ref = p->prox;
    }
    else // Remove do meio ou do fim
    {
        ant->prox = p->prox;
    }

    free(p);
    return ref;
}

// Função para liberar a memória da lista
void libera(Lista **lista)
{
    Lista *l = *lista;

    while (l != NULL)
    {
        Lista *aux = l->prox;
        free(l);
        l = aux;
    }

    *lista = NULL;
}

// Função para verificar se a lista está ordenada
int estaOrdenada(Lista *inicio)
{
    if (inicio == NULL || inicio->prox == NULL)
    {
        return 1; // Lista vazia ou com um único elemento está ordenada
    }

    int crescente = 1;
    int decrescente = 1;

    for (Lista *atual = inicio; atual->prox != NULL; atual = atual->prox)
    {
        if (atual->info > atual->prox->info)
        {
            crescente = 0; // Não é crescente
        }
        if (atual->info < atual->prox->info)
        {
            decrescente = 0; // Não é decrescente
        }
    }

    return crescente || decrescente; // Retorna 1 se está ordenada, 0 caso contrário
}

// Função principal para teste
int main()
{
    Lista *noinicial = criaLista();

    // Inserindo valores
    noinicial = insereNoLista(noinicial, 10);
    noinicial = insereNoLista(noinicial, 20);
    noinicial = insereNoLista(noinicial, 30);

    // Imprimindo a lista
    printf("Lista:\n");
    imprimir(noinicial);

    // Verificando se está ordenada
    if (estaOrdenada(noinicial))
    {
        printf("A lista esta ordenada.\n");
    }
    else
    {
        printf("A lista nao está ordenada.\n");
    }

    // Liberando a lista
    libera(&noinicial);

    return 0;
}
