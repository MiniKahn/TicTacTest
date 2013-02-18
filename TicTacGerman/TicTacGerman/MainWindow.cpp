#include "MainWindow.h"
#include "ui_MainWindow.h"
CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    ui->textEditLog->setReadOnly(true);
    ui->textEditLog->append("Willkommen bei TicTacToe von MiniKahn");
    getTicTacToeInstance()->startGame(ui);

}


CMainWindow::~CMainWindow()
{
    delete ui;
}


CMainWindowFormFuncs* CMainWindow::getMWFFInstace()
{
    return &mainWindowFormFuncsInstance;
}

CTicTacToe* CMainWindow::getTicTacToeInstance()
{
    return &ticTacToeInstance;
}


void CMainWindow::on_pushButtonSave_clicked()
{
    /*
     *Slot von pushButtonSave:
     *Beendet oder Startet das Spiel.
     */
    getTicTacToeInstance()->toggleGameField(ui);
}

void CMainWindow::selectedCheckBoxCheck()
{
    /*
     *Gemeinsamer Slot von checkbox_1 bis checkbox_9
     *
     *Checkt Spielfeld ob gewonnen oder unentschieden.
     */
    getTicTacToeInstance()->checkGameState(ui, QObject::sender());

}

void CMainWindow::on_checkBoxSymbol1_clicked()
{
    /*
     *Slot von checkBoxSymbol1:
     *Setzt checkBoxSymbol1 auf Hacken oder Box, niemals unchecked.
     *Setzt checkBoxSymbol2 auf das ENtgegengesetzte von checkBoxSymbol1
     *
     */
    if (ui->checkBoxSymbol1->checkState() == Qt::PartiallyChecked
            || ui->checkBoxSymbol1->checkState() == Qt::Unchecked)  {

        ui->checkBoxSymbol1->setCheckState(Qt::PartiallyChecked);
        ui->checkBoxSymbol2->setCheckState(Qt::Checked);

    } else if (ui->checkBoxSymbol1->checkState() == Qt::Checked) {

        ui->checkBoxSymbol2->setCheckState(Qt::PartiallyChecked);
    }
}

void CMainWindow::on_checkBoxSymbol2_clicked()
{
    /*
     *Slot von checkBoxSymbol2:
     *Setzt checkBoxSymbol2 auf Hacken oder Box, niemals unchecked.
     *Setzt checkBoxSymbol1 auf das Entgegengesetzte von checkBoxSymbol1
     *
     */

    if (ui->checkBoxSymbol2->checkState() == Qt::PartiallyChecked
            || ui->checkBoxSymbol2->checkState() == Qt::Unchecked) {

        ui->checkBoxSymbol2->setCheckState(Qt::PartiallyChecked);

        ui->checkBoxSymbol1->setCheckState(Qt::Checked);

    } else if (ui->checkBoxSymbol2->checkState() == Qt::Checked) {

        ui->checkBoxSymbol1->setCheckState(Qt::PartiallyChecked);

    }
}
