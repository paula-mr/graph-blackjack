#ifndef GRAFO_CPP
#define GRAFO_CPP

#include "Grafo.h"

Grafo::Grafo(int n, Pessoa* adjacencias) {
    this->tamanho = n;
    this->adjacencias = adjacencias;
}

Grafo::~Grafo() = default;

void Grafo::adicionarAdjacencia(int u, int v) {
    adjacencias[u].comandados.push_back(v);
}

void Grafo::imprimir() {
    for (int v = 0; v < this->tamanho; ++v) {
        cout << "IDADE " << adjacencias[v+1].idade << " ";
        cout << v+1;
        for (auto x : adjacencias[v+1].comandados)
           cout << "-> " << x;
        printf("\n");
    }
}

#endif
