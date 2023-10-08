//
// Created by higor on 06/10/2023.
//

#include "graphListAdj.h"
#include "stdlib.h"
#include "stdio.h"

nodeAdjList* criarNodeListAdj(int destino){
    nodeAdjList* novoNo = (nodeAdjList*)malloc(sizeof(nodeAdjList));
    novoNo->destino = destino;
    novoNo->proximo = NULL;
    return novoNo;
}

Grafo* criarGrafo(int numVertice, TipoGrafo tipo){
    Grafo* grafo = (Grafo*) malloc(sizeof (Grafo));
    grafo->numVertices = numVertice;
    grafo->array = (listaAdj*) malloc(numVertice * sizeof (listaAdj));
    grafo->tipo = tipo;

    for (int i = 0; i < numVertice; ++i) {
        grafo->array[i].cabeca = NULL;
    }
    return grafo;
};

void adicionarAresta(Grafo* grafo, int origem, int destino){
    nodeAdjList* newNode = criarNodeListAdj(destino);
    newNode->proximo = grafo->array[origem].cabeca;
    grafo->array[origem].cabeca = newNode;

    if(grafo->tipo == NAO_DIRECIONADO){
        nodeAdjList* newNodeReverse = criarNodeListAdj(origem);
        newNodeReverse->proximo = grafo->array[destino].cabeca;
        grafo->array[destino].cabeca = newNodeReverse;
    }

    grafo->arestas++;
}

int DFSUtil(Grafo *grafo, int vertice, int visitados[], int pai){
    visitados[vertice] = 1;

    nodeAdjList* atual = grafo->array[vertice].cabeca;
    while (atual != NULL){
        int vizinho = atual->destino;
        if(!visitados[vizinho]){
            if(DFSUtil(grafo, vizinho, visitados, vertice)){
                return 1; //achou ciclo
            }
        }else if(vizinho != pai){
            return 1; //achou ciclo
        }
        atual = atual->proximo;
    }
    return 0; //nao achou ciclo
}

int verificaCiclo(Grafo* grafo){
    int* visitados = (int*) malloc(sizeof(int) * grafo->numVertices);
    for (int i = 0; i < grafo->numVertices; ++i) {
        visitados[i] = 0;
    }

    for (int i = 0; i < grafo->numVertices; ++i) {
        if(!visitados[i]){
            if(DFSUtil(grafo, i, visitados, -1)){
                free(visitados);
                return 1; //achou ciclo
            }
        }
    }

    free(visitados);
    return 0; //nao achou ciclo
}

void imprimirGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; ++i) {
        nodeAdjList* atual = grafo->array[i].cabeca;
        printf("Lista de adjacência do vértice %d: ", i);
        while (atual) {
            printf("%d -> ", atual->destino);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}