#include "prod.h"
#include <QMessageBox>
#include "ui_prod.h"
#include "produitph.h"
#include "produitch.h"
prod::prod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prod)
{
    ui->setupUi(this);
    physique c;
     ui->comboBox->setModel(c.afficher_id());
      ui->label_3->setNum(ui->comboBox->currentText().toInt());
      chimie o;
       ui->comboBox_2->setModel(o.afficher_id());
        ui->label_5->setNum(ui->comboBox_2->currentText().toInt());
        physique p;

        ui->tableView->setModel(p.afficher());
        ui->tableView_2->setModel(c.afficher());

}

prod::~prod()
{
    delete ui;
}

void prod::on_pushButton_4_clicked()
{
    physique p;

    ui->tableView->setModel(p.afficher());
}

void prod::on_pushButton_clicked()
{ if(!verifform1()){
        QMessageBox::critical(nullptr,QObject::tr("ajout unsuccessful"),QObject::tr("verifier vos parametres.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{

        int id_phy =ui->lineEdit_2->text().toInt();
        QString nom=ui->lineEdit_3->text();
        QString marque=ui->lineEdit_4->text();
        QString prix =ui->lineEdit_5->text();
       QString dispo;
        if(ui->radioButton->isChecked()){
           dispo="disponible";
        }
        else{
           dispo="nondisponible";
        }





        physique f(id_phy,nom,marque,prix,dispo);
        bool test=f.ajouter();
        if(test)
        {ui->tableView->setModel(f.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajouter un physique"),QObject::tr("physique ajouter.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->radioButton->clearMask();
        ui->radioButton_2->clearMask();
        refresh();
    }


}
bool prod::verifform1(){

   if(ui->lineEdit_2->text()!="" && ui->lineEdit_3->text()!="" && ui->lineEdit_4->text()!="" && ui->lineEdit_5->text()!="" && ui->radioButton->isChecked() && !ui->radioButton_2->isChecked())
   {
       return true;
   }
   if(ui->lineEdit_2->text()!="" && ui->lineEdit_3->text()!="" && ui->lineEdit_4->text()!="" && ui->lineEdit_5->text()!="" && !ui->radioButton->isChecked() && ui->radioButton_2->isChecked())
   {
       return true;
   }
   return false;

}

void prod::on_comboBox_activated(const QString &arg1)
{
ui->label_3->setNum(arg1.toInt());
}

void prod::on_pushButton_2_clicked()
{
    int a=ui->label_3->text().toInt();
    physique o;
    if(o.supprimer(a)){
        ui->tableView->setModel(o.afficher());

    }
    refresh();
}
void prod::refresh(){
    physique o;
    chimie c;
     ui->comboBox->setModel(o.afficher_id());
ui->comboBox_2->setModel(c.afficher_id());
    ui->tableView_2->setModel(c.afficher());
 //ui->tableView_2->setModel(c.afficher());
 ui->label_3->setNum(ui->comboBox->currentText().toInt());
 ui->label_5->setNum(ui->comboBox_2->currentText().toInt());


  }

void prod::on_tableView_activated(const QModelIndex &index)
{
    int a=ui->tableView->model()->data(index).toInt();
ui->label_4->setNum(a);
    QSqlQuery q;
    q.prepare("select * from physique where id_phy = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_2->setText(q.value(0).toString());
             ui->lineEdit_3->setText(q.value(1).toString());
             ui->lineEdit_4->setText(q.value(2).toString());
             ui->lineEdit_5->setText(q.value(3).toString());
             if(q.value(4).toString()=="disponible"){
                 ui->radioButton->setChecked(true);
                 ui->radioButton_2->setChecked(false);
             }
             else
             {
                 ui->radioButton->setChecked(false);
                 ui->radioButton_2->setChecked(true);

             }


         }
     }
     refresh();
}

void prod::on_pushButton_3_clicked()
{
    int a=ui->label_4->text().toInt();

    QString b= ui->lineEdit_3->text();
    QString c= ui->lineEdit_4->text();
    QString d= ui->lineEdit_5->text();
    QString e;
    if(ui->radioButton->isChecked()){
       e="disponible";
    }
    else{
       e="nondisponible";
    }

    physique o(a,b,c,d,e);
    if(o.modifier(a)){
        ui->tableView->setModel(o.afficher());
        refresh();

    }

}

void prod::on_pushButton_5_clicked()
{
    QString nom =ui->lineEdit_6->text();
    QString marque= ui->lineEdit_7->text();
    int id_ch =ui->lineEdit_8->text().toInt();
    QString prix =ui->lineEdit_9->text();
    QString quantit =ui->lineEdit_10->text();


    chimie c(nom,marque,id_ch,prix,quantit);
    bool test=c.ajouter();
    if(test)
    {ui->tableView_2->setModel(c.afficher());
    QMessageBox::information(nullptr,QObject::tr("Ajouter un chimie"),QObject::tr("chimie ajouter.\n"
                                                                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    refresh();
}

void prod::on_pushButton_6_clicked()
{
    physique p;

    ui->tableView->setModel(p.afficher());

}

void prod::on_comboBox_2_activated(const QString &arg1)
{
    ui->label_5->setNum(arg1.toInt());
}

void prod::on_pushButton_8_clicked()
{
    int a=ui->label_5->text().toInt();
    chimie o;
    if(o.supprimer(a)){
        ui->tableView_2->setModel(o.afficher());

    }
    refresh();

}

void prod::on_tableView_2_activated(const QModelIndex &index)
{
    int a=ui->tableView_2->model()->data(index).toInt();
ui->label_6->setNum(a);
    QSqlQuery q;
    q.prepare("select * from chimie where id_ch = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->lineEdit_6->setText(q.value(0).toString());
             ui->lineEdit_7->setText(q.value(1).toString());
             ui->lineEdit_8->setText(q.value(2).toString());
             ui->lineEdit_9->setText(q.value(3).toString());
              ui->lineEdit_10->setText(q.value(4).toString());



         }
     }
     refresh();

}

void prod::on_pushButton_7_clicked()
{
    int a=ui->label_6->text().toInt();

    QString b= ui->lineEdit_6->text();
    QString c= ui->lineEdit_7->text();
    QString d= ui->lineEdit_9->text();
    QString e=ui->lineEdit_10->text();


    chimie o(b,c,a,d,e);
    if(o.modifier(a)){
        ui->tableView_2->setModel(o.afficher());
        refresh();

    }

}
