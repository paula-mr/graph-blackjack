#include "Grafo.h"
#include "Pessoa.h"

void receberPessoas(Pessoa pessoas[], int qtdPessoas);
void receberRelacionamentos(Grafo grafo, int qtdRelacoes);

int main() {

    int qtdPessoas, qtdRelacoes, qtdInstrucoes;

    std::cin >> qtdPessoas >> qtdRelacoes >> qtdInstrucoes;

    Pessoa pessoas[qtdPessoas+1];
    receberPessoas(pessoas, qtdPessoas);

    Grafo grafo = Grafo(qtdPessoas, pessoas);
    receberRelacionamentos(grafo, qtdRelacoes);

    grafo.imprimir();

    return 0;
}

void receberPessoas(Pessoa pessoas[], int qtdPessoas) {
    for (int i=0; i < qtdPessoas; i++) {
        int idade;
        std::cin >> idade;
        pessoas[i+1].idade = idade;
    }
}

void receberRelacionamentos(Grafo grafo, int qtdRelacoes) {
    for (int i=0; i < qtdRelacoes; i++) {
        int lider, comandado;
        std::cin >> lider >> comandado;

        grafo.adicionarAdjacencia(lider, comandado);
    }
}
