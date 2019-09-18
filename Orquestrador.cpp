#include "Orquestrador.h"

#include <list>
#include <iterator>
#include <algorithm>
#include "Pessoa.h"

void inverterGrafo(Grafo grafo, Grafo transposto, int tamanho);

void commander(Grafo grafo, int aluno) {
    Pessoa pessoas[grafo.tamanho+1];
    Grafo transposto = Grafo(grafo.tamanho, pessoas);
    inverterGrafo(grafo, transposto, grafo.tamanho+1);


}

void inverterGrafo(Grafo grafo, Grafo transposto, int tamanho)  {
    for (int i = 1; i < tamanho; i++) {
        for (int j = 0; j < grafo.adjacencias[i].comandados.size(); j++) {
            transposto.adicionarAdjacencia(grafo.adjacencias[i].comandados[j], i);
        }

    }
}
