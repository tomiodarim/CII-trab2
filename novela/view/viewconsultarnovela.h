#ifndef VIEWCONSULTARNOVELA_H
#define VIEWCONSULTARNOVELA_H

#include <QDialog>
#include <QList>
#include "util/parameter.h"
#include "model/model.h"
#include <QTreeWidgetItem>

namespace Ui {
class ViewConsultarNovela;
}

class ViewConsultarNovela : public QDialog
{
    Q_OBJECT

public:
    explicit ViewConsultarNovela(QWidget *parent = nullptr);
    void listar (QList<Model*> lista );
    void atualizar();
    ~ViewConsultarNovela();

private:
    Ui::ViewConsultarNovela *ui;

signals:
    void consultar ( QList<Parameter*> *lp );
    void manter ( Model *model );

private slots:
    void on_bConsultar_clicked();
    void on_bIncluir_clicked();
    void on_table_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_bFechar_clicked();
};

#endif // VIEWCONSULTARNOVELA_H
