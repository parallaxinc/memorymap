#include <QApplication>
#include <QDebug>
#include <QWidget>
#include <QSettings>

#include <MemoryMap>
#include <PropellerManager>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("Parallax");
    QCoreApplication::setApplicationName("PropellerIDE");

    PropellerManager manager;
    MemoryMap * map = new MemoryMap(&manager);

    if (argc > 1)
        map->openFile(argv[1]);

    QSettings settings;
    settings.beginGroup("Colors");

    map->recolor(
            settings.value("Block_PUB",         "#dde3f3").toString(),
            settings.value("Block_DAT",         "#e6f5e9").toString(),
            settings.value("Syntax_Text",       "#404040").toString(),
            settings.value("Syntax_Keywords",   "#003c79").toString(),
            settings.value("Block_CON",         "#f8f8f8").toString(),
            settings.value("Syntax_Comments",   "#999999").toString(),
            settings.value("Syntax_Text",       "#404040").toString()
           );

    map->show();

    return app.exec();
}
