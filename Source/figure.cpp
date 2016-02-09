#include "figure.h"

Figure::Figure()
{
    x=5;
    y=1;
}

Figure_I::Figure_I()
{
    Figure();
    figureMatrix={
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0} };
    size=4;
    blockType=1;
}


Figure_J::Figure_J()
{
    figureMatrix={
        {0,2,0},
        {0,2,0},
        {2,2,0} };
    size=3;
    blockType=2;
}

Figure_L::Figure_L()
{
    figureMatrix={
        {0,3,0},
        {0,3,0},
        {0,3,3} };
    size=3;
    blockType=3;
}

Figure_O::Figure_O()
{
    figureMatrix={
        {4,4},
        {4,4} };
    size=2;
    blockType=4;
}

Figure_S::Figure_S()
{
    figureMatrix={
        {0,0,0},
        {0,5,5},
        {5,5,0} };
    size=3;
    blockType=5;
}

Figure_T::Figure_T()
{
    figureMatrix={
        {0,0,0},
        {0,6,0},
        {6,6,6} };
    size=3;
    blockType=6;

}

Figure_Z::Figure_Z()
{
    figureMatrix={
        {0,0,0},
        {7,7,0},
        {0,7,7} };
    size=3;
    blockType=7;
}

void Figure::rotate()
{

    std::vector<std::vector<int>> buf;

    buf=figureMatrix;

    for(int i=0;i<figureMatrix.size();i++)
        for(int j=0; j<figureMatrix.size();j++)
            figureMatrix[i][j]=buf[j][figureMatrix.size()-i-1];

}

void Figure::setPosition(int _x,int _y)
{
    x=_x;
    y=_y;
}

int Figure::getX()
{
    return x;
}

int Figure::getY()
{
    return y;
}

int Figure::getSize()
{
    return size;
}

int Figure::getBlockType(int i, int j)
{
    return figureMatrix[i][j];
}

Figure* Figure::generateFigure()
{
    srand(time(NULL));
    int p;
    p=random()%COUNT_OF_FIGURE + 1;
    switch(p)
    {
    case 1: {Figure_I* figure=new Figure_I(); return figure;}
    case 2: {Figure_J* figure=new Figure_J(); return figure;}
    case 3: {Figure_L* figure=new Figure_L(); return figure;}
    case 4: {Figure_O* figure=new Figure_O(); return figure;}
    case 5: {Figure_S* figure=new Figure_S(); return figure;}
    case 6: {Figure_T* figure=new Figure_T(); return figure;}
    case 7: {Figure_Z* figure=new Figure_Z(); return figure;}
    default: {Figure_I* figure=new Figure_I(); return figure;}
    }
}

int Figure::getFigureMatrixElem(int i, int j)
{
    return figureMatrix[i][j];
}
