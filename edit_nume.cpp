#include "edit_nume.h"
#include "ui_edit_nume.h"
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>

edit_nume::edit_nume(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_nume)
{
    ui->setupUi(this);
    QPixmap background2("G:/QT6DB/Images/background.png");
      ui->label_4->setPixmap(background2);
}

edit_nume::~edit_nume()
{
    delete ui;
}

void edit_nume::on_pushButton_clicked()
{       db2 = QSqlDatabase::addDatabase("QMYSQL");
        db2.setHostName("127.0.0.1");
        db2.setUserName("root");
        db2.setPassword("");
        db2.setDatabaseName("agenda_telefon");
    db2.open();
    QString nume_vechi, nume_nou;
    nume_vechi=ui->lineEdit->text();
    nume_nou=ui->lineEdit_2->text();

    QSqlQuery qry;
    qry.prepare("update contacte set Nume='"+nume_nou+"' where Nume='"+nume_vechi+"'");


    if(qry.exec())
      {
         QMessageBox::information(this,tr("Stocare cu succes!"),tr("Contactul a fost stocat cu succes! "));
          this->hide();

      }
    else
    {
        QMessageBox::critical(this,tr("Stocare esuata!"),qry.lastError().text());
    }
}

void edit_nume::on_pushButton_2_clicked()
{
    this->hide();
}

