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
        void inverterGrafo(Grafo transposto);
        bool verificarCiclo(bool* visitado, bool* pilhaRecursao);
        bool verificarVerticesAdjacentes(int aluno, bool* visitado, bool* pilhaRecursao);
        void inicializarPilha(bool* visitado, stack<int>* pilha);
        void inserirPilhaTopologica(int aluno, bool* visitado, stack<int>* pilha);
};

#endif
