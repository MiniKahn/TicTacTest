#include "TicTacToe.h"
CTicTacToe::CTicTacToe(QObject *parent) :
    QObject(parent)
{
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

    g_cp.mainInstance->ui->textEditLog->clear();
    g_cp.mainInstance->ui->textEditLog->append("----------- Das Spiel ist zu Ende -------------");
    if (!pDraw)
    {
        g_cp.mainInstance->ui->textEditLog->append(getPlayerName(getPlayerPlay()) + " hat gewonnen!");
    } else {
        g_cp.mainInstance->ui->textEditLog->append("Das Spiel Endet Unentschieden!");
    }
    setIsStated(false);
}

bool CTicTacToe::getIsStarted()
{
    return this->started;
}

void CTicTacToe::setIsStated(bool pIsStarted)
{
    this->started = pIsStarted;
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

    this->playerPlay = pNumber;
    g_cp.mainInstance->ui->textEditLog->append(getPlayerName(pNumber) + " ist nun am Zug. Mit Symbol: " + getPlayerCheckBoxStateString(pNumber));

}

int CTicTacToe::getPlayerPlay()
{
    return this->playerPlay;
}



void CTicTacToe::setPlayerName(int pNumber, QString pName)
{
    if (pNumber == 1)
    {
        this->playerName1 = pName;
    } else if (pNumber == 2) {
        this->playerName2 = pName;
    }
}

QString CTicTacToe::getPlayerName(int pNumber)
{
    if (pNumber == 1)
    {
        return this->playerName1;
    } else if (pNumber == 2) {
        return this->playerName2;
    }
    return "";
}

void CTicTacToe::setPlayerCheckBoxState(int pNumber, Qt::CheckState pCheckState)
{
    if (pNumber == 1)
    {
        this->playerCheckBoxState1 = pCheckState;
    } else if (pNumber == 2) {
        this->playerCheckBoxState2 = pCheckState;
    }
}

Qt::CheckState CTicTacToe::getPlayerCheckBoxState(int pNumber)
{
    if (pNumber == 1)
    {
        return this->playerCheckBoxState1;
    } else if (pNumber == 2) {
        return this->playerCheckBoxState2;
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
        if (this->playerCheckBoxState1 == Qt::PartiallyChecked)
        {
            return "Box";
        }

    } else if (pNumber == 2) {
        if (this->playerCheckBoxState2 == Qt::PartiallyChecked)
        {
            return "Box";
        }

    }
    return "Hacken";
}

void CTicTacToe::setPlayableFields(int pAnzahl)
{
    this->playableFields = pAnzahl;
}

int CTicTacToe::getPlayableFields()
{
    return this->playableFields;
}

/**
 * Check state of the active game
 *
 * @param Ui      Pointer zu ui
 * @param QObject Clicked Object (Sender von Slot )
 */
void CTicTacToe::checkGameState(QObject *sender)
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

    if (g_cp.mainInstance->ui->checkBox_1->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_2->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_3->checkState() == pCheckState) {
        return true;
    }
    if (g_cp.mainInstance->ui->checkBox_4->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_5->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_6->checkState() == pCheckState) {
        return true;
    }

    if (g_cp.mainInstance->ui->checkBox_7->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_8->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_9->checkState() == pCheckState) {
        return true;
    }

    if (g_cp.mainInstance->ui->checkBox_1->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_4->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_7->checkState() == pCheckState) {
        return true;
    }

    if (g_cp.mainInstance->ui->checkBox_2->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_5->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_8->checkState() == pCheckState) {
        return true;
    }

    if (g_cp.mainInstance->ui->checkBox_3->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_6->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_9->checkState() == pCheckState) {
        return true;
    }

    if (g_cp.mainInstance->ui->checkBox_1->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_5->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_9->checkState() == pCheckState) {
        return true;
    }

    if (g_cp.mainInstance->ui->checkBox_3->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_5->checkState() == pCheckState && g_cp.mainInstance->ui->checkBox_7->checkState() == pCheckState) {
        return true;
    }

    return false;
}



bool CTicTacToe::hasFreeFields()
{
    if (getPlayableFields() == 0)
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
    g_cp.mainInstance->ui->checkBox_1->setEnabled(false);
    g_cp.mainInstance->ui->checkBox_2->setEnabled(false);
    g_cp.mainInstance->ui->checkBox_3->setEnabled(false);
    g_cp.mainInstance->ui->checkBox_4->setEnabled(false);
    g_cp.mainInstance->ui->checkBox_5->setEnabled(false);
    g_cp.mainInstance->ui->checkBox_6->setEnabled(false);
    g_cp.mainInstance->ui->checkBox_7->setEnabled(false);
    g_cp.mainInstance->ui->checkBox_8->setEnabled(false);
    g_cp.mainInstance->ui->checkBox_9->setEnabled(false);
}

void CTicTacToe::enableGameFields()

