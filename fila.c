//ian melo gonçalves:2412130071
//caroline lopes martins: 2412130073



#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};


struct fila {
    struct no *inicio;
    struct no *fim;
    unsigned int length;
};

void enfileira(struct fila *fila, int valor) {
    if (!fila) return;
    struct no *novo = malloc(sizeof(struct no));
    if (!novo) return;
    novo->dado = valor;
    novo->prox = NULL;
    if (fila->length == 0) {
        fila->inicio = fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->length++;
}

int desenfileira(struct fila *fila) {
    if (!fila || fila->length == 0) return -1;
    struct no *tmp = fila->inicio;
    int valor = tmp->dado;
    fila->inicio = tmp->prox;
    if (fila->inicio == NULL)
        fila->fim = NULL;
    free(tmp);
    fila->length--;
    return valor;
}
