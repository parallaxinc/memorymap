#include "memorymap.h"
#include "memorymapprivate.h"

#include <QFileDialog>
#include <QDataStream>

MemoryMap::MemoryMap(QWidget *parent) : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.frame, SIGNAL(widthChanged(int)), this, SLOT(fixWidth(int)));
    connect(ui.buttonOpenBinary, SIGNAL(clicked()), this, SLOT(load()));
    connect(ui.buttonSaveBinary, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui.buttonRun, SIGNAL(clicked()), this, SLOT(sendRun()));
    connect(ui.buttonWrite, SIGNAL(clicked()), this, SLOT(sendWrite()));
}

void MemoryMap::loadFile(QString binaryfile)
{
    QFile file(binaryfile);
    if (!file.open(QIODevice::ReadOnly)) return;
    loadData(file.readAll());
}

void MemoryMap::loadData(QByteArray binarydata)
{
    data.clear();
    data = binarydata;
    ui.frame->loadData(binarydata);
    ui.programSizeBar->setValue(data.size()/4); // longs
}

void MemoryMap::load()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open binary..."),
            QString(), tr("Binary files (*.binary);;All Files (*)"));
        if (!fn.isEmpty())
            loadFile(fn);
}

void MemoryMap::save()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),
            QString(), tr("Binary files (*.binary);;All Files (*)"));

    if (fn.isEmpty())
        return;

    QFile file(fn);
    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream stream(&file);
        stream << data;
    }
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

    // QHexEdit would require non-trivial refactoring to 
    // allow updating hex_text color without reloading data
    ui.frame->loadData(data); 
}

void MemoryMap::fixWidth(int width)
{
    int w = width + qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
    setFixedWidth(w);
}

void MemoryMap::updateColors()
{
    emit getRecolor(this);
}

void MemoryMap::sendRun()
{
    emit run(data);
}

void MemoryMap::sendWrite()
{
    emit write(data);
}