#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#include "Pessoa.h"

class Grafo {

    public:
        int tamanho;
        Pessoa* time;

        Grafo(int n, Pessoa* time);
        ~Grafo();
        void adicionarAdjacencia(int u, int v);
        void removerAdjacencia(int u, int v);
        void inverter(Grafo invertido);
        bool verificarCiclo(bool* visitado, bool* pilhaRecursao);
        bool verificarRecorrenciaVerticesAdjacentes(int aluno, bool* visitado, bool* pilhaRecursao);
        void inicializarPilhaTopologica(bool* visitado, stack<int>* pilha);
        void inserirPilhaTopologica(int aluno, bool* visitado, stack<int>* pilha);
};

#endif
