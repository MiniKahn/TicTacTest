#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ui_options.h"

QString g_INI_Path;
classpointer g_cp;
CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMainWindow)
{
    initIniPath();
    ui->setupUi(this);
    ui->textEditLog->setReadOnly(true);
    ui->textEditLog->append("Willkommen bei TicTacToe von MiniKahn");

    g_cp.mainInstance = this;
    g_cp.optionsInstance = new Options();
    g_cp.ticTacToeInstance = new CTicTacToe();

    g_cp.optionsInstance->getSettings();
   // g_cp.optionsInstance->show();
    g_cp.ticTacToeInstance->startGame();

    debug("");
}

void CMainWindow::on_actionOeffneOptionen_triggered()
{
    //g_cp.optionsInstance = new Options();
    g_cp.optionsInstance->show();
}

void CMainWindow::initIniPath()
{
    QSettings settings(QSettings::UserScope, "Microsoft", "Windows");
    settings.beginGroup("CurrentVersion/Explorer/Shell Folders");
    g_INI_Path = settings.value("Personal").toString() + "\\tictactoe.ini";
}

CMainWindow::~CMainWindow()
{
    delete g_cp.optionsInstance;
    delete g_cp.ticTacToeInstance;
    delete ui;
}

void CMainWindow::debug(QString text)
{
    qDebug() << text;
}

void CMainWindow::debug(int zahl)
{
    qDebug() << zahl;
}

void CMainWindow::closeEvent( QCloseEvent *event ) {
    // Damit die Anwendung schließt muß das Event akzeptiert werden
    //  MessageBox(NULL, L"ÄH NÖ?", L"NE!", NULL);

    event->accept();
    qApp->quit();
   // event->ignore();
}

CTicTacToe* CMainWindow::getTicTacToeInstance()
{
    return g_cp.ticTacToeInstance;
}

void CMainWindow::setTicTacToeInstance(CTicTacToe *instance)
{
    /**
     * @unused:
     */
    g_cp.ticTacToeInstance = instance;
}

void CMainWindow::on_pushButtonSave_clicked()
{
    /*
     *Slot von pushButtonSave:
     *Beendet oder Startet das Spiel.
     */
    getTicTacToeInstance()->toggleGameField();
}

void CMainWindow::selectedCheckBoxCheck()
{
    /*
     *Gemeinsamer Slot von checkbox_1 bis checkbox_9
     *
     *Checkt Spielfeld ob gewonnen oder unentschieden.
     */
    getTicTacToeInstance()->checkGameState( QObject::sender());

}
/*
void CMainWindow::on_checkBoxSymbol1_clicked()
{
    /*
     *Slot von checkBoxSymbol1:
     *Setzt checkBoxSymbol1 auf Hacken oder Box, niemals unchecked.
     *Setzt checkBoxSymbol2 auf das ENtgegengesetzte von checkBoxSymbol1
     *
     */ /*
    if (ui->checkBoxSymbol1->checkState() == Qt::PartiallyChecked
            || ui->checkBoxSymbol1->checkState() == Qt::Unchecked)  {

        ui->checkBoxSymbol1->setCheckState(Qt::PartiallyChecked);
        options->ui->checkBoxSymbol2->setCheckState(Qt::Checked);

    } else if (ui->checkBoxSymbol1->checkState() == Qt::Checked) {

        options->ui->checkBoxSymbol2->setCheckState(Qt::PartiallyChecked);
    }
}
/*
void CMainWindow::on_checkBoxSymbol2_clicked()
{
    /*
     *Slot von checkBoxSymbol2:
     *Setzt checkBoxSymbol2 auf Hacken oder Box, niemals unchecked.
     *Setzt checkBoxSymbol1 auf das Entgegengesetzte von checkBoxSymbol1
     *
     */ /*

    if (ui->checkBoxSymbol2->checkState() == Qt::PartiallyChecked
            || ui->checkBoxSymbol2->checkState() == Qt::Unchecked) {

        ui->checkBoxSymbol2->setCheckState(Qt::PartiallyChecked);

        ui->checkBoxSymbol1->setCheckState(Qt::Checked);

    } else if (ui->checkBoxSymbol2->checkState() == Qt::Checked) {

        ui->checkBoxSymbol1->setCheckState(Qt::PartiallyChecked);

    }
} */

