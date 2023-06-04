#include "notepad.h"
#include "ui_notepad.h"

NotePad::NotePad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotePad)
{
    ui->setupUi(this);
    //this->setCentralWidget(ui->textEdit);
    this->setCentralWidget(ui->tabWidget);
     ui->menubar->setStyleSheet("QMenuBar::item:selected { background: #474747; } QMenuBar::item:pressed {  background: #474747; }");

     // Create new tab on form load
     ui->tabWidget->addTab(new Pad(), QString("Tab %0").arg(ui->tabWidget->count() + 1));
}

NotePad::~NotePad()
{
    delete ui;
}

void NotePad::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}


void NotePad::on_actionNew_Tab_triggered()
{
    ui->tabWidget->addTab(new Pad(), QString("Tab %0").arg(ui->tabWidget->count() + 1));
}

