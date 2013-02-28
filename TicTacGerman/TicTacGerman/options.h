#ifndef OPTIONS_H
#define OPTIONS_H

#include <QMainWindow>
namespace Ui {
class Options;
}

class CMainWindow;
class CTicTacToe;
class Options : public QMainWindow
{
    Q_OBJECT

    
public:
    explicit Options(QWidget *parent = 0);
    ~Options();
    Ui::Options *ui;

    bool writeSettings();
    bool getSettings();
    
private slots:
    void on_saveClose_clicked();
    void on_checkBoxSymbol1_clicked();
    void on_checkBoxSymbol2_clicked();
private:
    CMainWindow *main;
    CTicTacToe *tictactoe;
};

#endif // OPTIONS_H
