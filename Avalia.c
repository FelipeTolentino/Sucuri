#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Avalia.h"
#include "Categorias.h"
#include "Pilha.h"
#include "Util.h"


/* Recebe uma fila de objetos em notação pós-fixa, avalia e retorna o resultado da expressação */
Objeto *avalia(Fila *posFixa){
    Pilha* execucao = criaPilha();
    Objeto* resultado = criaObjeto();
    while(tamanhoFila(posFixa)){
        Objeto* objPosfixa = front(posFixa);
        if (objPosfixa->categoria == INT || objPosfixa->categoria == FLOAT){
            empilha(execucao, copiaObjeto(objPosfixa));
        }
        else if (objPosfixa->categoria == OPER_MENOS_UNARIO){
            Objeto* operando = topoPilha(execucao);
            if (operando->categoria == FLOAT){
                resultado->valor.vFloat = operando->valor.vFloat * (-1);
                resultado->categoria = FLOAT;
            }
            else{
                resultado->valor.vInt = operando->valor.vInt * (-1);
                resultado->categoria = INT;
            }
            desempilha(execucao);
            empilha(execucao, copiaObjeto(resultado));
        }
        else if (objPosfixa->categoria <= 5){
            Objeto* operando1 = copiaObjeto(topoPilha(execucao));
            desempilha(execucao);
            Objeto* operando2 = copiaObjeto(topoPilha(execucao));
            desempilha(execucao);
            if (objPosfixa->categoria == OPER_EXPONENCIACAO){
                if (operando1->categoria == FLOAT && operando2->categoria == FLOAT){
                    resultado->valor.vFloat = pow(operando2->valor.vFloat, operando1->valor.vFloat);
                    resultado->categoria = FLOAT;
                }
                else if (operando1->categoria == FLOAT){
                    resultado->valor.vFloat = pow(operando2->valor.vInt, operando1->valor.vFloat);
                    resultado->categoria = FLOAT;
                }
                else if (operando2->categoria == FLOAT){
                    resultado->valor.vFloat = pow(operando2->valor.vFloat, operando1->valor.vInt);
                    resultado->categoria = FLOAT;
                }
                else{
                    resultado->valor.vInt = pow(operando2->valor.vInt, operando1->valor.vInt);
                    resultado->categoria = INT;
                }
            }
            else if (objPosfixa->categoria == OPER_RESTO_DIVISAO){
                if (operando1->categoria == FLOAT && operando2->categoria == FLOAT){
                    resultado->valor.vFloat = fmod(operando2->valor.vFloat, operando1->valor.vFloat);
                    resultado->categoria = FLOAT;
                }
                else if (operando1->categoria == FLOAT){
                    resultado->valor.vFloat = fmod(operando2->valor.vInt, operando1->valor.vFloat);
                    resultado->categoria = FLOAT;
                }
                else if (operando2->categoria == FLOAT){
                    resultado->valor.vFloat = fmod(operando2->valor.vFloat, operando1->valor.vInt);
                    resultado->categoria = FLOAT;
                }
                else{
                    resultado->valor.vInt = operando2->valor.vInt % operando1->valor.vInt;
                    resultado->categoria = INT;
                }
            }
            else if (objPosfixa->categoria == OPER_MULTIPLICACAO ){
                if (operando1->categoria == FLOAT && operando2->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vFloat * operando1->valor.vFloat;
                    resultado->categoria = FLOAT;
                }
                else if (operando1->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vInt * operando1->valor.vFloat;
                    resultado->categoria = FLOAT;
                }
                else if (operando2->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vFloat * operando1->valor.vInt;
                    resultado->categoria = FLOAT;
                }
                else{
                    resultado->valor.vInt = operando2->valor.vInt * operando1->valor.vInt;
                    resultado->categoria = INT;
                }
            }
            else if (objPosfixa->categoria == OPER_DIVISAO){
                if (operando1->categoria == FLOAT && operando2->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vFloat / operando1->valor.vFloat;
                    resultado->categoria = FLOAT;
                }
                else if (operando1->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vInt / operando1->valor.vFloat;
                    resultado->categoria = FLOAT;
                }
                else if (operando2->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vFloat / operando1->valor.vInt;
                    resultado->categoria = FLOAT;
                }
                else{
                    resultado->valor.vInt = operando2->valor.vInt / operando1->valor.vInt;
                    resultado->categoria = INT;
                }
            }
            else if (objPosfixa->categoria == OPER_ADICAO){
                if (operando1->categoria == FLOAT && operando2->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vFloat + operando1->valor.vFloat;
                    resultado->categoria = FLOAT;
                }
                else if (operando1->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vInt + operando1->valor.vFloat;
                    resultado->categoria = FLOAT;
                }
                else if (operando2->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vFloat + operando1->valor.vInt;
                    resultado->categoria = FLOAT;
                }
                else{
                    resultado->valor.vInt = operando2->valor.vInt + operando1->valor.vInt;
                    resultado->categoria = INT;
                }
            }
            else if (objPosfixa->categoria == OPER_SUBTRACAO){
                if (operando1->categoria == FLOAT && operando2->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vFloat - operando1->valor.vFloat;
                    resultado->categoria = FLOAT;
                }
                else if (operando1->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vInt - operando1->valor.vFloat;
                    resultado->categoria = FLOAT;
                }
                else if (operando2->categoria == FLOAT){
                    resultado->valor.vFloat = operando2->valor.vFloat - operando1->valor.vInt;
                    resultado->categoria = FLOAT;
                }
                else{
                    resultado->valor.vInt = operando2->valor.vInt - operando1->valor.vInt;
                    resultado->categoria = INT;
                }
            }
            
            liberaObjeto(operando1);
            liberaObjeto(operando2);
            empilha(execucao, copiaObjeto(resultado));
        }
        dequeue(posFixa);
    }
    liberaObjeto(resultado);
    resultado = copiaObjeto(topoPilha(execucao));
    liberaPilha(execucao);
    return resultado;
}
