#include "figureview.h"
#include <QPainter>

FigureView::FigureView(){}

FigureViewQT::FigureViewQT(Figure *_figure, QWidget *_widget)
{
    figure=_figure;
    painter=new QPainter(_widget);
}

void FigureViewQT::draw()
{
    if(!figure) return;

    static const std::vector< QColor > COLOR_TABLE = {
        Qt::white,
        Qt::yellow,
        Qt::green,
        Qt::red,
        Qt::cyan,
        Qt::magenta,
        Qt::lightGray
    };

        for( int i = 0; i <figure->getSize() ; i++ )
               {
                  for( int j = 0; j < figure->getSize(); j++ )
                  {
                      int type=figure->getBlockType(i,j);
                      if (type==0 || type == -1) continue;
                          if( type <= 0 || COLOR_TABLE.size() < type )
                          {
                              continue;
                          }

        painter->drawRect((figure->getX()+j)*BLOCK_SIZE, (figure->getY()+i)*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->fillRect((figure->getX()+j)*BLOCK_SIZE+1, (figure->getY()+i)*BLOCK_SIZE+1, BLOCK_SIZE-1, BLOCK_SIZE-1, COLOR_TABLE[ type - 1 ] );
                  }
        }

}
