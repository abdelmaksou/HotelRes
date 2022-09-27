#ifndef EXISTINGUSER_H
#define EXISTINGUSER_H

#include <QDialog>
#include "mainwindow.h"
#include "choice.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlTableModel>
#include <QVariant>


namespace Ui {
class existingUser;
}

class existingUser : public QDialog
{
    Q_OBJECT

public:
    static QString user;
    explicit existingUser(QWidget *parent = nullptr);
    ~existingUser();
    QSqlDatabase db;
    bool checkDB(QSqlDatabase db);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();


private:
    Ui::existingUser *ui;
};

#endif // EXISTINGUSER_H
