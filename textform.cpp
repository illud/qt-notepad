#include "textform.h"
#include "ui_textform.h"

textForm::textForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::textForm)
{
    ui->setupUi(this);
    //this->setCentralWidget(ui->textEdit);
}

textForm::~textForm()
{
    delete ui;
}
