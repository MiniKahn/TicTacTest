#include "TicTacToe.h"

CTicTacToe::CTicTacToe(QObject *parent) :
    QObject(parent)
{
    setIsStated(false);
}


int CTicTacToe::startGame()
{

    return 0;
}


bool CTicTacToe::getIsStarted()
{
    return isStarted;
}

void CTicTacToe::setIsStated(bool pIsStarted)
{
    isStarted = pIsStarted;
}