{
    g_cp.mainInstance->ui->checkBox_1->setEnabled(true);
    g_cp.mainInstance->ui->checkBox_3->setEnabled(true);
    g_cp.mainInstance->ui->checkBox_2->setEnabled(true);
    g_cp.mainInstance->ui->checkBox_4->setEnabled(true);
    g_cp.mainInstance->ui->checkBox_5->setEnabled(true);
    g_cp.mainInstance->ui->checkBox_6->setEnabled(true);
    g_cp.mainInstance->ui->checkBox_7->setEnabled(true);
    g_cp.mainInstance->ui->checkBox_8->setEnabled(true);
    g_cp.mainInstance->ui->checkBox_9->setEnabled(true);
}


void CTicTacToe::resetGameFields()
{
    g_cp.mainInstance->ui->checkBox_1->setChecked(false);
    g_cp.mainInstance->ui->checkBox_2->setChecked(false);
    g_cp.mainInstance->ui->checkBox_3->setChecked(false),
    g_cp.mainInstance->ui->checkBox_4->setChecked(false);
    g_cp.mainInstance->ui->checkBox_5->setChecked(false);
    g_cp.mainInstance->ui->checkBox_6->setChecked(false);
    g_cp.mainInstance->ui->checkBox_7->setChecked(false);
    g_cp.mainInstance->ui->checkBox_8->setChecked(false);
    g_cp.mainInstance->ui->checkBox_9->setChecked(false);
}

void CTicTacToe::freezePlayerNamesAndSymbols()
{
    g_cp.optionsInstance->ui->lineEditName1->setReadOnly(true);
    g_cp.optionsInstance->ui->lineEditName1->setEnabled(false);

    g_cp.optionsInstance->ui->lineEditName2->setReadOnly(true);
    g_cp.optionsInstance->ui->lineEditName2->setEnabled(false);

    g_cp.optionsInstance->ui->checkBoxSymbol1->setEnabled(false);
    g_cp.optionsInstance->ui->checkBoxSymbol2->setEnabled(false);
}

void CTicTacToe::releasePlayerNamesAndSymbols()
{
    g_cp.optionsInstance->ui->lineEditName1->setReadOnly(false);
    g_cp.optionsInstance->ui->lineEditName1->setEnabled(true);

    g_cp.optionsInstance->ui->lineEditName2->setReadOnly(false);
    g_cp.optionsInstance->ui->lineEditName2->setEnabled(true);

    g_cp.optionsInstance->ui->checkBoxSymbol1->setEnabled(true);
    g_cp.optionsInstance->ui->checkBoxSymbol2->setEnabled(true);
}

void CTicTacToe::resetPlayerNamesAndSymbols()
{
    g_cp.optionsInstance->ui->lineEditName1->clear();
    g_cp.optionsInstance->ui->lineEditName2->clear();
    g_cp.optionsInstance->ui->checkBoxSymbol1->setCheckState(Qt::Unchecked);
    g_cp.optionsInstance->ui->checkBoxSymbol2->setCheckState(Qt::Unchecked);
}

bool CTicTacToe::checkAllFieldsFilled()
{
    if ( g_cp.optionsInstance->ui->lineEditName1->text().isEmpty() == true ||
         g_cp.optionsInstance->ui->lineEditName2->text().isEmpty() == true ||
         g_cp.optionsInstance->ui->checkBoxSymbol1->checkState() == Qt::Unchecked ) {
        return false;
    }
    return true;
}

void CTicTacToe::toggleStartedGameField()
{
    if(checkAllFieldsFilled() == false)
    {
        MessageBox(NULL, L"Eines der Objekte wurde nicht ausgefüllt.", L"Error!", MB_ICONERROR);
        return;
    }

    setPlayerNamesFromUi();
    g_cp.mainInstance->ui->textEditLog->clear();
    g_cp.mainInstance->ui->textEditLog->append("Das Spiel kann beginnen...");
    g_cp.mainInstance->ui->textEditLog->append("Informationen ueber Spieler Nummer 1:\nName: " + getPlayerName(SPIELER_1) + "\nSymbol: " + getPlayerCheckBoxStateString(SPIELER_1) + "\n");
    g_cp.mainInstance->ui->textEditLog->append("Informationen ueber Spieler Nummer 2:\nName: " + getPlayerName(SPIELER_2) + "\nSymbol: " + getPlayerCheckBoxStateString(SPIELER_2)+ "\n");

    g_cp.mainInstance->ui->pushButtonSave->setText("Spiel Beenden");


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
   // resetPlayerNamesAndSymbols();
    releasePlayerNamesAndSymbols();

    g_cp.mainInstance->ui->textEditLog->append("Das Spiel wurde beendet.");
    g_cp.mainInstance->ui->pushButtonSave->setText("Spiel starten");
}


void CTicTacToe::setPlayerNamesFromUi()
{

    setPlayerName(SPIELER_1, g_cp.optionsInstance->ui->lineEditName1->text());
    setPlayerName(SPIELER_2, g_cp.optionsInstance->ui->lineEditName2->text());
    setPlayerCheckBoxState(SPIELER_1, g_cp.optionsInstance->ui->checkBoxSymbol1->checkState());
    setPlayerCheckBoxState(SPIELER_2, g_cp.optionsInstance->ui->checkBoxSymbol2->checkState());
}
