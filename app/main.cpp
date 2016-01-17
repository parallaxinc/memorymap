#include <QApplication>
#include <QDebug>
#include <QWidget>

#include <MemoryMap>
#include <PropellerManager>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    PropellerManager manager;
    MemoryMap * map = new MemoryMap(&manager);

    if (argc > 1)
        map->openFile(argv[1]);

    map->show();

    return app.exec();
}
