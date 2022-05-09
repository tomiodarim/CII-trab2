#ifndef COLLECTION_H
#define COLLECTION_H

#include <QObject>
#include <QList>
#include <model/model.h>

class Collection : public QObject
{
    Q_OBJECT
public:
    explicit Collection(QObject *parent = nullptr);

    static void sort ( QList<Model*> &lm );

signals:

};

#endif // COLLECTION_H
