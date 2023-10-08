//
// Created by higor on 06/10/2023.
//

#ifndef PRATICAGRAFOS_GRAPHLISTADJ_H
#define PRATICAGRAFOS_GRAPHLISTADJ_H

typedef enum {
    NAO_DIRECIONADO,
    DIRECIONADO
}TipoGrafo;

typedef struct nodeAdjList {
    int destino;
    struct nodeAdjList* proximo;
}nodeAdjList;

typedef struct listaAdj{
    nodeAdjList* cabeca;
}listaAdj;

typedef struct Grafo {
    int numVertices;
    int arestas;
    listaAdj* array;
    TipoGrafo tipo;
} Grafo;

nodeAdjList* criarNodeListAdj(int destino);
Grafo* criarGrafo(int numVertice, TipoGrafo tipo);
void adicionarAresta(Grafo* grafo, int origem, int destino);
void imprimirGrafo(Grafo* grafo);
int DFSUtil(Grafo *grafo, int vertice, int visitados[], int pai);
int verificaCiclo(Grafo* grafo);



#endif //PRATICAGRAFOS_GRAPHLISTADJ_H
