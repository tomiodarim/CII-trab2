#ifndef CONTROLLERMAIN_H
#define CONTROLLERMAIN_H

#include <QApplication>
#include "view/viewMainWindow.h"

class ControllerMain : public QApplication
{
    Q_OBJECT
private:
    ViewMainWindow *view;
public:
    ControllerMain( int argc, char *argv[] );

public slots:
    void consultarNovelas ();
};

#endif // CONTROLLERMAIN_H
