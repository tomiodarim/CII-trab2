#ifndef MODELNOVELA_H
#define MODELNOVELA_H

#include "model.h"

#include <QDate>

class ModelNovela: public Model {
    Q_OBJECT
    Q_PROPERTY(int idnovela READ getIdnovela WRITE setIdnovela )
    Q_PROPERTY(QString nome READ getNome WRITE setNome )
    Q_PROPERTY(QString autor READ getAutor WRITE setAutor )
    Q_PROPERTY(QString rede READ getRede WRITE setRede )
protected:
    int     idnovela;
    QString nome;
    QString autor;
    QString rede;

public:
    ModelNovela () : Model( "idnovela" ) {
        this->idnovela = 0;
    }

    Model *getNewInstance () {
        return new ModelNovela();
    }

    int getIdnovela() const {
        return idnovela;
    }
    void setIdnovela(int newId) {
        this->idnovela = newId;
    }

    const QString &getNome() const {
        return this->nome;
    }

    void setNome(const QString &newNome) {
        this->nome = newNome;
    }

    const QString &getAutor() const {
        return this->autor;
    }

    void setAutor(const QString &newAutor) {
        this->autor = newAutor;
    }

    const QString &getRede() const {
        return this->rede;
    }

    void setRede(const QString &newRede) {
        this->rede = newRede;
    }

    int compareTo ( Model *other ) {
        return this->nome.compare(other->get ("nome").toString(), Qt::CaseInsensitive);
    }

};

#endif // MODELNOVELA_H
