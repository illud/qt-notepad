#ifndef TEXTFORM_H
#define TEXTFORM_H

#include <QWidget>

namespace Ui {
class textForm;
}

class textForm : public QWidget
{
    Q_OBJECT

public:
    explicit textForm(QWidget *parent = nullptr);
    ~textForm();

private:
    Ui::textForm *ui;
};

#endif // TEXTFORM_H
