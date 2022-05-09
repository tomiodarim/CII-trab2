#ifndef PARAMETER_H
#define PARAMETER_H

#include <QObject>

class Parameter : public QObject {
    Q_OBJECT
public:
    enum Operation {EQUAL, LIKE};

private:
    QString name;
    QString value;
    Operation operation;

public:
    Parameter(
            QString name,
            QString value,
            QObject *parent = nullptr);

    Parameter(
            QString name,
            QString value,
            Operation operation,
            QObject *parent = nullptr);


    const QString &getName() const;
    const QString &getValue() const;
    Operation getOperation() const;

signals:

};

#endif // PARAMETER_H
