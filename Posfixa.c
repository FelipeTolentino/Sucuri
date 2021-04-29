#include <stdio.h>
#include <stdlib.h>

#include "Posfixa.h"
#include "Pilha.h"

/* A função recebe uma fila de objetos em notação infixa e converte (retorna) 
 * a correspondente em notação pós-fixa.
 * Para evitar problemas de vazamento de memória e/ou falha de segmentação, faça 
 * cópia dos objetos. 
 * Lembre-se que a função 'desempilha' (Pilha.h) e 'dequeue' (Fila.h)
 * fazem a desalocação dos objetos(liberaObjeto)
 */
Fila *infixaParaPosfixa(Fila *infixa) {
    Pilha* operadores = criaPilha();
    Fila* saida = criaFila();
    while(tamanhoFila(infixa)){
        Objeto* atualInfixa = front(infixa);
        if (atualInfixa->categoria == FLOAT || atualInfixa->categoria == INT){
            enqueue(saida, copiaObjeto(atualInfixa));
        }
        else if (atualInfixa->categoria == ABRE_PARENTESES){
            empilha(operadores, copiaObjeto(atualInfixa));
        }
        else if (atualInfixa->categoria == FECHA_PARENTESES){
            while(1){
                Objeto* operador = topoPilha(operadores);
                if (operador->categoria == ABRE_PARENTESES){
                    desempilha(operadores);
                    break;
                }
                enqueue(saida, copiaObjeto(operador));
                desempilha(operadores);
            }
        }
        else if(atualInfixa->categoria == 0 || atualInfixa->categoria == 6){
            empilha(operadores, copiaObjeto(atualInfixa));
        }
        else{
            while(1){
                Objeto* operador = topoPilha(operadores);
                if (operador == NULL || operador->valor.vInt < atualInfixa->valor.vInt){
                    break;
                }
                enqueue(saida, copiaObjeto(operador));
                desempilha(operadores);
            }
            empilha(operadores, copiaObjeto(atualInfixa));
        }
        dequeue(infixa);
    }
    while(tamanhoPilha(operadores)){
        Objeto* operador = topoPilha(operadores);
        enqueue(saida, copiaObjeto(operador));
        desempilha(operadores);
    }
    liberaPilha(operadores);
    return saida;
}

void imprimePosFixa(Fila *posfixa) {
    Fila *f = copiaFila(posfixa);
    while(!filaVazia(f)) {
        Objeto *obj = front(f);
        imprimeObjeto(obj, POSFIXA);
        dequeue(f);
    }
    printf("\n");
    liberaFila(f);
}