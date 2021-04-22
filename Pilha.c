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
    AVISO(Pilha.c: ainda não completei a função 'liberaPilha');
    
}

/* Insere um novo objeto a pilha */
void empilha(Pilha *p, Objeto *no) {
    AVISO(Pilha.c: ainda não completei a função 'empilha');
    
}

/* Remove (apaga) o último elemento da pilha */
void desempilha(Pilha *p){
    AVISO(Pilha.c: ainda não completei a função 'desempilha');
    
}

/* Retorna o objeto do topo da pilha */
Objeto *topoPilha(Pilha *p){
    AVISO(Pilha.c: ainda não completei a função 'top');
    return NULL;
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
    
}