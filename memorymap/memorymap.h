#pragma once

#include <QWidget>
#include <QColor>
#include <QResizeEvent>
#include "ui_memorymap.h"

class MemoryMap : public QWidget
{
    Q_OBJECT
private:
    Ui::MemoryMap ui;

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

    void setFont(QFont font);
    void loadFile(QString filename);
public slots:
    void fixWidth(int width);
};

