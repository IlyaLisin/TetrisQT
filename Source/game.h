#ifndef GAME_H
#define GAME_H
#include "figure.h"
#include "board.h"
#include <vector>
class Game
{
private:
    Figure *f_active; //активная фигура
    Board board;
    bool gameOver;
    int BottomTouchCounter;
    bool isCollision(Figure f); //обработка столкновений

public:

    Game();
    void start();
    int getMatrixHeight();
    int getMatrixWidth();
    int getType(int,int); // получить тип эелемента ячейки доски
    Figure* getFigure();
    bool isGameOver();
    void doStep();
    void moveItemLeft();
    void moveItemRight();
    void rotateItem();
};

#endif // GAME_H
