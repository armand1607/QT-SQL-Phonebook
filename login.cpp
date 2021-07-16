#include "login.h"
#include "mainwindow.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextEdit>
#include <mainwindow.h>

int count = 0;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap bg("G:/QT6DB/Images/background.png");
    QPixmap disconnected("G:/QT6DB/Images/deconectat.png");


        ui->label_6->setPixmap(bg);
        ui->buton->setPixmap(disconnected);

        this->setWindowTitle("MySQL Login App by Francovschi Armand");
        this->setFixedSize(QSize(800, 600));

    myDb = QSqlDatabase::addDatabase("QMYSQL");
    myDb.setHostName("127.0.0.1");
    myDb.setUserName("root");
    myDb.setPassword("");
    myDb.setDatabaseName("agenda_telefon");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username = ui->user->text();
    QString password = ui->parola->text();
    myDb.open();
    QSqlQuery qry;
    if(!myDb.open())
        QMessageBox::warning(this, "Deconectat", "Nu s-a putut realiza conexiunea la baza de date");
    if(qry.exec("select * from conturi where username='"+username+"' and password='"+password+"'"))
    {
        while(qry.next())
           {
            count++;
        }
        if(count==1)
{

       QPixmap connected("G:/QT6DB/Images/conectat.png");
           ui->buton->setPixmap(connected);
           ui->pushButton->setDisabled(true);
           ui->pushButton->repaint();
    }
    else
        QMessageBox::warning(this, "Eroare!", "Nume sau parola gresite!");
}
}



void Login::on_pushButton_2_clicked()
{
 if(count ==1){

     QMessageBox::information(this, "Bun venit!", "Bun venit la agenda dumneavoastra!");
     mainWindow = new MainWindow(this);
     mainWindow->show();
     this->hide();
 }
     else {
         QMessageBox::warning(this,"Deconectat!", "Trebuie mai intai sa va autentificati pentru a putea accesa baza de date!");
     }
}

