#pragma once

#include "QHexEdit/qhexedit.h"

class MemoryMap : public QHexEdit
{
    Q_OBJECT
public:
    explicit MemoryMap(QWidget *parent = 0);
    void recolor(
            QColor hex_background,
            QColor hex_line,
            QColor hex_text,
            QColor hex_text_alt,
            QColor addr_background,
            QColor addr_text,
            QColor addr_highlight);

public slots:
    void fixWidth(int width);
    void loadFile(QString filename);
    QSize sizeHint() const;
};

