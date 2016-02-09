#ifndef FIGUREVIEW_H
#define FIGUREVIEW_H

#include "figure.h"
#include <QWidget>
#include <QPainter>

class FigureView
{
protected:
    Figure *figure;
public:
    FigureView();

    virtual void draw()=0;
};

class FigureViewQT:public FigureView,public QPainter
{
private:
    static const int BLOCK_SIZE = 20;
    QPainter* painter;
public:
    FigureViewQT(Figure *_figure, QWidget *_widget);

    ~FigureViewQT();
    void draw();
};

#endif // FIGUREVIEW_H
