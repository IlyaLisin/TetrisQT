#include "tetrisview.h"
#include <QPainter>
#include <QKeyEvent>

TetrisView::TetrisView( QWidget* parent ) : QWidget( parent )
{
    controller = new Controller( &game, this, this );
    controller->onStart();
    resize(game.getMatrixWidth()*BLOCK_SIZE,game.getMatrixHeight()*BLOCK_SIZE );
}

TetrisView::~TetrisView(){}

void TetrisView::refresh()
{
    repaint();
}

void TetrisView::paintEvent( QPaintEvent* )
{
    QPainter painter( this );
    painter.fillRect( BLOCK_SIZE, BLOCK_SIZE, (game.getMatrixWidth()-2)*BLOCK_SIZE, (game.getMatrixHeight()-2)*BLOCK_SIZE, Qt::black );
    for( int i = 0; i < game.getMatrixHeight();i++ )
    {
        for( int j = 0; j < game.getMatrixWidth(); j++ )
        {
            drawBlock( i, j, game.getType(i,j), &painter );
        }
    }

    Figure *f_active = game.getFigure();
    fView=new FigureViewQT(f_active,this);
    fView->draw();
    delete fView;
}

void TetrisView::keyPressEvent( QKeyEvent* e )
{
    switch( e->key() )
    {
    case Qt::Key_Left:
        controller->onMoveLeft();
        break;
    case Qt::Key_Right:
        controller->onMoveRight();
        break;
    case Qt::Key_Up:
        controller->onRotate();
        break;
    case Qt::Key_Down:
        controller->onDropEnabled( true );
        break;
    case Qt::Key_Space:
        controller->onTogglePause();
        break;
    default:
        QWidget::keyPressEvent( e );
    }
}

void TetrisView::keyReleaseEvent( QKeyEvent* e )
{
    switch( e->key() )
    {
    case Qt::Key_Down:
        controller->onDropEnabled( false );
        break;
    default:
        QWidget::keyReleaseEvent( e );
    }
}

void TetrisView::drawBlock( int x, int y, int type , QPainter* painter )
{
    static const std::vector< QColor > COLOR_TABLE = {
        Qt::white,
        Qt::yellow,
        Qt::green,
        Qt::red,
        Qt::cyan,
        Qt::magenta,
        Qt::lightGray
    };

    if (type==0 || type == -1) return;
    if( type <= 0 || COLOR_TABLE.size() < type )
    {
        return;
    }

    //painter->drawRect(y*BLOCK_SIZE, x*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
    painter->fillRect( y*BLOCK_SIZE+1, x*BLOCK_SIZE+1, BLOCK_SIZE-1, BLOCK_SIZE-1, COLOR_TABLE[ type - 1 ] );
}
