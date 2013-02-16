#include "MainWindow.h"
#include "ui_MainWindow.h"
CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    ui->textEditLog->setReadOnly(true);
    ui->textEditLog->append("TEST!");
    ui->textEditLog->append("TEST!");
    ui->textEditLog->append("TEST!");
    ui->textEditLog->append("TEST!");

    getTicTacToeInstance()->startGame();
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
/*
void CMainWindow::on_lineEditSymbol1_editingFinished()
{
    getMWFFInstace()->setValidSymbolLineEdit(ui->lineEditSymbol1);
}

void CMainWindow::on_lineEditSymbol2_editingFinished()
{
    getMWFFInstace()->setValidSymbolLineEdit(ui->lineEditSymbol2);
}
*/




void CMainWindow::on_pushButtonSave_clicked()
{
    if (ticTacToeInstance.getIsStarted() == false) {
        if ( ui->lineEditName1->text().isEmpty() == true ||
             ui->lineEditName2->text().isEmpty() == true ||
             ui->checkBoxSymbol1->checkState() == Qt::Unchecked == true) {
            MessageBox(NULL, L"Eines der Objekte wurde nicht ausgefüllt.", L"Error!", MB_ICONERROR);
            return;
        }

            ui->lineEditName1->setReadOnly(true);
            ui->lineEditName1->setDisabled(true);

            ui->lineEditName2->setReadOnly(true);
            ui->lineEditName2->setDisabled(true);

            ui->checkBoxSymbol1->setDisabled(true);
            ui->checkBoxSymbol2->setDisabled(true);

            getTicTacToeInstance()->setIsStated(true);
            ui->pushButtonSave->setText("Spiel Beenden");
            ui->textEditLog->clear();
            ui->textEditLog->append("Das Spiel kann beginnen...");


            getTicTacToeInstance()->setPlayerName(1,ui->lineEditName1->text());
            getTicTacToeInstance()->setPlayerName(2,ui->lineEditName2->text());
            getTicTacToeInstance()->setPlayerCheckBoxState(1,ui->checkBoxSymbol1->checkState());
            getTicTacToeInstance()->setPlayerCheckBoxState(2,ui->checkBoxSymbol2->checkState());

            ui->textEditLog->append("Informationen ueber Spieler Nummer 1:\nSpieler Name: " + getTicTacToeInstance()->getPlayerName(1) + "\nSpieler Symbol: " + getTicTacToeInstance()->getPlayerCheckBoxStateString(1) + "\n");
            ui->textEditLog->append("Informationen ueber Spieler Nummer 2:\nSpieler Name: " + getTicTacToeInstance()->getPlayerName(2) + "\nSpieler Symbol: " + getTicTacToeInstance()->getPlayerCheckBoxStateString(2)+ "\n");

            getTicTacToeInstance()->setPlayerPlay(1, ui);
    } else {

        ui->lineEditName1->setReadOnly(false);
        ui->lineEditName1->setDisabled(false);

        ui->lineEditName2->setReadOnly(false);
        ui->lineEditName2->setDisabled(false);

        ui->checkBoxSymbol1->setDisabled(false);
        ui->checkBoxSymbol2->setDisabled(false);

        getTicTacToeInstance()->setIsStated(false);
        ui->pushButtonSave->setText("Save && GO");
        ui->textEditLog->append("Das Spiel wurde beendet.");

        ui->lineEditName1->clear();
        ui->lineEditName2->clear();
        ui->checkBoxSymbol1->setCheckState(Qt::Unchecked);
        ui->checkBoxSymbol2->setCheckState(Qt::Unchecked);
    }

}

void CMainWindow::selectedCheckBoxCheck()
{
    MessageBox(NULL,L"a", L"b", NULL);
    QMessageBox mb;
    mb.setText( QObject::sender()->objectName());
    mb.exec();
}

void CMainWindow::on_checkBoxSymbol1_clicked()
{
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
    if (ui->checkBoxSymbol2->checkState() == Qt::PartiallyChecked
            || ui->checkBoxSymbol2->checkState() == Qt::Unchecked) {

        ui->checkBoxSymbol2->setCheckState(Qt::PartiallyChecked);

        ui->checkBoxSymbol1->setCheckState(Qt::Checked);

    } else if (ui->checkBoxSymbol2->checkState() == Qt::Checked) {

        ui->checkBoxSymbol1->setCheckState(Qt::PartiallyChecked);

    }
}
