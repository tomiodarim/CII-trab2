#include "viewMainWindow.h"
#include "ui_viewMainWindow.h"


#include <QDebug>

ViewMainWindow::ViewMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewMainWindow)
{
    ui->setupUi(this);

    if (translator.load( ":/tradutor/novela_portugues" )) {
        QApplication::installTranslator( &translator );
    }

}

void ViewMainWindow::on_actionConsultar_novelas_triggered()
{
    emit consultarNovelas();
}

void ViewMainWindow::on_actionFechar_aplicacao_triggered()
{
     close();
}

ViewMainWindow::~ViewMainWindow()
{
    delete ui;
}

void ViewMainWindow::on_actionIngles_triggered()
{
    ui->actionIngles->setChecked( true );
    ui->actionPortugues->setChecked( false );
    ui->actionIngles->setEnabled( false );
    ui->actionPortugues->setEnabled( true );

    QApplication::removeTranslator(&translator);
    if (translator.load( ":/tradutor/novela_ingles" )) {
        QApplication::installTranslator( &translator );
    }
    ui->retranslateUi(this);
    qDebug() << "ingles\n";
}


void ViewMainWindow::on_actionPortugues_triggered()
{
    ui->actionIngles->setChecked( false );
    ui->actionPortugues->setChecked( true );
    ui->actionIngles->setEnabled( true );
    ui->actionPortugues->setEnabled( false );


    QApplication::removeTranslator(&translator);
    if (translator.load( ":/tradutor/novela_portugues" )) {
        QApplication::installTranslator( &translator );
    }
    ui->retranslateUi(this);
    qDebug() << "portugues\n";
}



