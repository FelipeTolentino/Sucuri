#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

struct fila {
    Objeto *inicio;
    Objeto *fim;
    int n;
};

Fila *criaFila() {
    Fila *f = mallocSafe(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->n = 0;
    return f;
}

/* Faz a desalocação da fila */
void liberaFila(Fila *f) {
    AVISO(Fila.c: ainda não completei a função 'liberaFila');
    
}

/* Insere um novo objeto a fila */
void enqueue(Fila *f, Objeto *o) {
    AVISO(Fila.c: ainda não completei a função 'enqueue');
    
}

/*Remove (apaga) o primeiro elemento da fila */
void dequeue(Fila *f) {
    AVISO(Fila.c: ainda não completei a função 'dequeue');
    
}

/* Retorna o primeiro elemento da fila */
Objeto *front(Fila *f) {
    AVISO(Fila.c: ainda não completei a função 'front');

    return NULL;
}

/* Verifica se a fila está vazia */
bool filaVazia(Fila *f) {
    return (f==NULL || f->n == 0);
}

/* Retorna o número de elementos na fila */
int tamanhoFila(Fila *f) {
    if (filaVazia(f)) return 0;
    return f->n;
}

/* Retorna uma cópia da fila passada como parâmetro */
Fila *copiaFila(Fila *f) {
    AVISO(Fila.c: ainda não completei a função 'copiaFila');

    return NULL;
}

/* Fução que imprime os elementos da fila 
 * Essa função pode ajudar a detectar problemas nos objetos da fila
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimeFila(Fila *f, int tipo) {

}

/* Função de Alta Ordem que recebe uma fila e uma função (cb).
 * Para cada objeto da fila, aplique a função cb ao objeto.
 */
void converteElementosFila(Fila *f, void (*cb)(Objeto *)) {
    AVISO(Fila.c: ainda não completei a função 'converteElementosFila');
    
}