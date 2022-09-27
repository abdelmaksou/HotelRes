#ifndef HOTELS_H
#define HOTELS_H

#include <QDialog>
#include "choice.h"
#include "mainwindow.h"
#include "availablehotels.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlTableModel>
#include "availablehotels.h"
#include "reservation.h"
#include "cruise.h"
namespace Ui {
class Hotels;
}

class Hotels : public QDialog
{
    Q_OBJECT


public:
    static vector <AVAhotels*> hotels;

    explicit Hotels(QWidget *parent = nullptr);
    ~Hotels();

    QSqlTableModel *model;
    QSqlDatabase db;
    void ViewDetails();
    void searchCity(QString s);
    void searchHotel(QString s);
    void searchPriceRange(double s, double d);
    void searchStarRating(double s);
    bool createDB(QString dbname);


private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_treeView_clicked(const QModelIndex &index);


private:
    Ui::Hotels *ui;
};

#endif // HOTELS_H
