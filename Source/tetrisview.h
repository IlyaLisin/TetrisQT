#ifndef TETRISVIEW_H
#define TETRISVIEW_H

#include <QWidget>
#include <game.h>
#include <controller.h>
#include "figureview.h"

class TetrisView : public QWidget
{
    Q_OBJECT
protected:
    void paintEvent( QPaintEvent* );
    void keyPressEvent( QKeyEvent* e );
    void keyReleaseEvent( QKeyEvent* e );

    void drawBlock( int xPoints, int yPoints, int type, QPainter* painter );

private:
    static const int BLOCK_SIZE=20;
    Game game;
    Controller* controller;
    FigureView* fView;

public:
    explicit TetrisView( QWidget* parent = 0 );
    ~TetrisView();

    void refresh();
};

#endif // TETRISVIEW_H
