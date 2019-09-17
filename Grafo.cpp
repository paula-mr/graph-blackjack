#ifndef GRAFO_CPP
#define GRAFO_CPP

#include "Grafo.h"

Grafo::Grafo(int n) {
    this->tamanho = n;
}

Grafo::~Grafo() = default;

void Grafo::adicionarAdjacencia(vector<int> adjacencias[], int u, int v) {
    adjacencias[u].push_back(v);
    adjacencias[v].push_back(u);

}

void Grafo::imprimirGrafo(vector<int> adjacencias[]) {
    for (int v = 0; v < this->tamanho; ++v) {
        cout << v;
        for (auto x : adjacencias[v])
           cout << "-> " << x;
        printf("\n");
    }
}

#endif
