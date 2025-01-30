#include <iostream>
#include <string>
using namespace std;

#include "produto.h"

// Construtor
Produto::Produto(bool disponibilidade, double preco, string nome)
    : disponibilidade(disponibilidade), preco(preco), nome(nome) {}

// Exibe os detalhes do produto
void Produto::detalhes() const {
    cout << "Disponibilidade: " << disponibilidade << endl;
    cout << "Preco..........: R$" << preco << endl;
    cout << "Nome do Produto: " << nome << endl;
}

// Getters e Setters
double Produto::getPreco() const {
    return preco;
}

void Produto::setPreco(double novoPreco) {
    if (novoPreco >= 0) {
        preco = novoPreco;
    } else {
        cout << "Erro: preco invalido!" << endl;
    }
}

string Produto::getNome() const {
    return nome;
}

void Produto::setNome(string novoNome) {
    nome = novoNome;
}

