#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QVariant>


class Model : public QObject {
    Q_OBJECT
private:
    QString idname;
public:
    Model( QString idname, QObject *parent = nullptr);

    virtual Model *getNewInstance()=0;

    virtual int getId ();
    virtual void setId ( int id );

    QVariant get( QString attrName );
    void set(QString attrName, QVariant attrValue );

    virtual int compareTo ( Model *other );
    virtual bool equals ( Model *other );
    Model *clone();
    bool replace ( Model *other );

    QStringList getAttributes ( );

    void show ();

signals:

};

#endif // MODEL_H
