#include "Grafo.h"
#include "Pessoa.h"
#include "Orquestrador.h"

void receberPessoas(Pessoa pessoas[], int qtdPessoas);
void receberRelacionamentos(Grafo grafo, int qtdRelacoes);
void receberComandos(Grafo grafo, int qtdInstrucoes);
void executarCommander(Grafo grafo);

int main() {

    int qtdPessoas, qtdRelacoes, qtdInstrucoes;

    std::cin >> qtdPessoas >> qtdRelacoes >> qtdInstrucoes;

    Pessoa pessoas[qtdPessoas+1];
    receberPessoas(pessoas, qtdPessoas);

    Grafo grafo = Grafo(qtdPessoas, pessoas);
    receberRelacionamentos(grafo, qtdRelacoes);

    grafo.imprimir();

    receberComandos(grafo, qtdInstrucoes);

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

void receberComandos(Grafo grafo, int qtdInstrucoes) {
    for (int i=0; i < qtdInstrucoes; i++) {
        char comando;
        std::cin >> comando;

        switch(comando) {
            case 'C':
                executarCommander(grafo);
                break;
        }
    }
}

void executarCommander(Grafo grafo) {
    int aluno;
    std::cin >> aluno;

    commander(grafo, aluno);
}
