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
    Objeto* atual = f->inicio;
    while(atual){
        Objeto* aux = atual;
        atual = atual->proximo;
        liberaObjeto(aux);
    }
    free(f);
}

/* Insere um novo objeto a fila */
void enqueue(Fila *f, Objeto *o) {
    if (f->inicio == NULL){
        f->inicio = f->fim = o;
    }
    else{
        f->fim->proximo = o;
        f->fim = o;
    }
    f->n++;
}

/*Remove (apaga) o primeiro elemento da fila */
void dequeue(Fila *f) {
    if (f->inicio == NULL)
        return;
    Objeto* auxiliar = f->inicio;
    f->inicio = f->inicio->proximo;
    liberaObjeto(auxiliar);
    auxiliar = NULL;
    f->n--;
}

/* Retorna o primeiro elemento da fila */
Objeto *front(Fila *f) {
    return (f->inicio == NULL) ? NULL : f->inicio;
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
    Fila* novaFila = criaFila();
    Objeto* atual = f->inicio;
    while(atual){
        enqueue(novaFila, copiaObjeto(atual));
        atual = atual->proximo;
    }
    return novaFila;
}

/* Fução que imprime os elementos da fila 
 * Essa função pode ajudar a detectar problemas nos objetos da fila
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimeFila(Fila *f, int tipo) {
    Objeto* atual = f->inicio;
    while(atual){
        printf("\n");
        imprimeObjeto(atual, tipo);
        atual = atual->proximo;
    }
}

/* Função de Alta Ordem que recebe uma fila e uma função (cb).
 * Para cada objeto da fila, aplique a função cb ao objeto.
 */
void converteElementosFila(Fila *f, void (*cb)(Objeto *)) {
    Objeto* atual = f->inicio;
    while(atual){
        cb(atual);
        atual = atual->proximo;
    }
}