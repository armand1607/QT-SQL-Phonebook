#ifndef LOGIN_H
#define LOGIN_H


#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextEdit>
#include <mainwindow.h>
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    MainWindow *mainWindow;
    QSqlDatabase myDb;

};

#endif // LOGIN_H
