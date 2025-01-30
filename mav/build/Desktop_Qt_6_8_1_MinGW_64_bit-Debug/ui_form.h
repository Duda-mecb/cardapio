/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *botaoCardapio;
    QPushButton *botaoPedido;
    QPushButton *botaoSair;
    QTextEdit *textEditCardapio;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        botaoCardapio = new QPushButton(centralwidget);
        botaoCardapio->setObjectName("botaoCardapio");

        verticalLayout->addWidget(botaoCardapio);

        botaoPedido = new QPushButton(centralwidget);
        botaoPedido->setObjectName("botaoPedido");

        verticalLayout->addWidget(botaoPedido);

        botaoSair = new QPushButton(centralwidget);
        botaoSair->setObjectName("botaoSair");

        verticalLayout->addWidget(botaoSair);

        textEditCardapio = new QTextEdit(centralwidget);
        textEditCardapio->setObjectName("textEditCardapio");

        verticalLayout->addWidget(textEditCardapio);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        botaoCardapio->setText(QCoreApplication::translate("MainWindow", "Mostrar Card\303\241pio", nullptr));
        botaoPedido->setText(QCoreApplication::translate("MainWindow", "Fazer Pedido", nullptr));
        botaoSair->setText(QCoreApplication::translate("MainWindow", "Sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
