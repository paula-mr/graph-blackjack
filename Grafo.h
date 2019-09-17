#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>

using namespace std;

class Grafo {
    public:
        int tamanho;

        Grafo(int n);
        ~Grafo();
        void adicionarAdjacencia(vector<int> adjacencias[], int u, int v);
        void imprimirGrafo(vector<int> adjacencias[]);
};

#endif
