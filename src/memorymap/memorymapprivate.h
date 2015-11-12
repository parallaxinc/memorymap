#pragma once

#include "../QHexEdit/qhexedit.h"

class MemoryMapPrivate : public QHexEdit
{
    Q_OBJECT
public:
    explicit MemoryMapPrivate(QWidget *parent = 0);
    void recolor(
            QColor hex_background,
            QColor hex_line,
            QColor hex_text,
            QColor hex_text_alt,
            QColor addr_background,
            QColor addr_text,
            QColor addr_highlight);
    void loadData(QByteArray binarydata);

public slots:
    void fixWidth(int width);
    QSize sizeHint() const;
};

