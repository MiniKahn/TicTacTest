#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QObject>
#include "stdafx.h"
#include "ui_MainWindow.h"
#include "MainWindow.h"

#include "ui_options.h"
#include "options.h"
#define SPIELER_1 1
#define SPIELER_2 2
#define ALL_FIELDS 9

class CTicTacToe : public QObject
{
    Q_OBJECT
public:
    explicit CTicTacToe(QObject *parent = 0);

    void startGame();
    void checkGameState(QObject* sender);

    bool getIsStarted();
    void setIsStated(bool pIsStarted);
    bool isStarted();

    void setPlayerName(int, QString);
    QString getPlayerName(int pNumber);

    void setPlayerCheckBoxState(int, Qt::CheckState);
    Qt::CheckState getPlayerCheckBoxState(int pNumber);
    QString getPlayerCheckBoxStateString(int pNumber);

    int getPlayerPlay();
    void setPlayerPlay(int pNumber);
    void setPlayerNamesFromUi();

    void setPlayableFields(int pAnzahl);
    int getPlayableFields();
    void toggleGameField();
    void gameEnded( bool pDraw = false);


    bool hasThreeInARow(int player);
    bool checkThreeInARow( QObject* sender);
    bool hasFreeFields();

    void switchToNextPlayer();
    void setCheckBoxCheckedForPlayer(QObject* sender, int player);

    void disableGameFields();
    void enableGameFields();
    void resetGameFields();

    void freezePlayerNamesAndSymbols();
    void releasePlayerNamesAndSymbols();
    void resetPlayerNamesAndSymbols();

    void toggleStartedGameField();
    void togglePausedGameField();

    bool checkAllFieldsFilled();
signals:
    
public slots:

private slots:


private:
    bool started;
    int playableFields;
    QString playerName1;
    QString playerName2;
    Qt::CheckState playerCheckBoxState1;
    Qt::CheckState playerCheckBoxState2;

    int playerPlay;
    CMainWindow *main;
    Options *options;
};

#endif // TICTACTOE_H
