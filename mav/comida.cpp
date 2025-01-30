#include <iostream>
#include <string>
using namespace std;

#include "Comida.h"

// Construtor
Comida::Comida(bool disponibilidade, double preco, string nome, int tempoPreparo, string tipo)
    : Produto(disponibilidade, preco, nome), tempoPreparo(tempoPreparo), tipo(tipo) {}

//Exibe os detalhes das comidas
void Comida::detalhes() const {
    Produto::detalhes();
    cout<< "Tempo de Preparo:" << tempoPreparo << endl;
    cout<< "Tipo............:" << tipo << endl;
}

//Define os preços de acordo com a classificação da comida
void Comida::PrecoPorTipo(){
    if (tipo == "Acompanhamentos"){
        setPreco(27.90);
    }
    else if (tipo == "Blend MVK"){
        setPreco(33.90);
    }
    else if (tipo == "Hamburguer Double Smash"){
        setPreco(34.90);
    }
    else if (tipo == "Hamburguer Smash"){
        setPreco(22.90);
    }
    else if (tipo == "Blend Frango"){
        setPreco(30.90);
    }
    else if (tipo == "Sanduiches"){
        setPreco(28.90);
    }
    else if (tipo == "Cachorro Quente"){
        setPreco(23.90);
    }


}

// Getters e Setters
int Comida::getPreparo() const {
    return tempoPreparo;
}

void Comida::setPreparo(int novoPreparo){
    if (novoPreparo >= 0) {
        tempoPreparo = novoPreparo;
    } else {
        cout << "Erro: tempo de preparo invalido!" << endl;
    }
}


string Comida::getTipo() const{
    return tipo;
}


void Comida::setTipo(string novoTipo){
    tipo = novoTipo;
    PrecoPorTipo();
}
