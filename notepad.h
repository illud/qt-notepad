
#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>

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
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

private:
    Ui::NotePad *ui;
    QString currentFile = "";
};

#endif // NOTEPAD_H
