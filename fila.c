//
// Created by higor on 25/10/2023.
//

#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

void FFVazia(TipoFila *Fila){
    Fila->Frente = (TipoCelula*) malloc(sizeof(TipoCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

int FVazia(TipoFila Fila){
    return (Fila.Frente->Prox == NULL);
}

void Enfileira(TipoFila *fila, int vert) {
    TipoCelula *novaCelula = (TipoCelula*) malloc(sizeof(TipoCelula));
    if (novaCelula == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novaCelula->node = vert;
    novaCelula->Prox = NULL;

    if (FVazia(*fila)) {
        fila->Frente->Prox = novaCelula; // Atualiza o próximo do frente
    } else {
        fila->Tras->Prox = novaCelula;
    }

    fila->Tras = novaCelula;
}

void Desenfileira(TipoFila *Fila){
    TipoApontador q;
    if(FVazia(*Fila)){
        printf("Erro fila esta vazia\n");
        return;
    }

    q = Fila->Frente->Prox; // Atualiza o q para o próximo do frente
    Fila->Frente->Prox = q->Prox;
    free(q);
}