#ifndef EDIT_SELECTOR_H
#define EDIT_SELECTOR_H

#include <QDialog>

namespace Ui {
class Edit_Selector;
}

class Edit_Selector : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Selector(QWidget *parent = nullptr);
    ~Edit_Selector();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Edit_Selector *ui;
};

#endif // EDIT_SELECTOR_H
