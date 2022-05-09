#include "controllernovela.h"

#include <QDebug>
#include <QList>
#include "util/parameter.h"

ControllerNovela::ControllerNovela(QObject *parent) : QObject(parent) {

    viewConsultar = new ViewConsultarNovela();

    connect( viewConsultar, SIGNAL(consultar(QList<Parameter*>*)),
             this, SLOT (consultar(QList<Parameter*>*)));

    connect( viewConsultar, SIGNAL(manter(Model*)),
             this, SLOT(manter(Model*)));

    connect( &viewManter, SIGNAL(salvar(Model*)),
             this, SLOT(salvar(Model*)));

    connect( &viewManter, SIGNAL(excluir(Model*)),
             this, SLOT(excluir(Model*)));

    viewConsultar->exec();

}

void ControllerNovela::salvar ( Model *model ) {
    dao.salvar(model);
    viewConsultar->atualizar();
}

void ControllerNovela::excluir  ( Model *model ) {
    dao.excluir( model );
    viewConsultar->atualizar();
}

void ControllerNovela::consultar (QList<Parameter *> *lp ) {
    viewConsultar->listar( dao.consultar( *lp) );
}

void ControllerNovela::manter ( Model *model ) {
    qDebug() << "manter novela\n";
    viewManter.mostrar(model);
}
