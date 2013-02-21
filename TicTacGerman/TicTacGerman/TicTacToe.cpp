#include "TicTacToe.h"
CTicTacToe::CTicTacToe(Ui::CMainWindow *ui,  QObject *parent) :
    QObject(parent)
{
    this->userInterface = ui;
}


void CTicTacToe::startGame()
{
    /*
     *
     *Bereitet Spielfeld zum Spielen vor.
     *
     */
    releasePlayerNamesAndSymbols();
    disableGameFields();
}

void CTicTacToe::gameEnded(bool pDraw)
{
    /**
     *Disabled Spielfeld. And send win message.
     *@param: Optional: Ob Spiel Unentschieden Endete ( 0 / 9 Felder frei )
     *
     */
    toggleGameField();
    this->userInterface->textEditLog->clear();
    this->userInterface->textEditLog->append("----------- Das Spiel ist zu Ende -------------");
    if (!pDraw)
    {
        this->userInterface->textEditLog->append(getPlayerName(getPlayerPlay()) + " hat gewonnen!");
    } else {
        this->userInterface->textEditLog->append("Das Spiel Endet Unentschieden!");
    }
    setIsStated(false);
}

bool CTicTacToe::getIsStarted()
{
    return started;
}

void CTicTacToe::setIsStated(bool pIsStarted)
{
    started = pIsStarted;
}

bool CTicTacToe::isStarted()
{

    if (getIsStarted() == true) {
        return true;
    }

    return false;
}

