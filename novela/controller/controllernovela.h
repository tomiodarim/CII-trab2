#ifndef CONTROLLERNOVELA_H
#define CONTROLLERNOVELA_H

#include <QObject>
#include "dao/dao.h"
#include "view/viewconsultarnovela.h"
#include "view/viewmanternovela.h"

class ControllerNovela : public QObject {
    Q_OBJECT
private:
    ViewConsultarNovela *viewConsultar;
    ViewManterNovela viewManter;
    Dao dao;

public slots:
    void consultar ( QList<Parameter*> *lp );// ViewConsultar
    void manter ( Model *model ); // ViewConsultar

    void salvar ( Model *model ); // ViewManter
    void excluir  ( Model *model );// ViewManter
public:
    explicit ControllerNovela(QObject *parent = nullptr);

signals:

};

#endif // CONTROLLERNOVELA_H
