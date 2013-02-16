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

void CMainWindow::on_lineEditSymbol1_editingFinished()
{
    getMWFFInstace()->setValidSymbolLineEdit(ui->lineEditSymbol1);
}

void CMainWindow::on_lineEditSymbol2_editingFinished()
{
    getMWFFInstace()->setValidSymbolLineEdit(ui->lineEditSymbol2);
}




void CMainWindow::on_pushButtonSave_clicked()
{
    if (ticTacToeInstance.getIsStarted() == false) {
        ui->lineEditName1->setReadOnly(true);
        ui->lineEditName1->setDisabled(true);
        ui->lineEditName2->setReadOnly(true);
        ui->lineEditName2->setDisabled(true);
        ui->lineEditSymbol2->setReadOnly(true);
        ui->lineEditSymbol1->setDisabled(true);
        ui->lineEditSymbol2->setReadOnly(true);
        ui->lineEditSymbol2->setDisabled(true);
        ui->pushButtonSave->setText("Spiel Beenden");
        ticTacToeInstance.setIsStated(true);
    } else {
        ui->lineEditName1->setReadOnly(false);
        ui->lineEditName1->setDisabled(false);
        ui->lineEditName2->setReadOnly(false);
        ui->lineEditName2->setDisabled(false);
        ui->lineEditSymbol2->setReadOnly(false);
        ui->lineEditSymbol1->setDisabled(false);
        ui->lineEditSymbol2->setReadOnly(false);
        ui->lineEditSymbol2->setDisabled(false);
        ui->pushButtonSave->setText("Save && GO");
        ticTacToeInstance.setIsStated(false);
    }

}

