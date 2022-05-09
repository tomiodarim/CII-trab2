#include "controllermain.h"

#include <iostream>
using namespace std;

#include "controller/controllernovela.h"

ControllerMain::ControllerMain(int argc, char *argv[]) :
    QApplication ( argc, argv )
{
    view = new ViewMainWindow ();
    connect( view, SIGNAL(consultarNovelas()),
             this, SLOT(consultarNovelas()));

    view->show();
}

void ControllerMain::consultarNovelas () {
    ControllerNovela ctrl;
}

