//ian melo gonçalves:2412130071
//Caroline lopes martins:2412130073


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} t_no;

typedef struct lista {
    t_no *inicio;
    t_no *fim;
    unsigned int length;
} t_lista;

// 1. Inserir no início
void inserirInicio(t_lista *lista, int valor) {
    if (!lista) return;
    t_no *novo = malloc(sizeof(t_no));
    if (!novo) return;
    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    if (lista->length == 0)
        lista->fim = novo;
    lista->length++;
}

// 2. Inserir no fim
void inserirFim(t_lista *lista, int valor) {
    if (!lista) return;
    t_no *novo = malloc(sizeof(t_no));
    if (!novo) return;
    novo->dado = valor;
    novo->prox = NULL;
    if (lista->length == 0) {
        lista->inicio = lista->fim = novo;
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->length++;
}

// 3. Inserir ordenado
void inserirOrdenado(t_lista *lista, int valor) {
    if (!lista) return;
    t_no *novo = malloc(sizeof(t_no));
    if (!novo) return;
    novo->dado = valor;
    novo->prox = NULL;

    if (lista->length == 0 || valor < lista->inicio->dado) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        if (lista->length == 0) lista->fim = novo;
    } else {
        t_no *atual = lista->inicio;
        while (atual->prox && atual->prox->dado < valor) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
        if (novo->prox == NULL) lista->fim = novo;
    }
    lista->length++;
}

// 4. Deletar início
void deletarInicio(t_lista *lista) {
    if (!lista || lista->length == 0) return;
    t_no *tmp = lista->inicio;
    lista->inicio = lista->inicio->prox;
    free(tmp);
    lista->length--;
    if (lista->length == 0) lista->fim = NULL;
}

// 5. Deletar fim
void deletarFim(t_lista *lista) {
    if (!lista || lista->length == 0) return;
    if (lista->length == 1) {
        free(lista->inicio);
        lista->inicio = lista->fim = NULL;
    } else {
        t_no *atual = lista->inicio;
        while (atual->prox != lista->fim) {
            atual = atual->prox;
        }
        free(lista->fim);
        atual->prox = NULL;
        lista->fim = atual;
    }
    lista->length--;
}
