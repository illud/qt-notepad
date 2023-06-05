
#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QToolButton>
#include <QLabel>
#include <QTabBar>
#include <QGraphicsBlurEffect>
#include "pad.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NotePad; }
QT_END_NAMESPACE

class NotePad : public QMainWindow

{
    Q_OBJECT

public:
    NotePad(QWidget *parent = nullptr);
    ~NotePad();

private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void addTab();

private:
    Ui::NotePad *ui;
    QString currentFile = "";
};

#endif // NOTEPAD_H
