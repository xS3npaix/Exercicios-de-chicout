/*Assumindo que os elementos da lista L1 são inteiros positivos, forneça os elementos que
 aparecem o maior e o menor número de vezes (forneça os elementos e o número de vezes correspondente)*/

 #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Função para contar as ocorrências de um valor em L1
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

// Função para verificar se um valor já foi contado
int jaContado(Lista *valoresContados, int valor)
{
    for (Lista *p = valoresContados; p != NULL; p = p->prox)
    {
        if (p->info == valor)
            return 1;
    }
    return 0;
}

// Função para encontrar o maior e o menor número de vezes
void encontrarMaiorEMenor(Lista *L1)
{
    Lista *valoresContados = criaLista();
    int maiorFrequencia = INT_MIN;
    int menorFrequencia = INT_MAX;
    int valorMaiorFreq, valorMenorFreq;

    for (Lista *p = L1; p != NULL; p = p->prox)
    {
        // Se o valor já foi contado, pula para o próximo
        if (jaContado(valoresContados, p->info))
            continue;

        // Conta as ocorrências do valor atual
        int frequencia = contarOcorrencias(L1, p->info);

        // Adiciona o valor na lista de valores contados
        valoresContados = insereNoFinal(valoresContados, p->info);

        // Atualiza o maior e o menor valor e suas frequências
        if (frequencia > maiorFrequencia)
        {
            maiorFrequencia = frequencia;
            valorMaiorFreq = p->info;
        }

        if (frequencia < menorFrequencia)
        {
            menorFrequencia = frequencia;
            valorMenorFreq = p->info;
        }
    }

    // Imprime os resultados
    printf("Elemento com maior frequencia: %d (aparece %d vezes)\n", valorMaiorFreq, maiorFrequencia);
    printf("Elemento com menor frequencia: %d (aparece %d vezes)\n", valorMenorFreq, menorFrequencia);
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

// Função principal para teste
int main()
{
    Lista *L1 = criaLista();

    // Inserindo valores na lista L1
    L1 = insereNoFinal(L1, 10);
    L1 = insereNoFinal(L1, 20);
    L1 = insereNoFinal(L1, 10);
    L1 = insereNoFinal(L1, 30);
    L1 = insereNoFinal(L1, 20);
    L1 = insereNoFinal(L1, 10);

    printf("Lista L1:\n");
    imprimirLista(L1);

    // Encontrando maior e menor frequências
    encontrarMaiorEMenor(L1);

    return 0;
}
