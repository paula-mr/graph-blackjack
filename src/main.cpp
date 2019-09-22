#include "Grafo.h"
#include "Pessoa.h"
#include "Orquestrador.h"

FILE* abrirArquivo(int argc, char *argv[]);
void receberPessoas(Pessoa pessoas[], FILE* arquivo, int qtdPessoas);
void receberRelacionamentos(Grafo grafo, FILE* arquivo, int qtdRelacoes);
void receberComandos(Grafo grafo, FILE* arquivo, int qtdInstrucoes);
void executarCommander(Grafo grafo, FILE* arquivo);
void executarSwap(Grafo grafo, FILE* arquivo);
int recuperarNumero(FILE* arquivo);
char recuperarChar(FILE* arquivo);

int main(int argc, char *argv[]) {

    FILE* arquivo = abrirArquivo(argc, argv);
    if (arquivo == NULL)
        return 1;

    int qtdPessoas, qtdRelacoes, qtdInstrucoes;

    qtdPessoas = recuperarNumero(arquivo);
    qtdRelacoes = recuperarNumero(arquivo);
    qtdInstrucoes = recuperarNumero(arquivo);

    Pessoa pessoas[qtdPessoas+1];
    receberPessoas(pessoas, arquivo, qtdPessoas);

    Grafo grafo = Grafo(qtdPessoas, pessoas);
    receberRelacionamentos(grafo, arquivo, qtdRelacoes);

    receberComandos(grafo, arquivo, qtdInstrucoes);

    return 0;
}

FILE* abrirArquivo(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Parâmetro inválido.";
        return NULL;
    }

    char* nomeArquivo = argv[1];

    FILE* arquivo = fopen(nomeArquivo, "r");

    return arquivo;
}

char recuperarChar(FILE* arquivo) {
    char resultado = fgetc(arquivo);

    //le espaco em branco ou nova linha
    fgetc(arquivo);

    return resultado;
}

int recuperarNumero(FILE* arquivo) {
    int numero = 0, auxiliar;

    //enquanto char lido nao for espaco branco ou nova linha
    while ((auxiliar = fgetc(arquivo)) != ' ' && auxiliar != '\n') {
        numero*=10;
        //transforma char em valor numerico
        numero+=auxiliar-48;
    }

    return numero;
}

void receberPessoas(Pessoa pessoas[], FILE* arquivo, int qtdPessoas) {
    for (int i=0; i < qtdPessoas; i++) {
        int idade = recuperarNumero(arquivo);
        pessoas[i+1].idade = idade;
    }
}

void receberRelacionamentos(Grafo grafo, FILE* arquivo, int qtdRelacoes) {
    for (int i=0; i < qtdRelacoes; i++) {
        int lider, comandado;
        lider = recuperarNumero(arquivo);
        comandado = recuperarNumero(arquivo);

        grafo.adicionarAdjacencia(lider, comandado);
    }
}

void receberComandos(Grafo grafo, FILE* arquivo, int qtdInstrucoes) {
    for (int i=0; i < qtdInstrucoes; i++) {
        char comando = recuperarChar(arquivo);

        switch(comando) {
            case 'C':
                executarCommander(grafo, arquivo);
                break;

            case 'M':
                meeting(grafo);
                break;

            case 'S':
                executarSwap(grafo, arquivo);
                break;
        }
    }
}

void executarCommander(Grafo grafo, FILE* arquivo) {
    int aluno = recuperarNumero(arquivo);

    commander(grafo, aluno);
}

void executarSwap(Grafo grafo, FILE* arquivo) {
    int aluno1, aluno2;
    aluno1 = recuperarNumero(arquivo);
    aluno2 = recuperarNumero(arquivo);

    swap(grafo, aluno1, aluno2);
}
