#include "model.h"

#include <QMetaProperty>
#include <QDebug>

#include <iostream>
using namespace std;

Model::Model(QString idname, QObject *parent) : QObject(parent) {
    this->idname = idname;
}

int Model::getId () {
    return get(idname).toInt();
}

void Model::setId ( int id ) {
    set (idname, id );
}

QVariant Model::get( QString attrName ) {
    return this->property(attrName.toStdString().c_str());
}

void Model::set(QString attrName, QVariant attrValue ) {
    if (!this->setProperty ( attrName.toLatin1().constData(),
                             attrValue )) {
        qWarning() << "Atributo " << attrName << " não localizado!" << Qt::endl;
    }
}

QStringList Model::getAttributes ( ) {
    QStringList sl;
    for (int i=metaObject()->propertyOffset();
         i<metaObject()->propertyCount();
         i++) {
        sl.append(metaObject()->property(i).name());
    }
    return sl;
}

bool Model::equals (Model *other ) {
    return this->getId()==other->getId();
}

int Model::compareTo ( Model *other ) {
    if (this->getId()==other->getId()) {
        return 0;
    }
    if (this->getId()<other->getId()) {
        return -1;
    }
    return 1;
}

Model *Model::clone() {
    QString name;
    Model *model = getNewInstance();
    QStringList sl = getAttributes();
    for (int i=0; i<sl.count(); i++ ) {
        name = sl.at(i);
        model->set( name, this->get(name) );
    }
    return model;
}

bool Model::replace ( Model *other ) {
    QString s1 = this->metaObject()->className();
    QString s2 = other->metaObject()->className();
    if (s1.compare ( s2 ) != 0) {
        return false;
    }

    QString name;
    QStringList sl = getAttributes();
    for (int i=0; i<sl.count(); i++ ) {
        name = sl.at(i);
        this->set( name, other->get(name) );
    }
    return true;
}

void Model::show () {
    QString name;
    QStringList sl = getAttributes();
    for (int i=0; i<sl.count(); i++ ) {
        name = sl.at(i);
        cout << name.toStdString()
             << ": "
             << get(name).toString().toStdString()
             << endl;
    }
}

