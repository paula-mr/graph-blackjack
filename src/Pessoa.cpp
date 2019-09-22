#ifndef PESSOA_CPP
#define PESSOA_CPP

#include "Pessoa.h"

Pessoa::Pessoa() = default;

Pessoa::~Pessoa() = default;

bool Pessoa::comanda(int aluno) {
    for (auto i : this->comandados) {
        if (i == aluno)
            return true;
    }

    return false;
}

#endif
