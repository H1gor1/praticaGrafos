//
// Created by higor on 25/10/2023.
//

#ifndef PRATICAGRAFOS_FILA_H
#define PRATICAGRAFOS_FILA_H

typedef struct TipoCelula *TipoApontador;

typedef struct TipoFila {
    TipoApontador Frente, Tras;
} TipoFila;

typedef struct TipoCelula {
    int node;
    TipoApontador Prox;
} TipoCelula;

void FFVazia(TipoFila *Fila);
int FVazia(TipoFila Fila);
void Enfileira(TipoFila *fila, int vert);
void Desenfileira(TipoFila *Fila);

#endif //PRATICAGRAFOS_FILA_H
