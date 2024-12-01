/*Gere uma lista L2 onde cada registro contém dois campos de informação: elem contém um elemento de L1,
 e count contém quantas vezes este elemento aparece em L1.
*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para L1
typedef struct No {
    int info;
    struct No *prox;
} Lista;

// Definição da estrutura para L2
typedef struct NoContagem {
    int elem;       // Valor do elemento
    int count;      // Contagem do elemento
    struct NoContagem *prox;
} ListaContagem;

// Função para criar uma nova lista
Lista *criaLista()
{
    return NULL;
}

// Função para criar uma nova lista de contagem
ListaContagem *criaListaContagem()
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

// Função para inserir um nó no final da lista de contagem
ListaContagem *insereNoListaContagem(ListaContagem *cursor, int valor, int contagem)
{
    ListaContagem *novoNo = (ListaContagem *)malloc(sizeof(ListaContagem));
    novoNo->elem = valor;
    novoNo->count = contagem;
    novoNo->prox = NULL;

    if (cursor == NULL)
        return novoNo;

    ListaContagem *p = cursor;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = novoNo;
    return cursor;
}

// Função para contar a frequência de um valor em L1
int contarOcorrencias(Lista *L1, int valor)
{
    int contagem = 0;
    for (Lista *p = L1; p != NULL; p = p->prox)
    {
        if (p->info == valor)
            contagem++;
    }
    return contagem;
}

// Função para verificar se um elemento já está em L2
int existeEmListaContagem(ListaContagem *L2, int valor)
{
    for (ListaContagem *p = L2; p != NULL; p = p->prox)
    {
        if (p->elem == valor)
            return 1;
    }
    return 0;
}

// Função para gerar L2 a partir de L1
ListaContagem *gerarListaContagem(Lista *L1)
{
    ListaContagem *L2 = criaListaContagem();
    Lista *atual = L1;

    while (atual != NULL)
    {
        // Se o elemento não está em L2, calcula sua contagem e adiciona
        if (!existeEmListaContagem(L2, atual->info))
        {
            int contagem = contarOcorrencias(L1, atual->info);
            L2 = insereNoListaContagem(L2, atual->info, contagem);
        }
        atual = atual->prox;
    }

    return L2;
}

// Função para imprimir os elementos da lista L1
void imprimirLista(Lista *inicio)
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

// Função para imprimir os elementos da lista L2
void imprimirListaContagem(ListaContagem *inicio)
{
    if (inicio == NULL)
    {
        printf("Lista Vazia\n");
        return;
    }

    for (ListaContagem *p = inicio; p != NULL; p = p->prox)
    {
        printf("Elemento: %d, Contagem: %d\n", p->elem, p->count);
    }
}

// Função principal para teste
int main()
{
    Lista *L1 = criaLista();
    ListaContagem *L2;

    // Inserindo valores na lista L1
    L1 = insereNoLista(L1, 10);
    L1 = insereNoLista(L1, 20);
    L1 = insereNoLista(L1, 10);
    L1 = insereNoLista(L1, 30);
    L1 = insereNoLista(L1, 20);
    L1 = insereNoLista(L1, 10);

    printf("Lista L1:\n");
    imprimirLista(L1);

    // Gerando L2 a partir de L1
    L2 = gerarListaContagem(L1);

    printf("Lista L2 (elementos e contagem):\n");
    imprimirListaContagem(L2);

    return 0;
}


