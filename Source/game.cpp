#include "game.h"

Game::Game(){}

void Game::start()
{
    f_active=NULL;
    gameOver=false;
    board.refresh();
}

bool Game::isCollision(Figure f)
{//i - height, j - width

    for(int i=0;i<f.getSize();i++)
        for(int j=0;j<f.getSize();j++)
             if(f.getFigureMatrixElem(i,j)!=0 && board.getMatrixElem(f.getY()+i,f.getX()+j)!=0)
                return true;
    return false;
}

void Game::doStep()
{
    board.Draw();
    if (f_active==NULL)
    {
        BottomTouchCounter=0;
        f_active=Figure::generateFigure();
        f_active->setPosition((board.getWidth()/2)-1,1);
        if(isCollision(*f_active))
        {
            gameOver = true;
        }
    }

    if(isGameOver()) return;

    f_active->setPosition(f_active->getX(), f_active->getY()+1);

    if(!isCollision(*f_active))
    {
        BottomTouchCounter=0;
    }
    else
    {
        while(isCollision(*f_active))
            f_active->setPosition(f_active->getX(),f_active->getY()-1);

        if( BottomTouchCounter > 2)
        {
            board.setFigure(*f_active);
            delete f_active;
            f_active=NULL;
        }
        else
        {
            BottomTouchCounter++;
        }
    }
    board.checkSolidLine();
}

bool Game::isGameOver()
{
    return gameOver;
}



int Game::getMatrixHeight()
{
    return board.getHeight();
}

int Game::getMatrixWidth()
{
    return board.getWidth();
}

int Game::getType(int i, int j)
{
    return board.getMatrixElem(i,j);
}

Figure* Game::getFigure()
{
    return f_active;
}

void Game::moveItemLeft()
{
    if(f_active==NULL) return;
    f_active->setPosition(f_active->getX()-1, f_active->getY());
    if (isCollision(*f_active)) f_active->setPosition(f_active->getX()+1, f_active->getY());
}

void Game::moveItemRight()
{
    if(f_active==NULL) return;
    f_active->setPosition(f_active->getX()+1, f_active->getY());
    if (isCollision(*f_active)) f_active->setPosition(f_active->getX()-1, f_active->getY());
}

void Game::rotateItem()
{
    Figure f_copy;
    f_copy=*f_active;
    f_copy.rotate();
    if(isCollision(f_copy)) return;
    if(f_active==NULL) return;
    f_active->rotate();
}
