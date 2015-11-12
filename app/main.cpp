#include <QApplication>
#include <QDebug>
#include <QWidget>

#include <MemoryMap>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QStringList args = app.arguments();
    if (args.isEmpty()) return 1;

    MemoryMap * map = new MemoryMap;
    map->loadFile(args[0]);

    map->show();

    return app.exec();
}
