#include "pad.h"
#include "ui_pad.h"

Pad::Pad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    ui->menubar->setStyleSheet("QMenuBar::item:selected { background: #474747; } QMenuBar::item:pressed {  background: #474747; } QMenuBar {color: #ffffff;}");
    ui->textEdit->setFocus();
}

Pad::~Pad()
{
    delete ui;
}

void WarningMessageBox(QString msg, QString error){
    QMessageBox m_MsgBox;
    //m_MsgBox.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    m_MsgBox.setIcon(QMessageBox::Warning);
    m_MsgBox.setText(msg + error);
    m_MsgBox.setStandardButtons(QMessageBox::Ok);
    m_MsgBox.setStyleSheet("QLabel{font-size: 13px; color: #ffffff;} QPushButton{ width:25px; font-size: 13px; background-color: #424242; color: #ffffff; } QMessageBox{background-color: #383838;}");
    if(m_MsgBox.exec() == QMessageBox::Ok)
        m_MsgBox.close();
}

void Pad::on_actionNew_triggered()
{
    currentFile .clear();
    ui->textEdit->setText(QString());
}


void Pad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        WarningMessageBox("Cannot open file: ", file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void Pad::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Print Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        WarningMessageBox("Cannot Access printer.", "");
        return;
    }
    ui->textEdit->print(&printer);
}


void Pad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        WarningMessageBox("Cannot save file: ", file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void Pad::on_actionExit_triggered()
{
    QApplication::quit();
}


void Pad::on_actionCopy_triggered()
{
     ui->textEdit->copy();
}


void Pad::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}


void Pad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Pad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void Pad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

