#include "dao.h"

Dao::Dao(QObject *parent) : QObject(parent) {
    id = 0;
}

void Dao::incluir ( Model* m ) {
    m->setId( ++id );
    lista.append( m->clone() );
}

void Dao::atualizar ( Model* m  ) {
    for ( int i=0; i<lista.count(); i++ ) {
        if (lista.at(i)->equals(m)) {
            lista.at(i)->replace(m);
            return;
        }
    }
}

void Dao::salvar ( Model *m )  {
    if (m->getId()==0) {
        incluir(m);
    } else {
        atualizar(m);
    }
}

void Dao::excluir(Model *m) {
    for ( int i=0; i<lista.count(); i++ ) {
        if (lista.at(i)->equals(m)) {
            delete lista.at(i);
            lista.removeAt(i);
            return;
        }
    }
}

QList<Model*> Dao::consultar ( QList<Parameter*> lp ) {
    QList<Model*> result;
    Model *m;
    QString s;
    bool ok;
    Parameter *param;
    for ( int i=0; i<lista.count(); i++) {
        m = lista.at(i);
        ok=true;
        for ( int j=0; ok && j<lp.count(); j++ ) {
            param = lp.at(j);
            if (param->getValue()!="") {
                switch (param->getOperation()) {
                case Parameter::EQUAL:
                    s = m->get(param->getName()).toString();
                    if(s.compare(param->getValue())!=0) {
                        ok = false;
                    }
                    break;
                case Parameter::LIKE:
                    s = m->get(param->getName()).toString();
                    if(!s.contains(param->getValue())) {
                        ok = false;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        if (ok) {
            result.append( m );
        }
    }

    return result;
}

