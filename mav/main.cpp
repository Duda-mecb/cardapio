#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include "conecta.h"

class MenuWindow : public QWidget {
    Q_OBJECT

public:
    MenuWindow(QWidget *parent = nullptr) : QWidget(parent) {
        conexao.abrir();

        // Configurar layout e widgets
        QVBoxLayout *layout = new QVBoxLayout(this);

        botaoCardapio = new QPushButton("Mostrar Cardápio", this);
        botaoPedido = new QPushButton("Fazer Pedido", this);
        botaoSair = new QPushButton("Sair", this);
        textEditCardapio = new QTextEdit(this);

        layout->addWidget(botaoCardapio);
        layout->addWidget(botaoPedido);
        layout->addWidget(botaoSair);
        layout->addWidget(textEditCardapio);

        connect(botaoCardapio, &QPushButton::clicked, this, &MenuWindow::mostrarCardapio);
        connect(botaoPedido, &QPushButton::clicked, this, &MenuWindow::fazerPedido);
        connect(botaoSair, &QPushButton::clicked, this, &MenuWindow::sair);
    }

    ~MenuWindow() {
        conexao.fechar();
    }

private slots:
    void mostrarCardapio() {
        textEditCardapio->clear();
        QSqlQuery query(conexao.bancoDeDados);
        if (query.exec("SELECT id, nome, preco, tipo FROM produtos WHERE disponibilidade = 1")) {
            textEditCardapio->append("====== CARDÁPIO ======");
            while (query.next()) {
                int id = query.value("id").toInt();
                QString nome = query.value("nome").toString();
                double preco = query.value("preco").toDouble();
                QString tipo = query.value("tipo").toString();

                textEditCardapio->append(QString("%1 - %2 (%3) - R$ %4").arg(id).arg(nome).arg(tipo).arg(preco));
            }
        } else {
            QMessageBox::critical(this, "Erro", "Erro ao carregar cardápio: " + query.lastError().text());
        }
    }

    void fazerPedido() {
        bool ok;
        int produtoId = QInputDialog::getInt(this, "Pedido", "Digite o ID do produto que deseja pedir:", 1, 1, 1000000, 1, &ok);
        if (!ok) return;

        int quantidade = QInputDialog::getInt(this, "Pedido", "Digite a quantidade:", 1, 1, 1000, 1, &ok);
        if (!ok) return;

        QSqlQuery query(conexao.bancoDeDados);
        query.prepare("SELECT nome, preco FROM produtos WHERE id = :id AND disponibilidade = 1");
        query.bindValue(":id", produtoId);

        if (!query.exec() || !query.next()) {
            QMessageBox::critical(this, "Erro", "Produto não encontrado ou indisponível!");
            return;
        }

        QString nomeProduto = query.value("nome").toString();
        double preco = query.value("preco").toDouble();
        double total = preco * quantidade;

        QSqlQuery insertPedido(conexao.bancoDeDados);
        insertPedido.prepare("INSERT INTO pedidos (total) VALUES (:total)");
        insertPedido.bindValue(":total", total);
        if (!insertPedido.exec()) {
            QMessageBox::critical(this, "Erro", "Erro ao registrar pedido: " + insertPedido.lastError().text());
            return;
        }

        int pedidoId = insertPedido.lastInsertId().toInt();

        QSqlQuery insertItem(conexao.bancoDeDados);
        insertItem.prepare("INSERT INTO itens_pedido (pedido_id, produto_id, quantidade, subtotal) VALUES (:pedido_id, :produto_id, :quantidade, :subtotal)");
        insertItem.bindValue(":pedido_id", pedidoId);
        insertItem.bindValue(":produto_id", produtoId);
        insertItem.bindValue(":quantidade", quantidade);
        insertItem.bindValue(":subtotal", total);
        if (!insertItem.exec()) {
            QMessageBox::critical(this, "Erro", "Erro ao registrar item do pedido: " + insertItem.lastError().text());
            return;
        }

        QMessageBox::information(this, "Pedido Realizado", QString("Pedido realizado com sucesso! %1x %2 (R$ %3)").arg(quantidade).arg(nomeProduto).arg(total));
    }

    void sair() {
        QApplication::quit();
    }

private:
    QPushButton *botaoCardapio;
    QPushButton *botaoPedido;
    QPushButton *botaoSair;
    QTextEdit *textEditCardapio;
    Conexao conexao;
};

#include "main.moc"  // Necessário para a meta-objetos do Qt

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuWindow window;
    window.show();

    return app.exec();
}
