#include "Grafo.h"
#include "Pessoa.h"

int main() {

    int qtdPessoas, qtdRelacoes, qtdInstrucoes;

    std::cin >> qtdPessoas >> qtdRelacoes >> qtdInstrucoes;

    Pessoa pessoas[qtdPessoas];

    for (int i=0; i < qtdPessoas; i++) {
        int idade;
        std::cin >> idade;
        pessoas[i+1].idade = idade;
    }

    Grafo grafo = Grafo(qtdPessoas);

    for (int i=0; i < qtdRelacoes; i++) {
        int lider, comandado;
        std::cin >> lider >> comandado;

        grafo.adicionarAdjacencia(pessoas, lider, comandado);
    }

    grafo.imprimirGrafo(pessoas);

    return 0;
}
