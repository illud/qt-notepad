
#include "notepad.h"
#include "ui_notepad.h"


NotePad::NotePad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotePad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
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
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

