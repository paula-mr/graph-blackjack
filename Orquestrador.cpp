#include "Orquestrador.h"

#include <list>
#include <iterator>
#include <algorithm>
#include "Pessoa.h"

void inverterGrafo(Grafo grafo, Grafo transposto, int tamanho);
void inicializarListaVisitados(bool* visitado, int tamanho);

void meeting(Grafo grafo) {
    bool visitado[grafo.tamanho];
    inicializarListaVisitados(visitado, grafo.tamanho);


}

void commander(Grafo grafo, int aluno) {
    int liderMaisNovo = -1, menorIdade = 1000;
    bool visitado[grafo.tamanho];
    list<int> fila;
    Pessoa pessoas[grafo.tamanho+1];
    Grafo transposto = Grafo(grafo.tamanho, pessoas);

    inverterGrafo(grafo, transposto, grafo.tamanho+1);
    inicializarListaVisitados(visitado, grafo.tamanho);
    visitado[aluno] = true;

    fila.push_back(aluno);

    int iterador;
    while (!fila.empty()) {
        iterador = fila.front();
        fila.pop_front();

        if (liderMaisNovo == -1 || grafo.adjacencias[iterador].idade < menorIdade) {
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
        std::cout << "C *" << endl;
    } else {
        std::cout << "C " << liderMaisNovo << endl;
    }
}

void inicializarListaVisitados(bool* visitado, int tamanho) {
    for (int i=0; i < tamanho; i++) {
        visitado[i+1] = false;
    }
}

void inverterGrafo(Grafo grafo, Grafo transposto, int tamanho)  {
    for (int i = 1; i < tamanho; i++) {
        for (int j = 0; j < grafo.adjacencias[i].comandados.size(); j++) {
            transposto.adicionarAdjacencia(grafo.adjacencias[i].comandados[j], i);
        }

    }
}
