#include "congee.h"



congee::congee()
{
cin=0;

}
congee::congee(int a,QDate d,QDate e)
{
cin=a;
date_d=d;
date_e=e;


}
int congee::getcin(){

    return cin;
}
QDate congee::getdate_d(){

return date_d;
}
QDate congee::getdate_e(){

    return date_e;
}
bool congee::ajouter(){

    QSqlQuery query;
    query.prepare("insert into conges values(?,?,?,id.nextval);");
    query.addBindValue(cin);
    query.addBindValue(date_d);
    query.addBindValue(date_e);


   return query.exec();
}
QSqlQueryModel * congee::afficher(){

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from conges;");
   return model;



}
bool congee::supprimer(int a){

    QSqlQuery query;
    query.prepare("delete from conges where id = ?");
    query.addBindValue(a);


   return query.exec();

}
QSqlQueryModel * congee::afficher_cin(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id from conges;" );

    return  model;

}




