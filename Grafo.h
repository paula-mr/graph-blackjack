#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

class Grafo {
    public:
        int tamanho;

        Grafo(int n);
        ~Grafo();
        void adicionarAdjacencia(Pessoa adjacencias[], int u, int v);
        void imprimirGrafo(Pessoa adjacencias[]);
};

#endif
