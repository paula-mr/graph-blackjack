#include "Orquestrador.h"

#include <list>
#include <iterator>
#include <algorithm>
#include "Pessoa.h"

void inverterGrafo(Grafo grafo, Grafo transposto, int tamanho);

void commander(Grafo grafo, int aluno) {
    int liderMaisNovo = -1, menorIdade = 1000;

    Pessoa pessoas[grafo.tamanho+1];
    Grafo transposto = Grafo(grafo.tamanho, pessoas);
    inverterGrafo(grafo, transposto, grafo.tamanho+1);

    bool visitado[grafo.tamanho];
    for (int i=0; i < grafo.tamanho; i++) {
        visitado[i+1] = false;
    }

    visitado[aluno] = true;

    list<int> fila;
    fila.push_back(aluno);

    int iterador;
    while (!fila.empty()) {
        iterador = fila.front();
        fila.pop_front();

        if (liderMaisNovo == -1) {
            liderMaisNovo = iterador;
            menorIdade = grafo.adjacencias[iterador].idade;
        } else if (grafo.adjacencias[iterador].idade < menorIdade) {
            liderMaisNovo = iterador;
            menorIdade = grafo.adjacencias[iterador].idade;
        }

        for (auto i : transposto.adjacencias[iterador].comandados) {
            if (!visitado[i]) {
                visitado[i] = true;

                fila.push_back(i);
            }
        }
    }

    if (liderMaisNovo == -1 || liderMaisNovo == aluno) {
        std::cout << "*";
    } else {
        std::cout << liderMaisNovo;
    }
}

void inverterGrafo(Grafo grafo, Grafo transposto, int tamanho)  {
    for (int i = 1; i < tamanho; i++) {
        for (int j = 0; j < grafo.adjacencias[i].comandados.size(); j++) {
            transposto.adicionarAdjacencia(grafo.adjacencias[i].comandados[j], i);
        }

    }
}
