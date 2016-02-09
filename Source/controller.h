#ifndef TETRISCONTROLLER_H
#define TETRISCONTROLLER_H

#include <QObject>
#include <QTimer>

class Game;
class TetrisView;

class Controller : QObject
{
    Q_OBJECT
public:
    Controller( Game* c_game, TetrisView* c_view, QObject* parent = 0 );

public slots:
    void onStart();
    void onPause();
    void onResume();
    void onStep();

    void onMoveLeft();
    void onMoveRight();
    void onRotate();

    void onDropEnabled( bool enabled );

    void onTogglePause();

private:
    void onAction( void ( Game::*action )() );

    Game* game;
    TetrisView* view;
    QTimer* timer;
};

#endif // TETRISCONTROLLER_H
