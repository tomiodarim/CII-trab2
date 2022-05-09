#ifndef VIEWMANTERNOVELA_H
#define VIEWMANTERNOVELA_H

#include <QDialog>

#include "model/modelnovela.h"

namespace Ui {
class ViewManterNovela;
}

class ViewManterNovela : public QDialog
{
    Q_OBJECT

public:
    explicit ViewManterNovela(QWidget *parent = nullptr);
    void mostrar ( Model *model );
    ~ViewManterNovela();

private slots:
    void on_bsalvar_clicked();

    void on_bexcluir_clicked();

    void on_bfechar_clicked();

signals:
    void salvar ( Model *model );
    void excluir ( Model *model );
private:
    Ui::ViewManterNovela *ui;
    ModelNovela *model;
};

#endif // VIEWMANTERNOVELA_H
