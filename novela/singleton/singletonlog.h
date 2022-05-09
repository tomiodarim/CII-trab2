#ifndef SINGLETONLOG_H
#define SINGLETONLOG_H

#include <QtGlobal>
#include <iostream>
using namespace std;

class SingletonLog {
private:
    //static SingletonLog *instance=0;
    static SingletonLog *instance;

    QString getFileName (); ///< pega o nome do arquivo
    void removeFile ( QString file_name );

    SingletonLog ();
public:
    static SingletonLog * getInstance();

    void doLog (QtMsgType type, const QString &msgs );

    ~SingletonLog();
};

void myMessageOutput(QtMsgType type, const QMessageLogContext &, const QString &msg);

#endif // SINGLETONLOG_H
