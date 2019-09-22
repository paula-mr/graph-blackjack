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

void Grafo::inverter(Grafo invertido)  {
    for (int i = 1; i < this->tamanho+1; i++) {
        for (auto j : this->time[i].comandados) {
            invertido.adicionarAdjacencia(j, i);
        }

    }
}


bool Grafo::verificarCiclo(bool* visitado, bool* pilhaRecursao) {

    for (int i=0; i < this->tamanho; i++) {
        if (verificarRecorrenciaVerticesAdjacentes(i+1, visitado, pilhaRecursao)) {
            return true;
        }
    }

    return false;
}

bool Grafo::verificarRecorrenciaVerticesAdjacentes(int aluno, bool* visitado, bool* pilhaRecursao) {
    if (!visitado[aluno]) {
        visitado[aluno] = true;
        pilhaRecursao[aluno] = true;

        for (auto i : this->time[aluno].comandados) {
            if ((!visitado[i] && verificarRecorrenciaVerticesAdjacentes(i, visitado, pilhaRecursao)) || pilhaRecursao[i]) {
                return true;
            }
        }

    }

    pilhaRecursao[aluno] = false;
    return false;
}

void Grafo::inicializarPilhaTopologica(bool* visitado, stack<int>* pilha) {
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
