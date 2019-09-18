#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

class Grafo {
    private:
        int tamanho;

    public:
        Pessoa* adjacencias;

        Grafo(int n, Pessoa* adjacencias);
        ~Grafo();
        void adicionarAdjacencia(int u, int v);
        void imprimir();
};

#endif
