#include "TicTacToe.h"
CTicTacToe::CTicTacToe(QObject *parent) :
    QObject(parent)
{
}


int CTicTacToe::startGame(Ui::CMainWindow* ui)
{
    /*
     *Param1: Pointer zu ui.
     *
     *Bereitet Spielfeld zum Spielen vor.
     *
     */
    setIsStated(false);
    ui->checkBox_1->setEnabled(false);
    ui->checkBox_2->setEnabled(false);
    ui->checkBox_3->setEnabled(false);
    ui->checkBox_4->setEnabled(false);
    ui->checkBox_5->setEnabled(false);
    ui->checkBox_6->setEnabled(false);
    ui->checkBox_7->setEnabled(false);
    ui->checkBox_8->setEnabled(false);
    ui->checkBox_9->setEnabled(false);
    return 0;
}

bool CTicTacToe::gameEnded(Ui::CMainWindow* ui, bool pDraw)
{
    /*
     *Param1: Pointer zu ui
     *Optional Param2: ob Spiel Unentschieden Endete ( 0 / 9 Felder frei )
     *
     *Disabled Spielfeld.
     *return true;
     */
    toggleGameField(ui);
    ui->textEditLog->clear();
    ui->textEditLog->append("----------- Das Spiel ist zu Ende -------------");
    if (!pDraw)
    {
        ui->textEditLog->append(getPlayerName(getPlayerPlay()) + " hat gewonnen!");
    } else {
        ui->textEditLog->append("Das Spiel Endet Unentschieden!");
    }
    setIsStated(false);
    return true;
}

bool CTicTacToe::getIsStarted()
{
    return isStarted;
}

void CTicTacToe::setIsStated(bool pIsStarted)
{
    isStarted = pIsStarted;
}