void CTicTacToe::setPlayerPlay(int pNumber)
{

    playerPlay = pNumber;
    this->userInterface->textEditLog->append(getPlayerName(pNumber) + " ist nun am Zug. Mit Symbol: " + getPlayerCheckBoxStateString(pNumber));

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
    return "";
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
    /**
     *@param: pNumber
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

/**
 * Check state of the active game
 *
 * @param Ui      Pointer zu ui
 * @param QObject Clicked Object ( Sender von Slot )
 */
void CTicTacToe::checkGameState( QObject *sender)
{
    if (!checkThreeInARow(sender))
    {
        if (hasFreeFields())
        {
            switchToNextPlayer();
        }
    }
}

bool CTicTacToe::checkThreeInARow( QObject* sender)
{
    int player = getPlayerPlay();
    setCheckBoxCheckedForPlayer(sender, player);

    if (hasThreeInARow(player)) {
        gameEnded();
        return true;
    }


    setPlayableFields(getPlayableFields()-1);
    return false;
}

void CTicTacToe::setCheckBoxCheckedForPlayer(QObject* sender, int player)
{
    /**
     * @param: QObject sender: Object to the pressed Checkbox
     * @param: int player: Player who play
     */

    Qt::CheckState pCheckState = getPlayerCheckBoxState(player);
    QCheckBox* box = static_cast<QCheckBox*>(sender);
    box->setCheckState(pCheckState);
    box->setEnabled(false);
}

bool CTicTacToe::hasThreeInARow(int player)
{
    // TODO: isChecked(checkBox_3);

    Qt::CheckState pCheckState = getPlayerCheckBoxState(player);

    if (this->userInterface->checkBox_1->checkState() == pCheckState && this->userInterface->checkBox_2->checkState() == pCheckState && this->userInterface->checkBox_3->checkState() == pCheckState) {
        return true;
    }
    if (this->userInterface->checkBox_4->checkState() == pCheckState && this->userInterface->checkBox_5->checkState() == pCheckState && this->userInterface->checkBox_6->checkState() == pCheckState) {
        return true;
    }

    if (this->userInterface->checkBox_7->checkState() == pCheckState && this->userInterface->checkBox_8->checkState() == pCheckState && this->userInterface->checkBox_9->checkState() == pCheckState) {
        return true;
    }

    if (this->userInterface->checkBox_1->checkState() == pCheckState && this->userInterface->checkBox_4->checkState() == pCheckState && this->userInterface->checkBox_7->checkState() == pCheckState) {
        return true;
    }

    if (this->userInterface->checkBox_2->checkState() == pCheckState && this->userInterface->checkBox_5->checkState() == pCheckState && this->userInterface->checkBox_8->checkState() == pCheckState) {
        return true;
    }

    if (this->userInterface->checkBox_3->checkState() == pCheckState && this->userInterface->checkBox_6->checkState() == pCheckState && this->userInterface->checkBox_9->checkState() == pCheckState) {
        return true;
    }

    if (this->userInterface->checkBox_1->checkState() == pCheckState && this->userInterface->checkBox_5->checkState() == pCheckState && this->userInterface->checkBox_9->checkState() == pCheckState) {
        return true;
    }

    if (this->userInterface->checkBox_3->checkState() == pCheckState && this->userInterface->checkBox_5->checkState() == pCheckState && this->userInterface->checkBox_7->checkState() == pCheckState) {
        return true;
    }

    return false;
}



bool CTicTacToe::hasFreeFields()
{
    if ( getPlayableFields() == 0)
    {
        gameEnded(true);
        return false;
    }
    return true;
}

void CTicTacToe::switchToNextPlayer()
{
    if (isStarted())
    {
        (getPlayerPlay() == SPIELER_1) ? setPlayerPlay(SPIELER_2) : setPlayerPlay(SPIELER_1);
    }
}

void CTicTacToe::toggleGameField()
{


    if (!isStarted()) {
        toggleStartedGameField();
    } else {
        togglePausedGameField();
    }
}



void CTicTacToe::disableGameFields()
{
    this->userInterface->checkBox_1->setEnabled(false);
    this->userInterface->checkBox_2->setEnabled(false);
    this->userInterface->checkBox_3->setEnabled(false);
    this->userInterface->checkBox_4->setEnabled(false);
    this->userInterface->checkBox_5->setEnabled(false);
    this->userInterface->checkBox_6->setEnabled(false);
    this->userInterface->checkBox_7->setEnabled(false);
    this->userInterface->checkBox_8->setEnabled(false);
    this->userInterface->checkBox_9->setEnabled(false);
}

void CTicTacToe::enableGameFields()

{
    this->userInterface->checkBox_1->setEnabled(true);
    this->userInterface->checkBox_3->setEnabled(true);
    this->userInterface->checkBox_2->setEnabled(true);
    this->userInterface->checkBox_4->setEnabled(true);
    this->userInterface->checkBox_5->setEnabled(true);
    this->userInterface->checkBox_6->setEnabled(true);
    this->userInterface->checkBox_7->setEnabled(true);
    this->userInterface->checkBox_8->setEnabled(true);
    this->userInterface->checkBox_9->setEnabled(true);
}


void CTicTacToe::resetGameFields()
{
    this->userInterface->checkBox_1->setChecked(false);
    this->userInterface->checkBox_2->setChecked(false);
    this->userInterface->checkBox_3->setChecked(false),
    this->userInterface->checkBox_4->setChecked(false);
    this->userInterface->checkBox_5->setChecked(false);
    this->userInterface->checkBox_6->setChecked(false);
    this->userInterface->checkBox_7->setChecked(false);
    this->userInterface->checkBox_8->setChecked(false);
    this->userInterface->checkBox_9->setChecked(false);
}

void CTicTacToe::freezePlayerNamesAndSymbols()
{
    this->userInterface->lineEditName1->setReadOnly(true);
    this->userInterface->lineEditName1->setEnabled(false);

    this->userInterface->lineEditName2->setReadOnly(true);
    this->userInterface->lineEditName2->setEnabled(false);

    this->userInterface->checkBoxSymbol1->setEnabled(false);
    this->userInterface->checkBoxSymbol2->setEnabled(false);
}

void CTicTacToe::releasePlayerNamesAndSymbols()
{
    this->userInterface->lineEditName1->setReadOnly(false);
    this->userInterface->lineEditName1->setEnabled(true);

    this->userInterface->lineEditName2->setReadOnly(false);
    this->userInterface->lineEditName2->setEnabled(true);

    this->userInterface->checkBoxSymbol1->setEnabled(true);
    this->userInterface->checkBoxSymbol2->setEnabled(true);
}

void CTicTacToe::resetPlayerNamesAndSymbols()
{
    this->userInterface->lineEditName1->clear();
    this->userInterface->lineEditName2->clear();
    this->userInterface->checkBoxSymbol1->setCheckState(Qt::Unchecked);
    this->userInterface->checkBoxSymbol2->setCheckState(Qt::Unchecked);
}

void CTicTacToe::toggleStartedGameField()
{
    if ( this->userInterface->lineEditName1->text().isEmpty() == true ||
         this->userInterface->lineEditName2->text().isEmpty() == true ||
         this->userInterface->checkBoxSymbol1->checkState() == Qt::Unchecked ) {
        MessageBox(NULL, L"Eines der Objekte wurde nicht ausgefüllt.", L"Error!", MB_ICONERROR);
        return;
    }


    setPlayerNamesFromUi();
    this->userInterface->textEditLog->clear();
    this->userInterface->textEditLog->append("Das Spiel kann beginnen...");
    this->userInterface->textEditLog->append("Informationen ueber SPIELER_ Nummer 1:\nSPIELER_ Name: " + getPlayerName(SPIELER_1) + "\nSPIELER_ Symbol: " + getPlayerCheckBoxStateString(SPIELER_1) + "\n");
    this->userInterface->textEditLog->append("Informationen ueber SPIELER_ Nummer 2:\nSPIELER_ Name: " + getPlayerName(SPIELER_2) + "\nSPIELER_ Symbol: " + getPlayerCheckBoxStateString(SPIELER_2)+ "\n");

    this->userInterface->pushButtonSave->setText("Spiel Beenden");


    freezePlayerNamesAndSymbols();
    resetGameFields();
    setPlayableFields(ALL_FIELDS);
    enableGameFields();
    setIsStated(true);
    setPlayerPlay(SPIELER_1);
}

void CTicTacToe::togglePausedGameField()
{
    setIsStated(false);

    disableGameFields();
    resetPlayerNamesAndSymbols();
    releasePlayerNamesAndSymbols();

    this->userInterface->textEditLog->append("Das Spiel wurde beendet.");
    this->userInterface->pushButtonSave->setText("Save && GO");
}


void CTicTacToe::setPlayerNamesFromUi()
{

    setPlayerName(SPIELER_1, this->userInterface->lineEditName1->text());
    setPlayerName(SPIELER_2, this->userInterface->lineEditName2->text());
    setPlayerCheckBoxState(SPIELER_1, this->userInterface->checkBoxSymbol1->checkState());
    setPlayerCheckBoxState(SPIELER_2, this->userInterface->checkBoxSymbol2->checkState());
}
