#ifndef FLIGHTS_H
#define FLIGHTS_H


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlTableModel>
#include <QDialog>
#include "choice.h"
#include "targetflight.h"
namespace Ui {
class flights;
}

class flights : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel *model;
    explicit flights(QWidget *parent = nullptr);
    ~flights();
    bool sh=false;
    bool ch= false;
    QSqlDatabase db;
    bool checkDB(QSqlDatabase db);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_checkBox_2_clicked();

    void on_checkBox_clicked();

private:
    Ui::flights *ui;
};

#endif // FLIGHTS_H
