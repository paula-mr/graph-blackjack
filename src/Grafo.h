#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Pessoa.h"

using namespace std;

class Grafo {

    public:
        int tamanho;
        Pessoa* adjacencias;

        Grafo(int n, Pessoa* adjacencias);
        ~Grafo();
        void adicionarAdjacencia(int u, int v);
        void removerAdjacencia(int u, int v);
        void imprimir();
};

#endif
