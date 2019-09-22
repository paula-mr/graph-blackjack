#ifndef ORQUESTRADOR_CPP
#define ORQUESTRADOR_CPP

#include "Orquestrador.h"
#include "Pessoa.h"

#include <stack>
#include <list>
#include <iterator>
#include <algorithm>

void inicializarVisitados(bool* visitado, int tamanho);
void imprimirPilha(stack<int>* pilha);
void realizarTroca(Grafo grafo, int aluno1, int aluno2);

void swap(Grafo grafo, int aluno1, int aluno2) {
    int comandante, comandado;

    //verifica se o aluno2 esta contido na lista de comandados do aluno1
    if (grafo.time[aluno1].comanda(aluno2)) {
        comandante = aluno1;
        comandado = aluno2;
    //verifica se o aluno1 esta contido na lista de comandados do aluno2
    } else if (grafo.time[aluno2].comanda(aluno1)) {
        comandante = aluno2;
        comandado = aluno1;
    } else {
        std::cout << "S N" << std::endl;
        return;
    }

    realizarTroca(grafo, comandante, comandado);

    bool visitado[grafo.tamanho], pilhaRecursao[grafo.tamanho];
    inicializarVisitados(visitado, grafo.tamanho);
    inicializarVisitados(pilhaRecursao, grafo.tamanho);

    if (grafo.verificarCiclo(visitado, pilhaRecursao)) {
        //destroca comandante com comandado caso a troca cause um ciclo
        realizarTroca(grafo, comandado, comandante);
        std::cout << "S N" << std::endl;
    } else {
        std::cout << "S T" << std::endl;
    }
}

void realizarTroca(Grafo grafo, int aluno1, int aluno2) {
    grafo.removerAdjacencia(aluno1, aluno2);
    grafo.adicionarAdjacencia(aluno2, aluno1);
}

void meeting(Grafo grafo) {
    stack<int> pilha;
    bool visitado[grafo.tamanho];
    inicializarVisitados(visitado, grafo.tamanho);

    grafo.inicializarPilhaTopologica(visitado, &pilha);

    std::cout << "M ";

    imprimirPilha(&pilha);

}

void imprimirPilha(stack<int>* pilha) {
    while (!pilha->empty()) {
        std::cout << pilha->top() << " ";
        pilha->pop();
    }

    std::cout << endl;
}

void commander(Grafo grafo, int aluno) {
    int liderMaisNovo = -1, menorIdade;
    bool visitado[grafo.tamanho];
    list<int> fila;
    Pessoa pessoas[grafo.tamanho+1];

    //inverte o grafo
    Grafo transposto = Grafo(grafo.tamanho, pessoas);
    grafo.inverterGrafo(transposto);

    inicializarVisitados(visitado, grafo.tamanho);
    visitado[aluno] = true;

    fila.push_back(aluno);

    int iterador;
    while (!fila.empty()) {
        iterador = fila.front();
        fila.pop_front();

        //verifica se o aluno atual eh mais novo que o lider cadastrado
        if (liderMaisNovo == -1 || grafo.time[iterador].idade < menorIdade) {
            liderMaisNovo = iterador;
            menorIdade = grafo.time[iterador].idade;
        }

        //adiciona os comandados que ainda nao foram visitados do aluno atual
        for (auto i : transposto.time[iterador].comandados) {
            if (!visitado[i]) {
                visitado[i] = true;
                fila.push_back(i);
            }
        }
    }


    if (liderMaisNovo == -1 || liderMaisNovo == aluno) {
        std::cout << "C *" << endl;
    } else {
        std::cout << "C " << grafo.time[liderMaisNovo].idade << endl;
    }
}

void inicializarVisitados(bool* visitado, int tamanho) {
    for (int i=0; i < tamanho; i++) {
        visitado[i+1] = false;
    }
}

#endif
