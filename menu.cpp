#include "menu.h"
#include "ui_menu.h"
#include "dialog.h"
#include "prod.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    Dialog d;
    d.exec();
}

void menu::on_pushButton_3_clicked()
{
    prod p;
    p.exec();
}
