#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <cstdlib>
#include <time.h>

class Figure
{
protected:
    int size;
    int blockType;
    std::vector<std::vector<int> > figureMatrix;

private:
    const static int COUNT_OF_FIGURE=7;
    int x,y; // координаты фигуры

public:
    Figure();
    void setPosition(int i,int j); // установить координаты фигуры
    int getX();
    int getY();
    int getSize();
    void rotate();
    int getBlockType(int i,int j); // получить тип блока
    static  Figure* generateFigure();
    int getFigureMatrixElem(int i,int j);
};

class Figure_I: public Figure
{
public:
    Figure_I();
};

class Figure_J: public Figure
{
public:
    Figure_J();
};


class Figure_L:public Figure
{
public:
    Figure_L();
};

class Figure_O:public Figure
{
public:
    Figure_O();
};

class Figure_S:public Figure
{
public:
    Figure_S();
};

class Figure_T: public Figure
{
public:
    Figure_T();
};

class Figure_Z: public Figure
{
public:
    Figure_Z();
};

#endif // FIGURE_H
