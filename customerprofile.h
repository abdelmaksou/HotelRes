#ifndef CUSTOMERPROFILE_H
#define CUSTOMERPROFILE_H

#include <QDialog>
#include "edituser.h"
#include "history.h"
namespace Ui {
class CustomerProfile;
}

class CustomerProfile : public QDialog
{
    Q_OBJECT

public:
     QSqlTableModel *model;
    explicit CustomerProfile(QWidget *parent = nullptr);
    ~CustomerProfile();
    bool checkDB(QSqlDatabase db);
    QString name, username, age, email, phone, password, country, passportNumber, points;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::CustomerProfile *ui;
};

#endif // CUSTOMERPROFILE_H
