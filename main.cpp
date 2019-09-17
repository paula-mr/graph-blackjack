#include "Grafo.h"

int main() {

    int tamanho = 5;
    vector<int> adj[tamanho];

    Grafo grafo = Grafo(tamanho);
    grafo.adicionarAdjacencia(adj, 0, 1);
    grafo.adicionarAdjacencia(adj, 0, 4);
    grafo.adicionarAdjacencia(adj, 1, 2);
    grafo.adicionarAdjacencia(adj, 1, 3);
    grafo.adicionarAdjacencia(adj, 1, 4);
    grafo.adicionarAdjacencia(adj, 2, 3);
    grafo.adicionarAdjacencia(adj, 3, 4);

    grafo.imprimirGrafo(adj);

    return 0;
}
