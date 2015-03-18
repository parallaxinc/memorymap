#include "memorymap.h"

#include <QDebug>
#include "QHexEdit/qhexedit.h"

MemoryMap::MemoryMap(QWidget *parent): QMainWindow(parent)
{
        
}

void MemoryMap::fixWidth(int width) {
    QHexEdit * hex = findChild<QHexEdit *>();
    qDebug() << size() << hex->size() << hex->sizeHint() << sizeHint();
    setFixedWidth(width);
    qDebug() << "SIZE" << size() << sizeHint();
}
