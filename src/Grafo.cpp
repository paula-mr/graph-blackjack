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


bool Grafo::verificarCiclo(bool* visitado, bool* pilhaRecursao) {

    for (int i=0; i < this->tamanho; i++) {
        if (verificarVerticesAdjacentes(i+1, visitado, pilhaRecursao)) {
            return true;
        }
    }

    return false;
}

bool Grafo::verificarVerticesAdjacentes(int aluno, bool* visitado, bool* pilhaRecursao) {
    if (!visitado[aluno]) {
        visitado[aluno] = true;
        pilhaRecursao[aluno] = true;

        for (auto i : this->time[aluno].comandados) {
            if ((!visitado[i] && verificarVerticesAdjacentes(i, visitado, pilhaRecursao)) || pilhaRecursao[i]) {
                return true;
            }
        }

    }

    pilhaRecursao[aluno] = false;
    return false;
}

void Grafo::inicializarPilha(bool* visitado, stack<int>* pilha) {
    for (int i=1; i < this->tamanho+1; i++) {
        if (!visitado[i]) {
            inserirPilhaTopologica(i, visitado, pilha);
        }
    }
}

void Grafo::inserirPilhaTopologica(int aluno, bool* visitado, stack<int>* pilha) {
    visitado[aluno] = true;

    for (auto i : this->time[aluno].comandados) {
        if (!visitado[i]) {
            inserirPilhaTopologica(i, visitado, pilha);
        }
    }

    pilha->push(aluno);
}

#endif
