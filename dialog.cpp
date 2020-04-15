#include "dialog.h"
#include "ouvrier.h"
#include "smtp.h"
#include "congee.h"
#include "ui_dialog.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ouvrier o;
    congee c;
     ui->comboBox->setModel(o.afficher_cin());
    ui->comboBox_2->setModel(o.afficher_cin());
    ui->comboBox_3->setModel(c.afficher_cin());
    connect(ui->pushButton_9, SIGNAL(clicked()),this, SLOT(sendMail()));
    ui->tableView->setModel(o.afficher());
 ui->tableView_2->setModel(c.afficher());
}
void Dialog::sendMail()
{
    Smtp* smtp = new Smtp(ui->lineEdit_9->text(), ui->lineEdit_10->text(), ui->lineEdit->text(), ui->lineEdit_8->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->lineEdit_9->text(), ui->lineEdit_13->text() , ui->lineEdit_11->text(),ui->lineEdit_12->text());
}
Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::verif_form(){

     return (ui->lineEdit_2->text()!="" && ui->lineEdit_3->text()!="" && ui->lineEdit_4->text()!="" && ui->lineEdit_5->text()!="" && ui->lineEdit_6->text()!="" && ui->lineEdit_7->text()!="");
}
bool Dialog::verif_formdate(){

     return (ui->dateEdit->date()<ui->dateEdit_2->date());
}


void Dialog::on_pushButton_clicked()
{
    if(verif_form()){
    int a= ui->lineEdit_2->text().toInt();
    QString b= ui->lineEdit_3->text();
    QString c= ui->lineEdit_4->text();
    QString d= ui->lineEdit_5->text();
    int e= ui->lineEdit_7->text().toInt();
    int f= ui->lineEdit_6->text().toInt();
    ouvrier o(a,b,c,d,e,f);
    if(o.ajouter()){

        QMessageBox::critical(nullptr, QObject::tr("ajout successful"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(o.afficher());

    }

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajout unsuccessful"),
                    QObject::tr("champ vide.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }

    //refresh();
}

void Dialog::on_pushButton_2_clicked()
{
    ouvrier o;
    ui->tableView->setModel(o.afficher());


}


void Dialog::on_comboBox_activated(const QString &arg1)
{
    ui->label_2->setText(arg1);
    /*int a=arg1.toInt();
    QSqlQuery q;
    q.prepare("select * from mycrud where cin = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_2->setText(q.value(0).toString());
             ui->lineEdit_3->setText(q.value(1).toString());
             ui->lineEdit_4->setText(q.value(2).toString());
             ui->lineEdit_5->setText(q.value(3).toString());
             ui->lineEdit_7->setText(q.value(4).toString());
             ui->lineEdit_6->setText(q.value(5).toString());
         }
     }*/
}


void Dialog::on_pushButton_4_clicked()
{
    int a=ui->label_2->text().toInt();
    ouvrier o;
    if(o.supprimer(a)){
        ui->tableView->setModel(o.afficher());

    }
}

void Dialog::on_pushButton_3_clicked()
{

     int a=ui->label_8->text().toInt();
     QString b= ui->lineEdit_3->text();
     QString c= ui->lineEdit_4->text();
     QString d= ui->lineEdit_5->text();
     int e= ui->lineEdit_7->text().toInt();
     int f= ui->lineEdit_6->text().toInt();
     ouvrier o(a,b,c,d,e,f);
     if(o.modifier(a)){
         ui->tableView->setModel(o.afficher());

     }
}

void Dialog::on_pushButton_5_clicked()
{
    int a= ui->label_7->text().toInt();
    QDate b= ui->dateEdit->date();
    QDate c= ui->dateEdit_2->date();

    congee con(a,b,c);
   if(verif_formdate()){
       if(con.ajouter()){

           QMessageBox::critical(nullptr, QObject::tr("ajout successful"),
                       QObject::tr("ajout successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
   }


    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajout unsuccessful"),
                    QObject::tr("verifier vos parametres .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }

}


void Dialog::on_comboBox_2_activated(const QString &arg1)
{
    ui->label_7->setText(arg1);
}

void Dialog::on_pushButton_6_clicked()
{
    congee c;
    ui->tableView_2->setModel(c.afficher());
}

/*void Dialog::on_comboBox_currentIndexChanged(int index)
{
    int a=index;
    QSqlQuery q;
    q.prepare("select * from mycrud where cin = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_2->setText(q.value(0).toString());
             ui->lineEdit_3->setText(q.value(1).toString());
             ui->lineEdit_4->setText(q.value(2).toString());
             ui->lineEdit_5->setText(q.value(3).toString());
             ui->lineEdit_7->setText(q.value(4).toString());
             ui->lineEdit_6->setText(q.value(5).toString());
         }
     }


}*/

void Dialog::on_tableView_activated(const QModelIndex &index)
{
    int a=ui->tableView->model()->data(index).toInt();
ui->label_8->setNum(a);
    QSqlQuery q;
    q.prepare("select * from mycrud where cin = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_2->setText(q.value(0).toString());
             ui->lineEdit_3->setText(q.value(1).toString());
             ui->lineEdit_4->setText(q.value(2).toString());
             ui->lineEdit_5->setText(q.value(3).toString());
             ui->lineEdit_7->setText(q.value(4).toString());
             ui->lineEdit_6->setText(q.value(5).toString());
         }
     }

}

void Dialog::on_comboBox_3_activated(const QString &arg1)
{
    ui->label_9->setText(arg1);

}
