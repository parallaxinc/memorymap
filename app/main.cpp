#include <QApplication>
#include <QDebug>
#include <QWidget>

#include <MemoryMap>
#include <PropellerManager>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QStringList args = app.arguments();
    if (args.isEmpty() || args.size() < 2) return 1;

    PropellerManager manager;

    MemoryMap * map = new MemoryMap(&manager);
    map->openFile(args[1]);

    map->show();

    return app.exec();
}
