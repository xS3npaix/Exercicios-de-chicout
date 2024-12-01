/*Crie uma outra função que garanta a inserção de números em ordem decrescente.
 Inspire-se na letra anterior;
*/


#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_MAXIMO 50

// Definição da lista estática
typedef struct {
    int dados[TAMANHO_MAXIMO];
    int tamanho; // Quantidade de elementos na lista
} ListaEstatica;

// Função para inicializar a lista
void inicializarLista(ListaEstatica *lista)
{
    lista->tamanho = 0;
}

// Função para verificar se a lista está cheia
bool listaCheia(ListaEstatica *lista)
{
    return lista->tamanho == TAMANHO_MAXIMO;
}

// Função para imprimir a lista
void imprimirLista(ListaEstatica *lista)
{
    if (lista->tamanho == 0)
    {
        printf("Lista Vazia\n");
        return;
    }

    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

// Função para inserir um elemento na lista de forma decrescente
bool inserirDecrescente(ListaEstatica *lista, int valor)
{
    if (listaCheia(lista))
    {
        printf("Erro: Lista está cheia, não é possível inserir %d.\n", valor);
        return false;
    }

    int i;

    // Encontrar a posição para inserir o novo valor
    for (i = 0; i < lista->tamanho; i++)
    {
        if (lista->dados[i] < valor)
        {
            break;
        }
    }

    // Deslocar elementos para abrir espaço
    for (int j = lista->tamanho; j > i; j--)
    {
        lista->dados[j] = lista->dados[j - 1];
    }

    // Inserir o novo valor na posição correta
    lista->dados[i] = valor;
    lista->tamanho++;

    return true;
}

// Função principal para teste
int main()
{
    ListaEstatica lista;

    // Inicializando a lista
    inicializarLista(&lista);

    // Inserindo valores na lista em ordem decrescente
    inserirDecrescente(&lista, 20);
    inserirDecrescente(&lista, 10);
    inserirDecrescente(&lista, 30);
    inserirDecrescente(&lista, 25);
    inserirDecrescente(&lista, 5);

    // Imprimindo a lista ordenada
    printf("Lista em ordem decrescente:\n");
    imprimirLista(&lista);

    return 0;
}
