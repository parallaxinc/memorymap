#include <QApplication>
#include <QDebug>
#include <QWidget>

#include "memorymap.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    MemoryMap * map = new MemoryMap;
    map->loadFile("LameSerial.binary");

    QFont f = QFont("Courier",14);
    f.setFixedPitch(true);
    f.setKerning(false);
    map->setFont(f);

    map->show();

    return app.exec();
}
