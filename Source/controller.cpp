#include "controller.h"

#include "game.h"
#include "tetrisview.h"
#include <QDebug>

Controller::Controller( Game* c_game , TetrisView* c_view, QObject* parent ) :
    QObject( parent ), game( c_game ), view( c_view )
{
    timer = new QTimer();
    timer->setInterval(500);
    connect( timer, SIGNAL( timeout() ), SLOT( onStep() ) );
}

void Controller::onStart()
{
    game->start();
    timer->start();
}

void Controller::onStep()
{
    game->doStep();
    view->refresh();
    if(game->isGameOver())
    {
        timer->stop();
        onStart();
    }
}

void Controller::onPause()
{
    timer->stop();
}

void Controller::onResume()
{
    timer->start(500);
}

void Controller::onMoveLeft()
{
    onAction( &Game::moveItemLeft );
}

void Controller::onMoveRight()
{
    onAction( &Game::moveItemRight );
}

void Controller::onRotate()
{
    onAction( &Game::rotateItem );
}

void Controller::onDropEnabled( bool enabled )
{
    if(enabled) timer->setInterval(20);
    else
        timer->setInterval(500);
}

void Controller::onTogglePause()
{
    timer->isActive() ? onPause() : onResume();
}

void Controller::onAction( void ( Game::*action )() )
{
    ( game->*action )();
    view->refresh();
}
