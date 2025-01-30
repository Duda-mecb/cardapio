#ifndef CONEXAO_H
#define CONEXAO_H

#include <QtSql>
#include <QCoreApplication>

class Conexao {
public:
    QSqlDatabase bancoDeDados;
    QString banco;

    Conexao() {
        banco = "C:/Users/Pichau/Downloads/copy/ControlEstoque_cfb/db/controlNovo.db";
        bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");
    }

    void fechar() {
        bancoDeDados.close();
    }

    bool abrir() {
        bancoDeDados.setDatabaseName(banco);
        return bancoDeDados.open();
    }

    bool aberto() {
        return bancoDeDados.isOpen();
    }
};

#endif // CONEXAO_H
