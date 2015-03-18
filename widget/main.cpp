#include <QApplication>
#include <QFile>
#include <QByteArray>
#include <QDebug>
#include <QMainWindow>
#include <QColor>
#include <Qt>

#include "QHexEdit/qhexedit.h"
#include "QHexEdit/qhexeditdata.h"

#include "memorymap.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);


    QHexEdit * hex = new QHexEdit();
    QHexEditData * hexeditdata = QHexEditData::fromFile("LameSerial.binary");

    hex->clearHighlight();
    hex->setReadOnly(true);

    QPalette p = hex->palette();

    QFont f = QFont("Monospace",14);
    f.setFixedPitch(true);
    f.setKerning(false);

    hex->setFont(f);

    p.setColor(QPalette::WindowText, QColor("#000000")); // the lines on the side
//    p.setColor(QPalette::Text, QColor("#000000"));       

    p.setColor(QPalette::Base, QColor("#170026"));
    hex->setPalette(p);

    hex->setLineColor(QColor("#2F2F78"));
    hex->setAlternateLineColor(QColor("#210036"));

    hex->setHexColor(QColor("#6565FE"));
    hex->setAlternateHexColor(QColor("#999999"));

    hex->setHighlightColor(QColor("#FE7FFE"));
    hex->setAddressForeColor(QColor("#EDEDED"));
    hex->setAddressBackColor(QColor("#3D3D3D"));
//    hex->setAddressForeColor(QColor("#6565FE"));
//    hex->setAddressBackColor(QColor("000000"));

    hex->setData(hexeditdata);

//    qDebug() << file.size() << blob.toHex();

    MemoryMap w;
    w.setCentralWidget(hex);
//    w.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
//    w.setFixedSize(w.size());

    QObject::connect(hex, SIGNAL(widthChanged(int)), &w, SLOT(fixWidth(int)));


    qDebug() << w.size() << hex->size();

    w.show();
    return app.exec();
}
