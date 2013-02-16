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

void CTicTacToe::setPlayerPlay(int pNumber)
{
    playerPlay = pNumber;
}

int CTicTacToe::getPlayerPlay()
{
    return playerPlay;
}

void CTicTacToe::setPlayerName(int pNumber, QString pName)
{
    if (pNumber == 1)
    {
        playerName1 = pName;
    } else if (pNumber == 2) {
        playerName2 = pName;
    }
}

QString CTicTacToe::getPlayerName(int pNumber)
{
    if (pNumber == 1)
    {
        return playerName1;
    } else if (pNumber == 2) {
        return playerName2;
    }
    return 0;
}

void CTicTacToe::setPlayerCheckBoxState(int pNumber, Qt::CheckState pCheckState)
{
    if (pNumber == 1)
    {
        playerCheckBoxState1 = pCheckState;
    } else if (pNumber == 2) {
        playerCheckBoxState2 = pCheckState;
    }
}

Qt::CheckState CTicTacToe::getPlayerCheckBoxState(int pNumber)
{
    if (pNumber == 1)
    {
        return playerCheckBoxState1;
    } else if (pNumber == 2) {
        return playerCheckBoxState2;
    }
    return Qt::Unchecked;
}


QString CTicTacToe::getPlayerCheckBoxStateString(int pNumber)
{
    if (pNumber == 1)
    {
        if (playerCheckBoxState1 == Qt::PartiallyChecked)
        {
            return "Box";
        }

    } else if (pNumber == 2) {
        if (playerCheckBoxState2 == Qt::PartiallyChecked)
        {
            return "Box";
        }

    }
    return "Hacken";
}
