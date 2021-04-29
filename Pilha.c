#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

typedef struct pilha {
    Objeto *inicio;
    int n;
} Pilha;

Pilha *criaPilha(){
    Pilha *p = mallocSafe(sizeof(Pilha));
    p->inicio  = NULL;
    p->n = 0;
    return p;
}

/* Faz a desalocação da pilha */
void liberaPilha(Pilha *p) {
    Objeto* atual = p->inicio;
    while(atual){
        Objeto* auxiliar = atual;
        atual = atual->proximo;
        liberaObjeto(auxiliar);
        auxiliar = NULL;
    }
    free(p);
    p = NULL;
}

/* Insere um novo objeto a pilha */
void empilha(Pilha *p, Objeto *no) {
    if (p->inicio == NULL){
        p->inicio = no;
    }
    else{
        no->proximo = p->inicio;
        p->inicio = no;
    }
    p->n++;
}

/* Remove (apaga) o último elemento da pilha */
void desempilha(Pilha *p){
    if (!p->n) return;
    Objeto* auxiliar = p->inicio;
    p->inicio = p->inicio->proximo;
    liberaObjeto(auxiliar);
    auxiliar = NULL;
    p->n--;
}

/* Retorna o objeto do topo da pilha */
Objeto *topoPilha(Pilha *p){
    return p->inicio;
}

/* Verifica se a pilha está vazia */
bool pilhaVazia(Pilha *p){
    return (p==NULL || p->n == 0);
}

/* Retorna o número de elementos na pilha */
int tamanhoPilha(Pilha *p) {
    if (pilhaVazia(p)) return 0;
    return p->n;
}

/* Fução que imprime os elementos da pilha 
 * Essa função pode ajudar a detectar problemas nos objetos da pilha
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimePilha(Pilha *pilha, int tipo) {
    Objeto* atual = pilha->inicio;
    while(atual){
        printf("\n");
        imprimeObjeto(atual, tipo);
        atual = atual->proximo;
    }
}