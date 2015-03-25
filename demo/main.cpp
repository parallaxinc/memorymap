#include <QApplication>
#include <QDebug>
#include <QWidget>

#include "memorymap.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    MemoryMap * map = new MemoryMap;
    map->loadFile("LameSerial.binary");

    map->show();

    return app.exec();
}
