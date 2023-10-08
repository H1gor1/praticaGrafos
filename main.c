#include <stdio.h>
#include <stdlib.h>
#include "graphListAdj.h"
#include "graphMatAdj.h"

int main() {
    int escolha, escolhamenu;
    int vertices;
    int vert1, vert2;
    float n, m;
    float densidade;
    int maxArestas, temCiclo;

    graph grafoMat;
    Grafo *grafoLista;


    do {
        printf("\nDigite o que deseja fazer: \n"
                    "1- Criar os grafos\n"
                    "2- Inserir arestas\n"
                    "3- Verificar qual estrutura eh melhor\n"
                    "4- Verificar grafo completo\n"
                    "5- Verificar grafo ciclico\n"
                    "6- Sair\n");

        scanf("%d", &escolhamenu);

        switch (escolhamenu) {
            case 1:
                printf("Quantos vertices tem o grafo(max de 10): ");
                scanf("%d", &vertices);

                printf("\nEscolha como deseja o grafo: \n"
                       "0- Grafo nao direcionado\n"
                       "1- Grafo direcionado\n");
                scanf("%d", &escolha);

                grafoLista = criarGrafo(vertices, escolha);
                criaGrafo(&grafoMat, vertices, escolha);
                break;
            case 2:
                printf("Digite os vertices: ");
                scanf("%d", &vert1);
                scanf("%d", &vert2);

                adicionarAresta(grafoLista, vert1, vert2);
                if(escolha == 0){
                    insereArestaNDir(&grafoMat, vert1, vert2);
                } else{
                    insereArestaDir(&grafoMat, vert1, vert2);
                }
                break;
            case 3:
                n = grafoMat.vertices;
                m = grafoMat.arestas;

                if(grafoMat.direcionado = NAO_DIRECIONADO){
                    //nao direcionado
                    densidade = (2 * m) / (n * (n - 1));
                } else {
                    //direcionado
                    densidade = m / (n * (n - 1));
                }

                if(densidade >= 0.5){
                    printf("Para esse grafo o melhor eh MATRIZ DE ADJACENCIAS\n");
                    printf("%f", densidade);
                } else {
                    printf("Para esse grafo o melhor eh LISTA DE ADJACENCIAS\n");
                    printf("%f", densidade);
                }

                break;
            case 4:
                maxArestas = (vertices * (vertices - 1)) / 2;

                if(grafoMat.direcionado == DIRECIONADO){
                    printf("O grafo eh direcionado, logo nao eh possivel verificar se eh completo!\n");
                } else if (maxArestas != grafoMat.arestas){
                    printf("O grafo nao eh completo!\n");
                } else {
                    printf("O grafo eh completo!\n");
                }
                break;
            case 5:
                temCiclo = verificaCiclo(grafoLista);

                if(temCiclo){
                    printf("O grafo tem ciclo.");
                } else {
                    printf("O grafo nao tem ciclo");
                }
                break;
            case 6:
                printf("Saindo...");
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    } while (escolhamenu != 6);

    free(grafoLista->array);
    free(grafoLista);

}
