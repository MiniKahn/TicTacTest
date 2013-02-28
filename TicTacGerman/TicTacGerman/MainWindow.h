#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

#include "stdafx.h"

#include "TicTacToe.h"
#include "options.h"

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
    void debug(QString text);
    void debug(int zahl);
    Ui::CMainWindow *ui;
protected:
    void closeEvent( QCloseEvent *event );
signals:
private slots:

    void on_pushButtonSave_clicked();

    void selectedCheckBoxCheck();
    void on_actionOeffneOptionen_triggered();

private:
    void initIniPath();

};
extern QString g_INI_Path;

struct classpointer {
    CMainWindow *mainInstance;
    CTicTacToe *ticTacToeInstance;
    Options *optionsInstance;

};
extern classpointer g_cp;
#endif // MAINWINDOW_H
