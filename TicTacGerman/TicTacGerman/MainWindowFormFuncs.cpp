#include "MainWindowFormFuncs.h"

CMainWindowFormFuncs::CMainWindowFormFuncs(QObject *parent) :
    QObject(parent)
{
}

/*
QString CMainWindowFormFuncs::setValidSymbolLineEdit(QLineEdit *lineEdit)
{

    QString text = lineEdit->text();
    int length = text.length();
    wchar_t txt[32];
    _itow_s(length, txt, 10);
    if (length > 1)
    {
        MessageBox(NULL, txt, L"Test", NULL);
        text.remove(1,text.length()-1);
        lineEdit->setText(text);
    }
    return text;
}
*/
