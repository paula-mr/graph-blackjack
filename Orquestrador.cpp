#include "Orquestrador.h"

#include <stack>
#include <list>
#include <iterator>
#include <algorithm>
#include "Pessoa.h"

void inverterGrafo(Grafo grafo, Grafo transposto, int tamanho);
void inicializarVisitados(bool* visitado, int tamanho);
void inserirPilhaTopologica(int aluno, bool* visitado, Grafo grafo, stack<int>* pilha);
void iniciarPilha(bool* visitado, Grafo grafo, stack<int>* pilha);
void imprimirPilha(stack<int>* pilha);
bool verificarCiclo(Grafo grafo);
bool verificarVerticesAdjacentes(int aluno, bool* visitado, bool* pilhaRecursao, Grafo grafo);
bool contem(vector<int> lista, int item);

void swap(Grafo grafo, int aluno1, int aluno2) {
    if (contem(grafo.adjacencias[aluno1].comandados, aluno2)) {
        grafo.removerAdjacencia(aluno1, aluno2);
        grafo.adicionarAdjacencia(aluno2, aluno1);

        if (verificarCiclo(grafo)) {
            grafo.removerAdjacencia(aluno2, aluno1);
            grafo.adicionarAdjacencia(aluno1, aluno2);

            std::cout << "S N" << std::endl;
        } else {
            std::cout << "S T" << std::endl;
        }
    } else if (contem(grafo.adjacencias[aluno2].comandados, aluno1)) {
        grafo.removerAdjacencia(aluno2, aluno1);
        grafo.adicionarAdjacencia(aluno1, aluno2);

        if (verificarCiclo(grafo)) {
            grafo.removerAdjacencia(aluno1, aluno2);
            grafo.adicionarAdjacencia(aluno2, aluno1);

            std::cout << "S N" << std::endl;
        } else {
            std::cout << "S T" << std::endl;
        }
    } else {
        std::cout << "S N" << std::endl;
    }
}

bool contem(vector<int> lista, int item) {
    for (auto i : lista) {
        if (i == item)
            return true;
    }

    return false;
}

bool verificarCiclo(Grafo grafo) {
    bool visitado[grafo.tamanho], pilhaRecursao[grafo.tamanho];

    inicializarVisitados(visitado, grafo.tamanho);
    inicializarVisitados(pilhaRecursao, grafo.tamanho);

    for (int i=0; i < grafo.tamanho; i++) {
        if (verificarVerticesAdjacentes(i+1, visitado, pilhaRecursao, grafo)) {
            return true;
        }
    }

    return false;
}

bool verificarVerticesAdjacentes(int aluno, bool* visitado, bool* pilhaRecursao, Grafo grafo) {
    if (!visitado[aluno]) {
        visitado[aluno] = true;
        pilhaRecursao[aluno] = true;

        for (auto i : grafo.adjacencias[aluno].comandados) {
            if ((!visitado[i] && verificarVerticesAdjacentes(i, visitado, pilhaRecursao, grafo)) || pilhaRecursao[i]) {
                return true;
            }
        }

    }

    pilhaRecursao[aluno] = false;
    return false;
}

void meeting(Grafo grafo) {
    stack<int> pilha;
    bool visitado[grafo.tamanho];

    inicializarVisitados(visitado, grafo.tamanho);
    iniciarPilha(visitado, grafo, &pilha);

    imprimirPilha(&pilha);

}

void iniciarPilha(bool* visitado, Grafo grafo, stack<int>* pilha) {
    for (int i=1; i < grafo.tamanho+1; i++) {
        if (!visitado[i]) {
            inserirPilhaTopologica(i, visitado, grafo, pilha);
        }
    }
}

void inserirPilhaTopologica(int aluno, bool* visitado, Grafo grafo, stack<int>* pilha) {
    visitado[aluno] = true;

    for (auto i : grafo.adjacencias[aluno].comandados) {
        if (!visitado[i]) {
            inserirPilhaTopologica(i, visitado, grafo, pilha);
        }
    }

    pilha->push(aluno);
}

void imprimirPilha(stack<int>* pilha) {
    while (!pilha->empty()) {
        std::cout << pilha->top() << " ";
        pilha->pop();
    }

    std::cout << endl;
}

void commander(Grafo grafo, int aluno) {
    int liderMaisNovo = -1, menorIdade = 1000;
    bool visitado[grafo.tamanho];
    list<int> fila;
    Pessoa pessoas[grafo.tamanho+1];
    Grafo transposto = Grafo(grafo.tamanho, pessoas);

    inverterGrafo(grafo, transposto, grafo.tamanho+1);
    inicializarVisitados(visitado, grafo.tamanho);
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

void inicializarVisitados(bool* visitado, int tamanho) {
    for (int i=0; i < tamanho; i++) {
        visitado[i+1] = false;
    }
}

void inverterGrafo(Grafo grafo, Grafo transposto, int tamanho)  {
    for (int i = 1; i < tamanho; i++) {
        for (unsigned int j = 0; j < grafo.adjacencias[i].comandados.size(); j++) {
            transposto.adicionarAdjacencia(grafo.adjacencias[i].comandados[j], i);
        }

    }
}
