#include <QApplication>
#include <QDebug>
#include <QWidget>

#include "ui_memorymap.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QWidget * widget = new QWidget;

    Ui::MemoryMapDialog ui;
    ui.setupUi(widget);

    ui.frame->loadFile("LameSerial.binary");
    qDebug() << ui.frame->size(); widget->size();
    widget->show();
    widget->setWindowTitle(QObject::tr("Memory Map"));

    return app.exec();
}
