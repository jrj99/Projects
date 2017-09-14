#include <QApplication>

#include "MainWindow.h"
#include "GraphicsWindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWin;
    mainWin.show();
	GraphicsWindow windowOne;
	windowOne.DrawOptionOne();
	windowOne.SetTitle("Graphics Window I");
	windowOne.show();
    return app.exec();
	
}
