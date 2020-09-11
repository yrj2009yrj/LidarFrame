#include <QtCore/QCoreApplication>

#include "MainProcess.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    MainProcess main_process;

    return a.exec();
}
