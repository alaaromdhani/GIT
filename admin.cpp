#include "admin.h"
#include <QDebug>
admin::admin()
{

}
admin::admin(int id,QString mot_de_passe){
this->id=id;
this->mot_de_passe=mot_de_passe;
}
bool admin::authentification(){
    QSqlQuery query;
    QString test_id,test_mot_de_passe;
    query.prepare("select * from admin where (id=:id) and(password=:mot_de_passe)");
    query.bindValue(":id",id);
    query.bindValue(":mot_de_passe",mot_de_passe);
    query.exec();
    while(query.next()){
        test_id=query.value(0).toString();
    test_mot_de_passe=query.value(1).toString();
    }
    return (((test_id!="")&&(test_mot_de_passe!="")));
}

