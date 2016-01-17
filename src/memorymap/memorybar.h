#pragma once

#include <QDebug>
#include <QFrame>
#include <QLinearGradient>
#include <QPainter>
#include <Qt>

class MemoryBar : public QFrame
{
    Q_OBJECT

    int _min, _max;
    int _program, _variable, _stack;
    QColor colorProgram, colorVariable, colorStack;

private:

    void paintEvent(QPaintEvent * e)
    {
        QFrame::paintEvent(e);

        QPainter p(this);
//        p.drawLine(0,0,width(),height());
        drawBar(&p, 0, _program, Qt::red);
        drawBar(&p, _program, _program+_variable, Qt::yellow);
        drawBar(&p, _program+_variable, _program+_variable+_stack, Qt::blue);
    }

public:
    void drawBar(QPainter * painter, int min, int max, QColor color)
    {
        QLinearGradient gradient(0,0,0,height());
        gradient.setColorAt(0, color);
        gradient.setColorAt(1, color.darker(150));
        QBrush brush(gradient);

        int w = (max - min)*(width()-2)/(this->_max);
        int x = (min)*(width()-2)/(this->_max);

        painter->fillRect(1 + x, 1, 1 + x + w, height()-2, brush);
    }

    void configure(int min, 
            int max, 
            int program, 
            int variable, 
            int stack)
    {
        this->_min       = min;
        this->_max       = max;
        this->_program   = program;
        this->_variable  = variable;
        this->_stack     = stack;

        update();
    }

    explicit MemoryBar(QWidget *parent) : QFrame(parent)
    {
        colorProgram  = QColor(Qt::red);
        colorVariable = QColor(Qt::yellow);
        colorStack    = QColor(Qt::blue);
    }

    ~MemoryBar()
    {
    }
};


