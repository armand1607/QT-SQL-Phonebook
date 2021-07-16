#ifndef EDIT_NUME_H
#define EDIT_NUME_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class edit_nume;
}

class edit_nume : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db2;
    explicit edit_nume(QWidget *parent = nullptr);
    ~edit_nume();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::edit_nume *ui;
};

#endif // EDIT_NUME_H
