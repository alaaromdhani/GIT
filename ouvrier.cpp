#include "ouvrier.h"

ouvrier::ouvrier()
{
cin=0;
numtel=0;
salaire=0;
}
ouvrier::ouvrier(int a,QString d,QString e,QString f,int b,int c)
{
cin=a;
numtel=b;
salaire=c;
nom=d;
prenom=e;
email=f;

}
int ouvrier::getcin(){

    return cin;
}
QString ouvrier::getnom(){

    return nom;
}
QString ouvrier::getprenom(){

    return prenom;
}
QString ouvrier::getemail(){

    return email;
}
int ouvrier::getnumtel(){

    return numtel;
}
int ouvrier::getsalaire(){

    return salaire;
}
bool ouvrier::ajouter(){

    QSqlQuery query;
    query.prepare("insert into mycrud values(?,?,?,?,?,?);");
    query.addBindValue(cin);
    query.addBindValue(nom);
    query.addBindValue(prenom);
     query.addBindValue(email);
     query.addBindValue(numtel);
     query.addBindValue(salaire);

   return query.exec();
}
QSqlQueryModel * ouvrier::afficher(){

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from mycrud;");
   return model;



}
bool ouvrier::supprimer(int a){

    QSqlQuery query;
    query.prepare("delete from mycrud where cin = ?");
    query.addBindValue(a);


   return query.exec();

}
bool ouvrier::modifier(int a){


    QSqlQuery query;
    query.prepare("update mycrud set nom = ? , prenom = ? , email = ? , numtel = ? , salaire = ? where cin = ?");

    query.addBindValue(nom);
    query.addBindValue(prenom);
     query.addBindValue(email);
     query.addBindValue(numtel);
     query.addBindValue(salaire);

   query.addBindValue(a);


   return query.exec();

}
QSqlQueryModel * ouvrier::afficher_cin(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select cin from mycrud;" );

    return  model;

}


