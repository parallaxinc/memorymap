#include <QApplication>
#include <QDebug>

#include "memorymap.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MemoryMap * mm = new MemoryMap();

    mm->loadFile("LameSerial.binary");
    mm->show();

    return app.exec();
}
