#ifndef GRAFO_CPP
#define GRAFO_CPP

#include "Grafo.h"

Grafo::Grafo(int n, Pessoa* time) {
    this->tamanho = n;
    this->time = time;
}

Grafo::~Grafo() = default;

void Grafo::adicionarAdjacencia(int u, int v) {
    time[u].comandados.push_back(v);
}

void Grafo::removerAdjacencia(int u, int v) {
    time[u].comandados.erase(std::remove(time[u].comandados.begin(), time[u].comandados.end(), v), time[u].comandados.end());
}

void Grafo::inverterGrafo(Grafo transposto)  {
    for (int i = 1; i < this->tamanho+1; i++) {
        for (auto j : this->time[i].comandados) {
            transposto.adicionarAdjacencia(j, i);
        }

    }
}

#endif
