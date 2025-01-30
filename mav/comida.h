#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

#include "Produto.h" //Inclui a classe Produto

class Comida : public Produto{ //Define como herança de Produto
private:
    int tempoPreparo; //Tempo médio de preparo em minutos
    string tipo; //Tipo da comida (se é acompanhamento, se é hambúrguer smash...)
public:

    Comida(bool disponibilidade, double preco, string nome, int tempoPreparo, string tipo); //Construtor

    //Métodos

    void detalhes() const override;
    void PrecoPorTipo(); //Define os preços de acordo com a classificação da comida


    // Getters e Setters
    int getPreparo() const;
    void setPreparo(int novoPreparo);

    string getTipo() const;
    void setTipo(string novoTipo);

};



#endif // COMIDA_H_INCLUDED
