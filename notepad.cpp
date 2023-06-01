
#include "notepad.h"
#include "ui_notepad.h"


NotePad::NotePad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotePad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    ui->menubar->setStyleSheet("QMenuBar::item:selected { background: #474747; } QMenuBar::item:pressed {  background: #474747; }");
}

NotePad::~NotePad()
{
    delete ui;
}



void NotePad::on_actionNew_triggered()
{
    currentFile .clear();
    ui->textEdit->setText(QString());
}


void NotePad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void NotePad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void NotePad::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Print Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Access printer");
        return;
    }
    ui->textEdit->print(&printer);
}


void NotePad::on_actionExit_triggered()
{
    QApplication::quit();
}


void NotePad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void NotePad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void NotePad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void NotePad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void NotePad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

