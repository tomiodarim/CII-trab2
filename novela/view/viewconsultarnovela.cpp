#include "viewconsultarnovela.h"
#include "ui_viewconsultarnovela.h"

#include "model/modelnovela.h"
#include "view/viewtreeitem.h"

ViewConsultarNovela::ViewConsultarNovela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewConsultarNovela)
{
    ui->setupUi(this);
        ui->table->setColumnWidth(1, 300);
}

ViewConsultarNovela::~ViewConsultarNovela()
{
    delete ui;
}

void ViewConsultarNovela::on_bConsultar_clicked()
{
    QList<Parameter*> lp;
    lp.append( new Parameter ( "nome", ui->fieldnome->text() ));
    lp.append( new Parameter ( "autor", ui->fieldautor->text() ));
    lp.append( new Parameter ( "rede", ui->fieldrede->text() ));
    lp.append( new Parameter ( "idnovela", ui->fieldidnovela->text() ));

    emit consultar ( &lp );
}

void ViewConsultarNovela::atualizar() {
    on_bConsultar_clicked();
}

void ViewConsultarNovela::on_bIncluir_clicked()
{
    emit manter ( nullptr );
}

void ViewConsultarNovela::listar ( QList<Model*> lista ) {
    ui->table->clear();

    QTreeWidgetItem *item;
    ModelNovela *model;
    for ( int i=0; i<lista.count(); i++) {
        model = (ModelNovela*)lista.at(i);

        item = new ViewTreeItem(model);
        item->setText(0,QString::number(model->getIdnovela()));
        item->setText(1, model->getNome());
        item->setText(2, model->getAutor());
        item->setText(3, model->getRede());

        ui->table->addTopLevelItem(item);
    }
    lista.clear();
}

void ViewConsultarNovela::on_table_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    emit manter(((ViewTreeItem*)item)->getModel());
}


void ViewConsultarNovela::on_bFechar_clicked()
{
    close();
}