void CTicTacToe::setPlayerPlay(int pNumber, Ui::CMainWindow* ui)
{
    playerPlay = pNumber;
    ui->textEditLog->append(getPlayerName(pNumber) + " ist nun am Zug. Mit Symbol: " + getPlayerCheckBoxStateString(pNumber));

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
    /*
     *Param1: pNumber
     *
     *return Symbol als String
     */
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

void CTicTacToe::setPlayableFields(int pAnzahl)
{
    playableFields = pAnzahl;
}

int CTicTacToe::getPlayableFields()
{
    return playableFields;
}

void CTicTacToe::checkGameState(Ui::CMainWindow *ui, QObject *sender)
{
    /*
     *Param1: Pointer zu ui
     *Param2: Clicked Object ( Sender von Slot )
     *
     *
     *Checkt ob 3 in einer Reihe
     *Check ob das Spiel noch Spielbar ist ( X > 0)
     *Toggle Player wenn noch keiner Gewonnen und ist Spielbar.
     *
     */
    QCheckBox* box = static_cast<QCheckBox*>(sender);
    Qt::CheckState pCheckState = getPlayerCheckBoxState(getPlayerPlay());

    box->setCheckState(pCheckState);
    box->setEnabled(false);
    setPlayableFields(getPlayableFields()-1);

    QString senderName = sender->objectName();
    bool isEnde = false;
    if (senderName == ui->checkBox_1->objectName())
    {
        if (ui->checkBox_1->checkState() == pCheckState && ui->checkBox_2->checkState() == pCheckState && ui->checkBox_3->checkState() == pCheckState ||
            ui->checkBox_1->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState ||
            ui->checkBox_1->checkState() == pCheckState && ui->checkBox_4->checkState() == pCheckState && ui->checkBox_7->checkState() == pCheckState  )
        {
           isEnde = gameEnded(ui);
        }
    } else if (senderName == ui->checkBox_2->objectName())
    {
        if (ui->checkBox_1->checkState() == pCheckState && ui->checkBox_2->checkState() == pCheckState && ui->checkBox_3->checkState() == pCheckState ||
            ui->checkBox_2->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_8->checkState() == pCheckState  )
        {
           isEnde = gameEnded(ui);
        }
    } else if (senderName == ui->checkBox_3->objectName())
    {
        if (ui->checkBox_1->checkState() == pCheckState && ui->checkBox_2->checkState() == pCheckState && ui->checkBox_3->checkState() == pCheckState ||
            ui->checkBox_3->checkState() == pCheckState && ui->checkBox_6->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState ||
            ui->checkBox_3->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_7->checkState() == pCheckState  )
        {
            isEnde = gameEnded(ui);
        }
    } else if (senderName == ui->checkBox_4->objectName())
    {
        if (ui->checkBox_1->checkState() == pCheckState && ui->checkBox_4->checkState() == pCheckState && ui->checkBox_7->checkState() == pCheckState ||
            ui->checkBox_4->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_6->checkState() == pCheckState  )
        {
            isEnde = gameEnded(ui);

        }
    } else if (senderName == ui->checkBox_5->objectName())
    {
        if (ui->checkBox_4->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_6->checkState() == pCheckState ||
            ui->checkBox_1->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState ||
            ui->checkBox_3->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_7->checkState() == pCheckState  )
        {
            isEnde = gameEnded(ui);
        }
    } else if (senderName == ui->checkBox_6->objectName())
    {
        if (ui->checkBox_4->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_6->checkState() == pCheckState ||
            ui->checkBox_3->checkState() == pCheckState && ui->checkBox_6->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState)
        {
            isEnde = gameEnded(ui);
        }
    } else if (senderName == ui->checkBox_7->objectName())
    {
        if (ui->checkBox_7->checkState() == pCheckState && ui->checkBox_8->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState ||
            ui->checkBox_1->checkState() == pCheckState && ui->checkBox_4->checkState() == pCheckState && ui->checkBox_7->checkState() == pCheckState ||
            ui->checkBox_3->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_7->checkState() == pCheckState )
        {
            isEnde = gameEnded(ui);
        }
    } else if (senderName == ui->checkBox_8->objectName())
    {
        if (ui->checkBox_7->checkState() == pCheckState && ui->checkBox_8->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState ||
            ui->checkBox_2->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_8->checkState() == pCheckState)
        {
            isEnde = gameEnded(ui);
        }
    } else if (senderName == ui->checkBox_9->objectName())
    {
        if (ui->checkBox_7->checkState() == pCheckState && ui->checkBox_8->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState ||
            ui->checkBox_1->checkState() == pCheckState && ui->checkBox_5->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState ||
            ui->checkBox_3->checkState() == pCheckState && ui->checkBox_6->checkState() == pCheckState && ui->checkBox_9->checkState() == pCheckState)
        {
            isEnde = gameEnded(ui);
        }
    }
    if (isEnde)
    {
        return;
    }
    if ( getPlayableFields() == 0)
    {
        gameEnded(ui, true);
    }
    if ( getIsStarted() == true)
    {
        (getPlayerPlay() == 1) ? setPlayerPlay(2, ui) : setPlayerPlay(1, ui);
    }

}

void CTicTacToe::toggleGameField(Ui::CMainWindow* ui)
{
    /*
     *Param1: Pointer zu ui
     *
     *
     *Wenn Spiel noch nicht angefangen: Checke ob alle Felder ausgefüllt
     *wenn ja, Bereite Spielfeld und Spiel vor.
     *
     *Wenn schon begonnen, beende Spiel.
     */
    if (getIsStarted() == false) {
        if ( ui->lineEditName1->text().isEmpty() == true ||
             ui->lineEditName2->text().isEmpty() == true ||
             ui->checkBoxSymbol1->checkState() == Qt::Unchecked ) {
            MessageBox(NULL, L"Eines der Objekte wurde nicht ausgefüllt.", L"Error!", MB_ICONERROR);
            return;
        }
            ui->lineEditName1->setReadOnly(true);
            ui->lineEditName1->setEnabled(false);

            ui->lineEditName2->setReadOnly(true);
            ui->lineEditName2->setEnabled(false);

            ui->checkBoxSymbol1->setEnabled(false);
            ui->checkBoxSymbol2->setEnabled(false);


            ui->checkBox_1->setEnabled(true);
            ui->checkBox_1->setChecked(false);

            ui->checkBox_2->setEnabled(true);
            ui->checkBox_2->setChecked(false);

            ui->checkBox_3->setEnabled(true);
            ui->checkBox_3->setChecked(false);

            ui->checkBox_4->setEnabled(true);
            ui->checkBox_4->setChecked(false);

            ui->checkBox_5->setEnabled(true);
            ui->checkBox_5->setChecked(false);

            ui->checkBox_6->setEnabled(true);
            ui->checkBox_6->setChecked(false);

            ui->checkBox_7->setEnabled(true);
            ui->checkBox_7->setChecked(false);

            ui->checkBox_8->setEnabled(true);
            ui->checkBox_8->setChecked(false);

            ui->checkBox_9->setEnabled(true);
            ui->checkBox_9->setChecked(false);

            ui->pushButtonSave->setText("Spiel Beenden");

            setPlayerName(1, ui->lineEditName1->text());
            setPlayerName(2, ui->lineEditName2->text());
            setPlayerCheckBoxState(1, ui->checkBoxSymbol1->checkState());
            setPlayerCheckBoxState(2, ui->checkBoxSymbol2->checkState());

            ui->textEditLog->clear();
            ui->textEditLog->append("Das Spiel kann beginnen...");
            ui->textEditLog->append("Informationen ueber Spieler Nummer 1:\nSpieler Name: " + getPlayerName(1) + "\nSpieler Symbol: " + getPlayerCheckBoxStateString(1) + "\n");
            ui->textEditLog->append("Informationen ueber Spieler Nummer 2:\nSpieler Name: " + getPlayerName(2) + "\nSpieler Symbol: " + getPlayerCheckBoxStateString(2)+ "\n");

            setPlayableFields(9);
            setIsStated(true);
            setPlayerPlay(1, ui);
    } else {

        setIsStated(false);

        ui->checkBox_1->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_4->setEnabled(false);
        ui->checkBox_5->setEnabled(false);
        ui->checkBox_6->setEnabled(false);
        ui->checkBox_7->setEnabled(false);
        ui->checkBox_8->setEnabled(false);
        ui->checkBox_9->setEnabled(false);
        ui->lineEditName1->clear();
        ui->lineEditName2->clear();
        ui->checkBoxSymbol1->setCheckState(Qt::Unchecked);
        ui->checkBoxSymbol2->setCheckState(Qt::Unchecked);

        ui->lineEditName1->setReadOnly(false);
        ui->lineEditName1->setEnabled(true);

        ui->lineEditName2->setReadOnly(false);
        ui->lineEditName2->setEnabled(true);

        ui->checkBoxSymbol1->setEnabled(true);
        ui->checkBoxSymbol2->setEnabled(true);

        ui->textEditLog->append("Das Spiel wurde beendet.");
        ui->pushButtonSave->setText("Save && GO");

    }
}


