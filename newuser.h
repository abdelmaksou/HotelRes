#ifndef NEWUSER_H
#define NEWUSER_H
#include "mainwindow.h"
#include "existinguser.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlTableModel>
#include <QVariant>

namespace Ui {
class newUser;
}

class newUser : public QDialog
{
    Q_OBJECT

public:
    explicit newUser(QWidget *parent = nullptr);
    ~newUser();
    QSqlDatabase db;
    bool checkDB(QSqlDatabase db);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newUser *ui;
};

#endif // NEWUSER_H
