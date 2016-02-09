#include "board.h"

Board::Board()
{
    refresh();
}

void Board::refresh()
{
    Matrix= std::vector<std::vector<int>>(height);
    for(int i=0;i<height;i++)
        Matrix[i].resize(width);

    for(int i=0;i<height;i++)
    {
        if(i==0||i==height-1)
        {
            for(int j=0;j<width;j++)
                Matrix[i][j]=-1;
            continue;
        }
        for(int j=0;j<width;j++)
            if(j==0||j==width-1)
                Matrix[i][j]=-1;
            else
                Matrix[i][j]=0;
    }
}

int Board::getHeight()
{
    return height;
}

int Board::getWidth()
{
    return width;
}

void Board::Draw()
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            std::cout<<Matrix[i][j];
        }
        std::cout<<std::endl;
    }
}

void Board::setFigure(Figure figure)
{
    for(int i=0;i<figure.getSize();i++)
        for(int j=0;j<figure.getSize();j++)
        {
            if(figure.getFigureMatrixElem(i,j)==0) continue;
            Matrix[figure.getY()+i][figure.getX()+j]=figure.getFigureMatrixElem(i,j);
        }
}

bool Board::checkSolidLine()
{
    int i, j;
    for(i=height-2;i>0;i--)
    {
        for( j=width-2;j>0;j--)
            if(Matrix[i][j]==0)  break;
        if(j==0){ delSolidLine(i); i++;}
    }
}

void Board::delSolidLine(int i)
{
    for(int j=1;j<width-1;j++)
        Matrix[i][j]=0;
    int buf;

    for(int y=i-1;y>0;y--)
        for(int x=1;x<width-1;x++)
        {
            buf=Matrix[y][x];
            Matrix[y+1][x]=buf;
        }
}

int Board::getMatrixElem(int i, int j)
{
    return Matrix[i][j];
}
