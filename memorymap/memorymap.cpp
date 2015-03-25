#include "memorymap.h"
#include "memorymapprivate.h"

MemoryMap::MemoryMap(QWidget *parent): QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.buttonLoadBinary,SIGNAL(clicked()),this,SLOT(bigger()));
    connect(ui.buttonSaveBinary,SIGNAL(clicked()),this,SLOT(smaller()));
    connect(ui.frame, SIGNAL(widthChanged(int)), this, SLOT(fixWidth(int)));
}

void MemoryMap::loadFile(QString filename)
{
    ui.frame->loadFile(filename);
}

void MemoryMap::setFont(QFont font)
{
    ui.frame->setFont(font);
}

void MemoryMap::recolor(
            QColor hex_background,
            QColor hex_line,
            QColor hex_text,
            QColor hex_text_alt,
            QColor addr_background,
            QColor addr_text,
            QColor addr_highlight)
{
    ui.frame->recolor(
            hex_background,
            hex_line,
            hex_text,
            hex_text_alt,
            addr_background,
            addr_text,
            addr_highlight);
}

void MemoryMap::fixWidth(int width)
{
    setFixedWidth(width);
}
