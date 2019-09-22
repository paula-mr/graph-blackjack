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

void Grafo::removerAdjacencia(int u, int v) {
    adjacencias[u].comandados.erase(std::remove(adjacencias[u].comandados.begin(), adjacencias[u].comandados.end(), v), adjacencias[u].comandados.end());
}

#endif
