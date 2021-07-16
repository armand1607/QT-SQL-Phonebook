#include "edit_numar.h"
#include "ui_edit_numar.h"

int qryy = 0;
edit_numar::edit_numar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_numar)
{
    ui->setupUi(this);
    QPixmap background2("G:/QT6DB/Images/background.png");
      ui->label_4->setPixmap(background2);
}


edit_numar::~edit_numar()
{
    delete ui;
}

void edit_numar::on_pushButton_clicked()
{
    {       db2 = QSqlDatabase::addDatabase("QMYSQL");
            db2.setHostName("127.0.0.1");
            db2.setUserName("root");
            db2.setPassword("");
            db2.setDatabaseName("agenda_telefon");
        db2.open();
        QString nume, numar_nou;
        nume=ui->lineEdit->text();
        numar_nou=ui->lineEdit_2->text();

        QSqlQuery qry;
        qry.prepare("update contacte set Numar='"+numar_nou+"' where Nume='"+nume+"'");


        if(qry.exec())
          {
             QMessageBox::information(this,tr("Editat cu succes!"),tr("Contactul a fost editat cu succes! "));
              this->hide();
            qryy = 1;

          }
        else
        {
            QMessageBox::critical(this,tr("Editare esuata!"),qry.lastError().text());
        }
        if( qryy == 1)
        this->hide();

    }
}


void edit_numar::on_pushButton_2_clicked()
{
     this->hide();
}

