#include "Grafo.h"
#include "Pessoa.h"

int main() {

    int tamanho = 5;
    Pessoa pessoas[tamanho];

    Grafo grafo = Grafo(tamanho);
    grafo.adicionarAdjacencia(pessoas, 0, 1);
    grafo.adicionarAdjacencia(pessoas, 0, 4);
    grafo.adicionarAdjacencia(pessoas, 1, 2);
    grafo.adicionarAdjacencia(pessoas, 1, 3);
    grafo.adicionarAdjacencia(pessoas, 1, 4);
    grafo.adicionarAdjacencia(pessoas, 2, 3);
    grafo.adicionarAdjacencia(pessoas, 3, 4);

    grafo.imprimirGrafo(pessoas);

    return 0;
}
