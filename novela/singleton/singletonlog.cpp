#include "singletonlog.h"

#include <stdio.h>
#include <QString>
#include <QDate>
#include <QFileInfo>
#include <QTextStream>

SingletonLog *SingletonLog::instance=0;

SingletonLog::SingletonLog() {
}

SingletonLog * SingletonLog::getInstance() {
    if (!instance) instance = new SingletonLog();
    return instance;
}

QString SingletonLog::getFileName () {
    int dia = QDate::currentDate().day();
    return QString("../logs/log") + (dia<10? "0" : "") +
           QString::number(dia) + ".txt";
}

void SingletonLog::removeFile ( QString file_name ) {
    QFileInfo fi ( file_name );
    if (fi.lastModified().date()!=QDate::currentDate()) {
        QFile f ( file_name );
        f.remove();
    }
}

void SingletonLog::doLog(QtMsgType type, const QString &msg) {
    QString file_name = getFileName();
    removeFile ( file_name );

    QString s= QTime::currentTime().toString( "hh:mm:ss - ");
    switch (type) {
    case QtDebugMsg:    s += "Debug: ";    break;
    case QtInfoMsg:     s += "Info: ";     break;
    case QtWarningMsg:  s += "Warning: ";  break;
    case QtCriticalMsg: s += "Critical: "; break;
    case QtFatalMsg:    s += "Fatal: ";    abort();
    }
    QFile f ( file_name );
    if (f.open( QIODevice::Append) ) {
        QTextStream out(&f);
        out << s
            << " "
            << msg;
        f.close();
    }
}


SingletonLog::~SingletonLog() {
    this->instance=0;
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &, const QString &msg) {
    SingletonLog::getInstance()->doLog( type, msg );
}
