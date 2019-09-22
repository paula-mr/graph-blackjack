#ifndef PESSOA_H
#define PESSOA_H

using namespace std;

#include <vector>

class Pessoa {
    public:
        int idade;
        vector<int> comandados;

        Pessoa();
        ~Pessoa();

        bool comanda(int aluno);
};

#endif
