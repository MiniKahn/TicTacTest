#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLineEdit>
#include "TicTacToe.h"
#include "stdafx.h"

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
    CTicTacToe* getTicTacToeInstance();
    void setTicTacToeInstance(CTicTacToe *ticTacToeInstance);

private slots:

    void on_pushButtonSave_clicked();

    void selectedCheckBoxCheck();

    void on_checkBoxSymbol1_clicked();

    void on_checkBoxSymbol2_clicked();
private:
    Ui::CMainWindow *ui;

    CTicTacToe *ticTacToeInstance;
};

#endif // MAINWINDOW_H
