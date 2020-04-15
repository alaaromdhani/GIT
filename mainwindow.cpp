#include "mainwindow.h"
#include "admin.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    admin ca(ui->lineEdit->text().toInt(),ui->lineEdit_2->text());
     if(ca.authentification()){

   Dialog d;
   d.exec();
     }
     else{

          QMessageBox::warning(this, tr("ERROR"), tr("incorrect .\n"));
     }




}
