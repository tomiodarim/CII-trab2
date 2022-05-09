#include "viewmanternovela.h"
#include "ui_viewmanternovela.h"

#include <QMessageBox>

ViewManterNovela::ViewManterNovela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewManterNovela)
{
    ui->setupUi(this);
}

void ViewManterNovela::mostrar ( Model *model ) {
    this->model=(ModelNovela*)model;
    if (model==nullptr) {
        ui->fieldidnovela->setValue( 0 );
        ui->fieldnome->setText( "" );
        ui->fieldautor->setText( "" );
        ui->fieldrede->setText( "" );
    } else {
        ui->fieldidnovela->setValue( this->model->getIdnovela() );
        ui->fieldnome->setText( this->model->getNome() );
        ui->fieldautor->setText( this->model->getAutor() );
        ui->fieldrede->setText( this->model->getRede() );
    }
    ui->bexcluir->setEnabled(model!=nullptr);

    this->exec();
}

ViewManterNovela::~ViewManterNovela()
{
    delete ui;
}

void ViewManterNovela::on_bsalvar_clicked()
{
    if (this->model==nullptr) {
        this->model = new ModelNovela();
    }
    try {
        this->model->setNome( ui->fieldnome->text() );
        this->model->setAutor( ui->fieldautor->text() );
        this->model->setRede( ui->fieldrede->text() );
        emit salvar( this->model );
        close();
    }  catch ( QString msg ) {
        QMessageBox::critical(this, tr("Erro"),msg);
    }
}


void ViewManterNovela::on_bexcluir_clicked()
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Excluir"),
                                  tr("Confirmar excluir a informação atual?"),
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        try {
            emit excluir ( this->model );
            close();
        }  catch ( QString msg ) {
            QMessageBox::critical(this, tr("Erro"),msg);
        }
    }
}

void ViewManterNovela::on_bfechar_clicked()
{
    close();
}

