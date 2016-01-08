#include "memorymapprivate.h"

#include <QDebug>
#include <QColor>
#include <Qt>

#include "../QHexEdit/qhexeditdata.h"

MemoryMapPrivate::MemoryMapPrivate(QWidget *parent): QHexEdit(parent)
{
    clearHighlight();
    setReadOnly(true);

    QFont f = QFont("Monospace",10);
    f.setFixedPitch(true);
    f.setKerning(false);
    setFont(f);

    recolor(
            QColor("#24003B"),
            QColor("#003951"),
            QColor("#6565FE"),
            QColor("#4C4CBF"),
            QColor("#484848"),
            QColor("#CBCBCB"),
            QColor("#FFFFFF")
           );

    connect(this, SIGNAL(widthChanged(int)), this, SLOT(fixWidth(int)));
}

void MemoryMapPrivate::recolor(
            QColor hex_background,
            QColor hex_line,
            QColor hex_text,
            QColor hex_text_alt,
            QColor addr_background,
            QColor addr_text,
            QColor addr_highlight)
{
    QPalette p = palette();
    p.setColor(QPalette::Base,  hex_background);    // hex line background 1 (main color)
    setPalette(p);

    setLineColor(               hex_line        );  // hex highlighted line background
    setAlternateLineColor(      hex_background  );  // hex line background 2
    setHexColor(                hex_text        );  // hex text
    setAlternateHexColor(       hex_text_alt    );  // 00 and FF

    setAddressBackColor(        addr_background );  // address background
    setAddressForeColor(        addr_text       );  // address text, but ALSO highlighted hex
    setHighlightColor(          addr_highlight  );  // address highlighted text
}

void MemoryMapPrivate::fixWidth(int width)
{
    setFixedWidth(width);
}

void MemoryMapPrivate::loadData(QByteArray binarydata)
{
    QHexEditData * hexeditdata = QHexEditData::fromMemory(binarydata);
    setData(hexeditdata);
}

QSize MemoryMapPrivate::sizeHint() const
{
    return size();
}
