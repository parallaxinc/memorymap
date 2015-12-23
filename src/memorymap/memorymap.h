#pragma once

#include <QColor>
#include <QWidget>

#include <PropellerManager>
#include <PropellerImage>

#include "ui_memorymap.h"

class MemoryMap : public QWidget
{
    Q_OBJECT
private:
    Ui::MemoryMap ui;
    void keyPressEvent(QKeyEvent* event);
    PropellerManager * manager;
    PropellerImage image;
    QString port;

public:
    explicit MemoryMap(PropellerManager * manager, QWidget *parent = 0);
    void recolor(
            QColor hex_background,
            QColor hex_line,
            QColor hex_text,
            QColor hex_text_alt,
            QColor addr_background,
            QColor addr_text,
            QColor addr_highlight);

    void setFont(QFont font);
    void openFile(QString binaryfile);
    void openData(QByteArray binarydata);
public slots:
    void fixWidth(int width);
    void open();
    void save();
    void updateColors();
    void sendRun();
    void sendWrite();

signals:
    void getRecolor(QWidget * widget);
    void run(QByteArray binary);
    void write(QByteArray binary);
};

