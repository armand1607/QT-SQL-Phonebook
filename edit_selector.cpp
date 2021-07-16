#include "edit_selector.h"
#include "ui_edit_selector.h"
#include "edit_numar.h"
#include "edit_nume.h"
#include <QPixmap>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>

Edit_Selector::Edit_Selector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Selector)

{
    ui->setupUi(this);
    this->setWindowTitle("Editarea unui contact");
    QPixmap background2("G:/QT6DB/Images/background.png");
      ui->background2->setPixmap(background2);
}

Edit_Selector::~Edit_Selector()
{
    delete ui;
}

void Edit_Selector::on_pushButton_5_clicked()
{
     this->hide();
}


void Edit_Selector::on_pushButton_clicked()
{
    edit_nume num;
    num.setModal(true);
    num.exec();
}


void Edit_Selector::on_pushButton_2_clicked()
{
    edit_numar numb;
    numb.setModal(true);
    numb.exec();
}

