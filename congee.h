#ifndef CONGEE_H
#define CONGEE_H



#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class congee
{
    QDate date_d,date_e;
    int cin;
public:
    congee();
    congee(int,QDate,QDate);
     bool ajouter();
    QDate getdate_d();
    QDate getdate_e();

    int getcin();

    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_cin();
    bool supprimer(int);
    bool modifier(int);


};

#endif // OUVRIER_H

