#include "parameter.h"


Parameter::Parameter(QString name, QString value,
                     QObject *parent) : QObject(parent) {
    this->name  = name;
    this->value = value;
    this->operation = LIKE;
}

Parameter::Parameter(QString name, QString value,
                     Operation operation,
                     QObject *parent) : QObject(parent) {
    this->name  = name;
    this->value = value;
    this->operation = operation;
}

const QString &Parameter::getName() const
{
    return name;
}

const QString &Parameter::getValue() const
{
    return value;
}

Parameter::Operation Parameter::getOperation() const
{
    return operation;
}
