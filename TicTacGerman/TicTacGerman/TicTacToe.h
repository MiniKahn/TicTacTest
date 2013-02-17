#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QObject>
#include "stdafx.h"
#include "ui_MainWindow.h"
class CTicTacToe : public QObject
{
    Q_OBJECT
public:
    explicit CTicTacToe(QObject *parent = 0);
    int startGame(Ui::CMainWindow* ui);

    bool getIsStarted();
    void setIsStated(bool pIsStarted);

    void setPlayerName(int, QString);
    QString getPlayerName(int pNumber);

    void setPlayerCheckBoxState(int, Qt::CheckState);
    Qt::CheckState getPlayerCheckBoxState(int);

    QString getPlayerCheckBoxStateString(int pNumber);

    int getPlayerPlay();
    void setPlayerPlay(int, Ui::CMainWindow*);


    void setPlayableFields(int pAnzahl);
    int getPlayableFields();
    void toggleGameField(Ui::CMainWindow* ui);
    void gameEnded(Ui::CMainWindow* ui, bool pDraw = false);


    void checkGameState(Ui::CMainWindow* ui, QObject* sender);
signals:
    
public slots:

private:
    bool isStarted;
    int playableFields;
    QString playerName1;
    QString playerName2;
    Qt::CheckState playerCheckBoxState1;
    Qt::CheckState playerCheckBoxState2;

    int playerPlay;

};

#endif // TICTACTOE_H
