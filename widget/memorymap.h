#pragma once
#include <QMainWindow>

class MemoryMap : public QMainWindow
{
    Q_OBJECT
public:
    explicit MemoryMap(QWidget *parent = 0);

public slots:
    void fixWidth(int width);
};

