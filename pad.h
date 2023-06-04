#ifndef PAD_H
#define PAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

namespace Ui {
class Pad;
}

class Pad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pad(QWidget *parent = nullptr);
    ~Pad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionPrint_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::Pad *ui;
    QString currentFile = "";
};

#endif // PAD_H
