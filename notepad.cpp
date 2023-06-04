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
     //ui->tabWidget->addTab(new Pad(), QString("Tab %0").arg(ui->tabWidget->count() + 1));

     QToolButton *tb = new QToolButton();
     //tb->setText("+");
     tb->setIcon(QIcon(":/resources/icons/plus.png"));
     //tb->setIconSize(QSize(20, 20));
     tb->setAutoRaise(true);
     tb->setStyleSheet("QToolButton{ color: white; background-color: transparent; }");
     connect(tb, SIGNAL(clicked()), this, SLOT(addTab()));

     //ui->tabWidget->addTab(new QLabel("You can add tabs by pressing <b>\"+\"</b>"), QString());
     ui->tabWidget->setTabEnabled(0, false);
     ui->tabWidget->tabBar()->setTabButton(0, QTabBar::RightSide, tb);

}

NotePad::~NotePad()
{
    delete ui;
}

void NotePad::addTab()
{
    static int number = 0;
    QLabel *tab = new QLabel(this);
    QString tabName = QString("Tab %1").arg(++number);
    tab->setText( QString("Inside %1").arg(tabName) );
    ui->tabWidget->insertTab( ui->tabWidget->count() - 1, new Pad(), tabName);
    //ui->tabWidget->addTab(new Pad(), QString("Tab %0").arg(ui->tabWidget->count() - 1));
}

void NotePad::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

