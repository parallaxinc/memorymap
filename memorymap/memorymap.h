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
    QByteArray data;

public:
    explicit MemoryMap(QWidget *parent = 0, Qt::WindowFlags f = 0);
    void recolor(
            QColor hex_background,
            QColor hex_line,
            QColor hex_text,
            QColor hex_text_alt,
            QColor addr_background,
            QColor addr_text,
            QColor addr_highlight);

    void setFont(QFont font);
    void loadFile(QString binaryfile);
    void loadData(QByteArray binarydata);
public slots:
    void fixWidth(int width);
    void load();
    void updateColors();

signals:
    void getRecolor(QWidget * widget);
};

