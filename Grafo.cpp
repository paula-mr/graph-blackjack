#ifndef GRAFO_CPP
#define GRAFO_CPP

#include "Grafo.h"

Grafo::Grafo(int n) {
    this->tamanho = n;
}

Grafo::~Grafo() = default;

void Grafo::adicionarAdjacencia(Pessoa adjacencias[], int u, int v) {
    adjacencias[u].comandados.push_back(v);
}

void Grafo::imprimirGrafo(Pessoa adjacencias[]) {
    for (int v = 0; v < this->tamanho; ++v) {
        cout << "IDADE " << adjacencias[v+1].idade << " ";
        cout << v;
        for (auto x : adjacencias[v+1].comandados)
           cout << "-> " << x;
        printf("\n");
    }
}

#endif
