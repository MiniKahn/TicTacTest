#include "options.h"
#include "ui_options.h"
#include "MainWindow.h"
Options::Options(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);

}

Options::~Options()
{
    delete ui;

}


void Options::on_saveClose_clicked()
{
    if(g_cp.ticTacToeInstance->checkAllFieldsFilled() == false)
    {
        MessageBox(NULL, L"Eines der Objekte wurde nicht ausgefüllt.", L"Error!", MB_ICONERROR);
        return;
    }
    writeSettings();
}

bool Options::writeSettings()
{

    g_cp.mainInstance->debug(g_INI_Path);

    QSettings setting(g_INI_Path ,QSettings::IniFormat);
    setting.beginGroup("Usernames");
    setting.setValue("Name1", ui->lineEditName1->text());
    setting.setValue("Name2", ui->lineEditName2->text());
    setting.endGroup();

    setting.beginGroup("Checkboxes");
    setting.setValue("Checkbox1", ui->checkBoxSymbol1->checkState());
    setting.setValue("Checkbox2", ui->checkBoxSymbol2->checkState());
    setting.endGroup();
    return true;
}

bool Options::getSettings()
{
    QSettings setting(g_INI_Path ,QSettings::IniFormat);
    setting.beginGroup("Usernames");
    ui->lineEditName1->setText(setting.value("Name1").toString());
    ui->lineEditName2->setText(setting.value("Name2").toString());
    setting.endGroup();

    setting.beginGroup("Checkboxes");
    ui->checkBoxSymbol1->setCheckState(static_cast<Qt::CheckState>(setting.value("Checkbox1").toInt()));
    ui->checkBoxSymbol2->setCheckState(static_cast<Qt::CheckState>(setting.value("Checkbox2").toInt()));
    setting.endGroup();
    return true;
}

void Options::on_checkBoxSymbol1_clicked()
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

void Options::on_checkBoxSymbol2_clicked()
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
