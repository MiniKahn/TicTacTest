#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QObject>
#include "stdafx.h"
#include "ui_MainWindow.h"
#define SPIELER_1 1
#define SPIELER_2 2
#define ALL_FIELDS 9
class CTicTacToe : public QObject
{
    Q_OBJECT
public:
    explicit CTicTacToe(Ui::CMainWindow *ui, QObject *parent = 0);
    void startGame();

    bool getIsStarted();
    void setIsStated(bool pIsStarted);

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


    bool checkThreeInARow( QObject* sender);
    bool hasFreeFields();
    void switchToNextPlayer();
    bool hasThreeInARow(int player);
    void setCheckBoxCheckedForPlayer(QObject* sender, int player);
    void checkGameState(QObject* sender);
    bool isStarted();
    void disableGameFields();
    void enableGameFields();
    void resetGameFields();
    void freezePlayerNamesAndSymbols();
    void releasePlayerNamesAndSymbols();
    void resetPlayerNamesAndSymbols();
    void toggleStartedGameField();
    void togglePausedGameField();
signals:
    
public slots:

private:
    bool started;
    int playableFields;
    QString playerName1;
    QString playerName2;
    Qt::CheckState playerCheckBoxState1;
    Qt::CheckState playerCheckBoxState2;

    int playerPlay;
    Ui::CMainWindow *userInterface;
};

#endif // TICTACTOE_H
