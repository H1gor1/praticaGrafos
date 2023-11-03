//
// Created by higor on 06/10/2023.
//

#include "graphMatAdj.h"
#include "stdio.h"
#include "fila.h"
#include "stdlib.h"
#include "stdio.h"

void criaGrafo(graph *g, int vertices, int dir){
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j)
            g->mat[i][j] = 0;
    }

    g->vertices = vertices;
    g->direcionado = dir;
}

void insereArestaNDir(graph *g, int Vert1, int Vert2){
    if(g->mat[Vert1][Vert2] == 2 || g->mat[Vert2][Vert1] == 2){
        printf("Arestas já existentes\n");
        return;
    }
    g->mat[Vert1][Vert2]+= 1;
    g->mat[Vert2][Vert1]+= 1;
    g->arestas++;
    return;
}

void insereArestaDir(graph *g, int Vert1, int Vert2){
    if(g->mat[Vert1][Vert2] == 1){
        printf("Arestas já existentes\n");
        return;
    }

    g->mat[Vert1][Vert2]+= 1;
    g->arestas++;
    return;
}

BFSResult BFS(graph* g, int initVert) {
    BFSResult result;
    result.d = (int*)malloc(g->vertices * sizeof(int));
    result.pi = (int*)malloc(g->vertices * sizeof(int));
    result.c = (char*)malloc(g->vertices * sizeof(char));

    TipoFila queue;
    FFVazia(&queue);

    for (int i = 0; i < g->vertices; ++i) {
        result.c[i] = 'w';
        result.d[i] = 0;
        result.pi[i] = -1;
    }
    result.c[initVert] = 'g';
    result.d[initVert] = 0;
    Enfileira(&queue, initVert);

    while (!FVazia(queue)) {
        int u = queue.Frente->node;
        for (int i = 0; i < g->vertices; ++i) {
            if (g->mat[u][i] == 1) {
                if (result.c[i] == 'w') {
                    result.c[i] = 'g';
                    result.d[i] = result.d[u] + 1;
                    result.pi[i] = u;
                    Enfileira(&queue, i);
                }
            }
        }
        Desenfileira(&queue);
        result.c[u] = 'b';
    }

    return result;
}

void freeBFSResult(BFSResult result) {
    free(result.d);
    free(result.pi);
    free(result.c);
}

DFSResult DFS(graph *g) {
    DFSResult result;
    result.d = (int*)malloc(g->vertices * sizeof(int));
    result.pi = (int*)malloc(g->vertices * sizeof(int));
    result.c = (char*)malloc(g->vertices * sizeof(char));
    result.f = (int*)malloc(g->vertices * sizeof(int));

    int time = 0;

    for (int i = 0; i < g->vertices; ++i) {
        result.c[i] = 'w';
        result.pi[i] = -1;
    }

    for (int i = 0; i < g->vertices; ++i) {
        if (result.c[i] == 'w') {
            visitaDFS(g, &result, &time, i);
        }
    }

    return result;
}

void visitaDFS(graph *g, DFSResult *result, int *time, int i) {
    result->c[i] = 'g';
    (*time) += 1;
    result->d[i] = *time;

    for (int j = 0; j < g->vertices; ++j) {
        if (g->mat[i][j] == 1) {
            if (result->c[j] == 'w') {
                result->pi[j] = i;
                visitaDFS(g, result, time, j);
            }
        }
    }

    result->c[i] = 'b';
    (*time) += 1;
    result->f[i] = *time;
}

void freeDFSResult(DFSResult result) {
    free(result.d);
    free(result.pi);
    free(result.c);
    free(result.f);
}

void imprimeGrafo(graph g){
    for (int i = 0; i < g.vertices; ++i) {
        for (int j = 0; j < g.vertices; ++j) {
            if(g.mat[i][j] > 0)
                printf("\n[%d,%d] ", i,j);
        }
    }
    printf("\n");
}