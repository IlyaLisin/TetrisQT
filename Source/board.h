#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "figure.h"

class Board
{
private:
    std::vector<std::vector<int> > Matrix;
    const int width =16;
    const int height = 20;

public:
    Board();
    int getWidth();
    int getHeight();
    void refresh();
    void setFigure(Figure figure);//установить фигуру на поле
    bool checkSolidLine(); // проверить заполненные линии
    void delSolidLine(int); // удалить заполненные линии
    void Draw();
    int getMatrixElem(int i, int j);
};

#endif // BOARD_H
