#ifndef EDIT_NUMAR_H
#define EDIT_NUMAR_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class edit_numar;
}

class edit_numar : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase db2;
    explicit edit_numar(QWidget *parent = nullptr);
    ~edit_numar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::edit_numar *ui;
};

#endif // EDIT_NUMAR_H
