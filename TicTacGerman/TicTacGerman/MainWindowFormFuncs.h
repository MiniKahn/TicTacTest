#ifndef MAINWINDOWFORMFUNCS_H
#define MAINWINDOWFORMFUNCS_H

#include <QObject>
#include <QLineEdit>
#include "stdafx.h"
class CMainWindowFormFuncs : public QObject
{
    Q_OBJECT
public:
    explicit CMainWindowFormFuncs(QObject *parent = 0);
    QString setValidSymbolLineEdit(QLineEdit *lineEdit);
signals:
    
public slots:
    
};

#endif // MAINWINDOWFORMFUNCS_H
