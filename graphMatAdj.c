//
// Created by higor on 06/10/2023.
//

#include "graphMatAdj.h"
#include "stdio.h"
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

void imprimeGrafo(graph g){
    for (int i = 0; i < g.vertices; ++i) {
        for (int j = 0; j < g.vertices; ++j) {
            if(g.mat[i][j] > 0)
                printf("\n[%d,%d] ", i,j);
        }
    }
    printf("\n");
}