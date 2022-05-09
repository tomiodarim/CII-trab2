#ifndef DAO_H
#define DAO_H

#include <QObject>

#include "model/model.h"
#include "util/parameter.h"
#include "util/collection.h"

class Dao : public QObject
{
    Q_OBJECT
protected:
    int id;
    void incluir ( Model* m );
    void atualizar ( Model* m  );

    QList<Model*> lista;
public:
    Dao(QObject *parent = nullptr);

    QList<Model*> consultar (QList<Parameter *> lp );
    void salvar ( Model *m ) ; // inclusão ou modificação
    void excluir ( Model *m );


signals:

};

#endif // DAO_H
