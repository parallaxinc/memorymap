#include <QApplication>
#include <QFile>
#include <QByteArray>
#include <QDebug>
#include <QMainWindow>
#include <QColor>
#include <Qt>

#include "QHexEdit/qhexedit.h"
#include "QHexEdit/qhexeditdata.h"


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QMainWindow w;

    QHexEdit x;

    w.setCentralWidget(&x);



//    QFile file("LameSerial.binary");
//
//    if (!file.open(QIODevice::ReadOnly)) {
//        qDebug() << "BLAH";
//        return 1;
//    }
//    QByteArray blob = file.readAll();
//    file.close();

    QHexEditData * hexeditdata = QHexEditData::fromFile("LameSerial.binary");

    x.clearHighlight();
    x.setReadOnly(true);

    QPalette p = x.palette();

    QFont f = QFont("Monospace",14);
    f.setFixedPitch(true);
    f.setKerning(false);

    x.setFont(f);

    p.setColor(QPalette::WindowText, QColor("#000000")); // the lines on the side
//    p.setColor(QPalette::Text, QColor("#000000"));       

    p.setColor(QPalette::Base, QColor("#170026"));
    x.setPalette(p);

    x.setLineColor(QColor("#2F2F78"));
    x.setAlternateLineColor(QColor("#210036"));

    x.setHexColor(QColor("#6565FE"));
    x.setAlternateHexColor(QColor("#999999"));

    x.setHighlightColor(QColor("#FE7FFE"));
    x.setAddressForeColor(QColor("#EDEDED"));
    x.setAddressBackColor(QColor("#3D3D3D"));
//    x.setAddressForeColor(QColor("#6565FE"));
//    x.setAddressBackColor(QColor("000000"));

    x.setData(hexeditdata);

//    qDebug() << file.size() << blob.toHex();

    w.show();
    return app.exec();
}
