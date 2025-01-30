#include <iostream>
#include <string>
using namespace std;

#include "bebida.h"


//Exibe os detalhes das bebidas
void Bebida::detalhes() const {
    Produto::detalhes();
    cout<< "Tamanho.........:" << tamanho << endl;
}

// Get e Set
int Bebida::getTamanho() const {
    return tamanho;
}

void Bebida::setTamanho(int novoTamanho){
    if (novoTamanho >= 0) {
        tamanho = novoTamanho;
    } else {
        cout << "Erro: tamanho invalido!" << endl;
    }
}
