//
// Created by higor on 06/10/2023.
//

#ifndef PRATICAGRAFOS_GRAPHMATADJ_H
#define PRATICAGRAFOS_GRAPHMATADJ_H

#define max 10
#define TRUE 7
#define FALSE 8

typedef struct graph{
    int mat[max][max];
    int vertices;
    int arestas;
    int direcionado; //0= nao eh direcionado 1= eh direcionado
}graph;


typedef struct BFSResult{
    int* d;
    int* pi;
    char* c;
} BFSResult;

typedef struct DFSResult{
    int* d;
    int* pi;
    char* c;
    int* f;
} DFSResult;

void criaGrafo(graph *g, int vertices, int dir);
void insereArestaNDir(graph *g, int Vert1, int Vert2);
void insereArestaDir(graph *g, int Vert1, int Vert2);
void imprimeGrafo(graph g);
BFSResult BFS(graph* g, int initVert);
void freeBFSResult(BFSResult result);
DFSResult DFS(graph *g);
void visitaDFS(graph *g, DFSResult *result, int *time, int i);
void freeDFSResult(DFSResult result);

#endif //PRATICAGRAFOS_GRAPHMATADJ_H
