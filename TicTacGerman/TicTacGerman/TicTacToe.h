#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QObject>
#include "stdafx.h"
class CTicTacToe : public QObject
{
    Q_OBJECT
public:
    explicit CTicTacToe(QObject *parent = 0);
    int startGame();
    bool getIsStarted();
    void setIsStated(bool pIsStarted);
    void blblblblblb();
    void blablabubbb(int a);
signals:
    
public slots:

private:
    bool isStarted;
    
};

#endif // TICTACTOE_H
