//ian melo gonçalves:2412130071
//caroline lopes martins: 2412130073

#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

struct pilha {
    struct no *topo;
    unsigned int length;
};

void empilha(struct pilha *pilha, int valor) {
    if (!pilha) return;
    struct no *novo = malloc(sizeof(struct no));
    if (!novo) return;
    novo->dado = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->length++;
}

int pop(struct pilha *pilha) {
    if (!pilha || pilha->length == 0) return -1;
    struct no *tmp = pilha->topo;
    int valor = tmp->dado;
    pilha->topo = tmp->prox;
    free(tmp);
    pilha->length--;
    return valor;
}

int topo(struct pilha *pilha) {
    if (!pilha || pilha->length == 0) return -1;
    return pilha->topo->dado;
}
